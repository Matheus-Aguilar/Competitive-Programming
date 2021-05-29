#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;

#define fi first 
#define se second 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Lendo arquivo com a solução
ifstream solFile;

int D, I, S, V, F;

//Armazena dados do carro
struct Car{
	int id, pos; //id do carro, posição da rua que ele esta passando no array e bonus
	vector<int> ruas; //Ruas que o carro passa
};

//Armazena dados da rua
struct Rua{
	
	int id, l; //id e tamanho da rua
	int b, e; //Interseções de início e fim da rua
	string nome;

	/*Fila de carros esperando no fim da rua (first é o id e 
	second é o tempo que ele chega no fim da rua)*/
	queue<pii> fila; 
};

//Armazena dados da interseção
struct Inter{
	int id; //ID da interseção e luz acesa
	vector<int> ruas; //Ruas da interseção
};

//Armazena a solução
struct Sol{
	
	//Valor total da solucao
	ll valor;

	/*A posiçõa i contem um array de tempos das luzes
	
	Os tempos estão em array de pares, indicando a ordem as luzes
	First indica a posição da luz no array de ruas da interseção e
	second indica o tempo (second = 0 indica que aquela luz é sempre vermelha)*/

	//[1, 3, 2, 5]

	//[(2, 3), (1, 4), (0, 2), (3, 9)]

	vector<int> pos;
	vector<vector<pii>> tempos;
};

//Salva as mudancas de cor
struct Event{
	int t, inter; //Tempo e id do semáforo
	Event(int _t = 0, int _inter = 0) : t(_t), inter(_inter) {}
	bool operator<(const Event &e) const{
		if(t != e.t) return t < e.t;
		return inter < e.inter;
		//return pos < e.pos;
	}
	bool operator>(const Event &e) const{
		if(t != e.t) return t > e.t;
		return inter > e.inter;
		//return pos > e.pos;
	}
};

vector<Car> carros;
vector<Inter> inter;
vector<Rua> ruas;

//mapeia os nomes da ruas para seus ids
map<string, int> nomes;

//fila de eventos
priority_queue<Event, vector<Event>, greater<Event>> eventos;

//Solucao global
Sol solG;

void leitura(){
	cin >> D >> I >> S >> V >> F;

	inter.resize(I);
	ruas.resize(S);
	carros.resize(V);

	//Le as ruas
	for(int i = 0; i < S; i++){
		
		cin >> ruas[i].b >> ruas[i].e >> ruas[i].nome >> ruas[i].l;
		
		ruas[i].id = i;

		//Map dos nomes
		nomes[ruas[i].nome] = ruas[i].id;

		//Adiciona rua na intersecao
		inter[ruas[i].e].ruas.push_back(ruas[i].id);
	}

	//Le os carros
	for(int i = 0; i < V; i++){
		
		int N;
		string rua;
		cin >> N;

		carros[i].id = i;
		carros[i].pos = 0;

		for(int j = 0; j < N; j++){
			cin >> rua;
			carros[i].ruas.push_back(nomes[rua]);
		}
	}
}

void leituraSolucaoInicial(){
	
	int N;
	solFile >> N;

	solG.pos.resize(I);
	solG.tempos.resize(I);

	for(int i = 0; i < I; i++){
		
		solG.tempos[i].resize(inter[i].ruas.size());

		for(int j = 0; j < solG.tempos[i].size(); j++){
			solG.tempos[i][j] = pii(j, 0);
		}

	}

	for(int i = 0; i < N; i++){

		int in, nRuas;
		solFile >> in >> nRuas;

		vector<bool> visit(inter[i].ruas.size(), false);

		for(int j = 0; j < nRuas; j++){
			string nome;
			int t;

			solFile >> nome >> t;

			for(int k = 0; k < inter[in].ruas.size(); k++){
				if(inter[in].ruas[k] == nomes[nome]){
					solG.tempos[in][j].first = k;
					solG.tempos[in][j].second = t;
					visit[k] = true;
				}
			}
		}

		for(int j = 0, k = nRuas; j < inter[in].ruas.size(); j++){
			if(!visit[j]){
				solG.tempos[in][k].first = j;
				solG.tempos[in][k].second = 0;
				k++;
			}
		}
	}
}

ll fObj(Sol &sol){

	//Iniciar os valores
	sol.valor = 0;

	//Limpar as filas
	for(int i = 0; i < S; i++){
		while(!ruas[i].fila.empty()){
			ruas[i].fila.pop();
		}
	}

	//Coloca os carros no inicio
	for(int i = 0; i < V; i++){
		int rua = carros[i].ruas.front();
		carros[i].pos = 0;
		ruas[rua].fila.emplace(i, 0);
	}

	//Colocar as luzes iniciais
	for(int i = 0; i < I; i++){
		sol.pos[i] = 0;
		eventos.emplace(0, i);
	}

	// for(int i = 0; i < I; i++){
	// 	for(int j = 0; j < inter[i].ruas.size(); j++){
	// 		//cerr << "( " << sol.tempos[i][j].first << " , " << sol.tempos[i][j].second << " ) ";
	// 	}
	// 	//cerr << "\n";
	// }


	while(!eventos.empty() && eventos.top().t <= D){

		int t = eventos.top().t;

		int in = eventos.top().inter;
		int posSol = sol.pos[in];
		int pos = sol.tempos[in][posSol].first;
		
		eventos.pop();

		int rua = inter[in].ruas[pos];
		
		int tempoLuz = sol.tempos[in][posSol].second;
		int cont = 0;

		//cerr << "Acende " << ruas[rua].nome << " " << "T: " << t << "\n";

		while(!ruas[rua].fila.empty() && cont < tempoLuz){

			int car = ruas[rua].fila.front().first;
			int tempo = ruas[rua].fila.front().second;

			if(tempo > t)
				break;
		
			//Tiro da fila
			ruas[rua].fila.pop();
			
			//Incrementa a posicao
			carros[car].pos++;

			int novaRua = carros[car].ruas[carros[car].pos];

			//Move o carro
			if(carros[car].pos < carros[car].ruas.size() - 1){
				if(t + ruas[novaRua].l <= D){

					//cerr << "Move " << car << " para " << ruas[novaRua].nome << " T: " << t + ruas[novaRua].l << "\n";

					ruas[novaRua].fila.emplace(car, t + ruas[novaRua].l);
				}
			}
			else{
				//Encerrou o percurso
				if(t + ruas[novaRua].l <= D){
				
					//cerr << car << " encerra " << " T: " << t + ruas[novaRua].l << "\n";
				
					sol.valor += F + (D - (t + ruas[novaRua].l));
				}
			}

			//incrementar o cont
			cont++;
		}

		posSol = (posSol + 1) % sol.tempos[in].size();

		if(tempoLuz == 0 && sol.tempos[in].size() - 1 == posSol && t == 0) continue;

		sol.pos[in] = pos;
		eventos.emplace(t + tempoLuz, in);
	}

	while(!eventos.empty()) 
		eventos.pop();

	return sol.valor;
}

void print(Sol &sol){
	
	int N = 0;
	
	//Contar quantas inter nao sao tudo vermelho
	for(int i = 0; i < I; i++){
		for(int j = 0; j < sol.tempos[i].size(); j++){
			if(sol.tempos[i][j].second > 0){
				N++;
				break;
			}
		}
	}

	cout << N << "\n";

	for(int i = 0; i < I; i++){

		int M = 0;

		for(int j = 0; j < sol.tempos[i].size(); j++){
			if(sol.tempos[i][j].second > 0){
				M++;
			}
		}

		if(M == 0) continue;

		cout << i << "\n";
		cout << M << "\n";

		for(int j = 0; j < sol.tempos[i].size(); j++){
			if(sol.tempos[i][j].second > 0){
				
				int pos = sol.tempos[i][j].first;
				int t = sol.tempos[i][j].second;

				int rua = inter[i].ruas[pos];

				cout << ruas[rua].nome << " " << t << "\n";
			}
		}
	}
}

bool vizAdd(Sol &sol){
	ll old = fObj(sol);

	int in = rng() % I;
	int i = rng() % sol.tempos[in].size();
	int val = -5 + rng() % 11;

	if(val + sol.tempos[in][i].second <= 0)
		val = -sol.tempos[in][i].second + 1;

	sol.tempos[in][i].second += val;


	ll novo = fObj(sol);

	cerr << novo << " " << old << endl;

	if(novo <= old){
		sol.tempos[in][i].second -= val;
		return false;	
	}

	return true;
}

bool vizTroca(Sol &sol){

	ll old = fObj(sol);

	int in = rng() % I;
	int i = rng() % sol.tempos[in].size();
	int j = rng() % sol.tempos[in].size();

	swap(sol.tempos[in][i], sol.tempos[in][j]);

	ll novo = fObj(sol);

	cerr << novo << " " << old << endl;

	if(novo <= old){
		swap(sol.tempos[in][i], sol.tempos[in][j]);
		return false;	
	}

	return true;
}

void VND(Sol &sol){
	
	for(int v = 0; v <= 1; v++){
		for(int i = 0; i < 100; i++){
			if(v == 0){
				if(vizTroca(sol)){
					v = i = 0;
				}
			}
			else if(i == 1){
				if(vizAdd(sol)){
					v = i = 0;
				}
			}
		}
	}

}

int main(int argc, char *argv[]){

	leitura();

	if(argc > 1){
		solFile.open(argv[1]);
		leituraSolucaoInicial();
	}

	solG.tempos.resize(I);
	solG.pos.resize(I);

	for(int i = 0; i < I; i++){
		solG.tempos[i].resize(inter[i].ruas.size());
		
		for(int j = 0; j < solG.tempos[i].size(); j++){
			solG.tempos[i][j].first = j;
			solG.tempos[i][j].second = 1;
		}
	}

	cerr << "Leu tudo\n";
	cerr << fObj(solG) << endl;

	VND(solG);
	print(solG);
	cerr << fObj(solG) << "\n";

    return 0;
}
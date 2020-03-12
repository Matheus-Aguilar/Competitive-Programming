#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll _tam_crivo;
bitset<10000010> bs;
vector<int> primos;
vector<int> pos(3501, -1);

void crivo(ll limite) { // cria lista de primos em [0..limite]
    _tam_crivo = limite + 1; // + 1 para incluir limite
    bs.reset(); bs.flip(); // todos valendo true
    bs.set(0, false); bs.set(1,false); // exceto indices 0 e 1
    for (ll i = 2; i <= _tam_crivo; i++){
        if (bs.test((size_t)i)) {
            //corta todos os multiplos de i comecando de i*i
            for (ll j = i*i; j <= _tam_crivo; j += i)
                bs.set((size_t)j, false);
            primos.push_back((int)i); // adiciona na lista de primos
        }
    }
}

int calcula(int n, int i){
    if(n == 1) return 1;
    return (calcula(n - 1, i + 1) + primos[i] - 1) % n + 1;
}

int calcula(int n){
    if(pos[n - 1] != -1) return pos[n - 1];
    pos[n - 1] = calcula(n, 0);
    return pos[n - 1];
}

int main(){
    crivo(32650);
    while(true){
        int n;
        scanf("%d", &n);
        if(!n) break;
        printf("%d\n", calcula(n));
    }
}
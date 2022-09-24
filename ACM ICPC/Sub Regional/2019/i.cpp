#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 100000000
#define pii pair<int, int>

using namespace std;

int J1, J2;
pii query1[100000];
pii query2[100000];
int adj[400][400][2];
int cold[400];
int hot[400];
int cold2[400];
int hot2[400];
int ans[100000];
pii temp[400];
int aux[400];
int auxN;

int mapa(int i, int mode){
    if(!mode) return cold[i];
    return hot[i];
}

int mapa2(int i, int mode){
    if(!mode) return cold2[i];
    return hot2[i];
}

void floyd(int n, int mode){

    int q = 0;

    for(int k = 0; k < n; k++){
        int K = mapa(k, mode);
        for(int i = 0; i < n; i++){
            int I = mapa(i, mode);
            for(int j = 0; j < n; j++){
                int J = mapa(j, mode);
                adj[I][J][mode] = min(adj[I][J][mode], adj[I][K][mode] + adj[K][J][mode]); 
            
                int key = n * n * 2 * k + n * 2 * i + j * 2 + mode;

                if(!mode){
                    while(q < J1 && key == query1[q].first){
                        ans[query1[q].second] = adj[I][J][mode]; 
                        q++;
                    }
                }
                else{
                    while(q < J2 && key == query2[q].first){
                        ans[query2[q].second] = adj[I][J][mode]; 
                        q++;
                    }
                }
            }
        }
    }
}

void preCalc(int n){
    sort(aux, aux + n);
    auxN = unique(aux, aux + n) - aux;
    sort(temp, temp + n);
    for(int i = 0; i < n; i++){ 
        cold[i] = hot[n - i - 1] = temp[i].second;
        cold2[temp[i].second] = i;
        hot2[temp[i].second] = n - i - 1;
    }
}

int upperBound(int start, int end, int x){
    while(start < end){
        int middle = start + (end - start)/2;
        if(temp[middle].first <= x)
            start = middle + 1;
        else
            end = middle;
    }
    return start - 1;
}

int lowerBound(int start, int end, int x){
    while(start < end){
        int middle = start + (end - start)/2;
        if(temp[middle].first < x)
            start = middle + 1;
        else
            end = middle;
    }
    return start;
}

int main(){
    optimize;
    
    int n, r;
    cin >> n >> r;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adj[i][j][0] = adj[i][j][1] = INF; 
        }
    }

    for(int i = 0; i < n; i++){
        cin >> aux[i];
        temp[i] = pii(aux[i], i);
    }

    while(r--){
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a][b][0] = adj[a][b][1] = adj[b][a][0] = adj[b][a][1] = c;
    }

    int q;
    cin >> q;

    preCalc(n);

    for(int i = 0; i < q; i++){
    
        int a, b, k, t;
        cin >> a >> b >> k >> t;
        --a, --b, --k;

        if(!t){
            int val = aux[(k >= auxN ? auxN - 1 : k)];
            k = upperBound(0, n, val);
            int I = mapa2(a, 0);
            int J = mapa2(b, 0);
            query1[J1++] = pii(n * n * 2 * k + n * 2 * I + J * 2 + t, i);
        }
        else{
            int val = aux[(k >= auxN ? 0 : auxN - k - 1)];
            k = n - lowerBound(0, n, val) - 1;
            int I = mapa2(a, 1);
            int J = mapa2(b, 1);
            query2[J2++] = pii(n * n * 2 * k + n * 2 * I + J * 2 + t, i);
        }
    }

    sort(query1, query1 + J1);
    sort(query2, query2 + J2);


    floyd(n, 0);
    floyd(n, 1);

    for(int i = 0; i < q; i++){
        cout << (ans[i] != INF ? ans[i] : -1) << "\n";
    }

    return 0;
}

#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 30300

using namespace std;

const int block = 128;

struct Query{
    int l, r, i;

    bool operator<(const Query &qry) const{
        if(l / block != qry.l / block)
            return l / block < qry.l / block;
        return (((l / block) & 1) ? r < qry.r : r > qry.r);
    }
};

int n, q, m, t[MAXN], uni[MAXN], comp[MAXN], ans[MAXN];
Query query[MAXN];

int cont[MAXN]; //cont[i] = quantos elementos do tipo t[i] temos
int sum[MAXN]; //sum[i] = quantos elementos tem i ou mais ocorrencias 
int maxSum; //maxSum = maior i, tal que sum[i] >= i

int gl = 0;

void init(){
    //ms(cont, 0);
    sum[0] = m;
    maxSum = 0;
}

void add(int i){
    cont[comp[i]]++;
    sum[cont[comp[i]]]++;
    if(sum[cont[comp[i]]] >= cont[comp[i]])
        maxSum = max(maxSum, cont[comp[i]]);
}

void rem(int i){
    if(sum[cont[comp[i]]] == cont[comp[i]] && sum[cont[comp[i]]] == maxSum)
        maxSum--;
    sum[cont[comp[i]]]--;
    cont[comp[i]]--;
}

int get(){
    return maxSum;
}

void Mo(){ 

    init();

    sort(query, query + q);
    
    for(int i = 0, l = 0, r = -1; i < q; i++){

        while(r < query[i].r) add(++r);
        while(l > query[i].l) add(--l);
        while(r > query[i].r) rem(r--);
        while(l < query[i].l) rem(l++);

        ans[query[i].i] = get();
    }
}

int main(){
    optimize;

    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> t[i];
        uni[i] = t[i];
    }

    /*Compressao de coordenadas*/
    sort(uni, uni + n);
    m = unique(uni, uni + n) - uni;

    for(int i = 0; i < n; i++)
        comp[i] = lower_bound(uni, uni + m, t[i]) - uni;
    
    for(int i = 0; i < q; i++){
        
        cin >> query[i].l >> query[i].r;

        query[i].l--;
        query[i].r--;
        query[i].i = i;
    }

    Mo();

    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";

    return 0;   
}

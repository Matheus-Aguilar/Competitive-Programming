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

using namespace std;

bool magic(vector<int> &a){
    
    int k = 0, c = 0;

    //Diagonal principal
    for(int i = 0; i < 3; i++)
        k += a[3 * i + i];
    
    //Diagonal secundaria
    for(int i = 0; i < 3; i++)
        c += a[3 * i + (2 - i)];

    if(k != c) return false;

    //Linhas
    for(int i = 0; i < 3; i++){

        c = 0;

        for(int j = 0; j < 3; j++)
            c += a[3 * i + j];

        if(k != c) return false;
    }

    //Colunas
    for(int i = 0; i < 3; i++){

        c = 0;

        for(int j = 0; j < 3; j++)
            c += a[3 * j + i];

        if(k != c) return false;
    }

    return true;
}

int diff(vector<int> &a, vector<int> &b){
    
    int sum = 0;

    for(int i = 0; i < 9; i++)
        sum += abs(a[i] - b[i]);
    
    return sum;
}

int main(){

    optimize;

    int best = INF;

    vector<int> a(9);
    vector<int> p(9);
    
    iota(all(p), 1);

    for(int i = 0; i < 9; i++)
        cin >> a[i];

    do{
        if(magic(p))
            best = min(best, diff(a, p));
    } while(next_permutation(all(p)));

    cout << best << "\n";

    return 0;   
}

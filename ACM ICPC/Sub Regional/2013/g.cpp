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

int minSwaps(vector<int> &a){
    int swaps = 0;
    vector<bool> v(a.size(), false);
    for(int i = 0; i < a.size(); i++){
        if(v[i]) continue;
        
        int cycle = 0, j = i;
        while(!v[j]){
            v[j] = true;
            j = a[j];
            cycle++;
        }
        swaps += cycle - 1;
    }
    return swaps;
}

int main(){
    optimize;

    int l, c;
    while(cin >> l >> c){
        vector<vector<int>> x(l, vector<int>(c));
        for(int i = 0; i < l; i++)
            for(int j = 0; j < c; j++)
                cin >> x[i][j];
        
        vector<int> rows(l);
        vector<int> cols(c);
        
        bool possible = true;

        for(int i = 0; i < l && possible; i++){
            vector<int> aux = x[i];
            sort(all(aux));
            if((aux[0] - 1) % c != 0){ 
                possible = false;
            }
            else{
                rows[i] = (aux[0] - 1) / c;
                for(int i = 1; i < c && possible; i++){
                    if(aux[i - 1] + 1 != aux[i]){
                        possible = false;
                    }
                }
            }
        }

        for(int j = 0; j < c && possible; j++){
            cols[j] = (x[0][j] - 1) % c;
            for(int i = 1; i < l && possible; i++){
                if((x[i][j] - 1) % c != cols[j]){
                    possible = false;
                }
            }
        }

        if(!possible){
            cout << "*" << "\n";
        }
        else{
            cout << minSwaps(rows) + minSwaps(cols) << "\n";
        }
    }
    return 0;   
}

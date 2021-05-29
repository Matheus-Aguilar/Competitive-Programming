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

bool cmp(vector<int> &a, vector<int> &b){
    for(int i = 9; i >= 0; i--)
        if(a[i] != b[i])
            return a[i] < b[i];
    return true;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        vector<int> cont(10, 0);
        vector<int> best(10, -1);
        int last = -1;
        vector<int> aux(10, 0);

        for(int i = 0; i <= 9; i++){
            int d;
            cin >> d;
            cont[i] += d;
        }

        if(accumulate(all(cont), 0) == 1){
            if(cont[8])
                cout << 8 << "\n";
            else if(cont[4])
                cout << 4 << "\n";
            else if(cont[0])
                cout << 0 << "\n";
            else
                cout << -1 << "\n";
            continue;
        }

        for(int i = 0; i < 100; i += 4){
            if(i % 10 == (i/10) % 10 && cont[i % 10] >= 2){
                aux = cont;
                aux[i % 10] -= 2;
            }
            else if(i % 10 != (i/10) % 10 && cont[i % 10] >= 1 && cont[(i/10) % 10] >= 1){
                aux = cont;
                aux[i % 10] -= 1;
                aux[(i/10) % 10] -= 1;
            }
            else{
                continue;
            }

            if(cmp(best, aux)){
                last = i;
                best = aux;
            }
        }

        if(*max_element(best.begin() + 1, best.end()) <= 0){
            if(last != -1)
                cout << last << "\n";
            else if(cont[8])
                cout << 8 << "\n";
            else if(cont[4])
                cout << 4 << "\n";
            else if(cont[0])
                cout << 0 << "\n";
            else
                cout << -1 << "\n";
        }
        else{
            for(int i = 9; i >= 0; i--){
                while(best[i]--)
                    cout << i;
            }
            if(last < 10) cout << 0;
            cout << last << "\n";
        }
    }

    
    return 0;   
}

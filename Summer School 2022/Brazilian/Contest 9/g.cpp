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

int main(){
    optimize;

    ifstream in("topo.in");

    int t;
    in >> t;

    while(t--){

        int n;
        in >> n;

        vector<int> a(n), b(n), c(n, 0);

        for(int i = 0; i < n; i++)
            in >> a[i];
        for(int i = 0; i < n; i++)
            in >> b[i];

        vector<pii> v1;
        vector<int> v2;

        bool ok = true;

        for(int i = 0; i < n; i++){
            
            c[i] = a[i] - b[i];
            
            if(b[i] == 0)
                v1.emplace_back(c[i], i);
            else
                v2.push_back(i);

            ok &= (a[i] >= b[i]);
        }

        sort(all(v1));

        vector<pii> e;

        for(int i = 0; i < n && ok; i++){
            if(b[i] != 0){

                int cont = 0;

                for(int j = 0; j < v1.size() && ok; j++){
                    
                    if(cont == c[i])
                        break;

                    e.emplace_back(v1[j].second, i);
                    cont++;
                }

                ok &= (cont == c[i]);
                cont = 0;

                for(int j = 0; j < v2.size() && ok; j++){
                    if(cont == b[i])
                        break;

                    if(i == v2[j])
                        continue;

                    e.emplace_back(v2[j], i);
                    cont++;

                }

                ok &= (cont == b[i]);
            }
            else {
                
                int cont = 0;

                for(int j = 0; j < v1.size() && v1[j].first < c[i] && ok; j++){
                    if(cont == c[i])
                        break;

                    e.emplace_back(v1[j].second, i);
                    cont++;
                }

                ok &= (cont == c[i]);
            }
        }

        if(!ok){
            cout << -1 << "\n";
        }
        else{
            cout << e.size() << "\n";

            for(int i = 0; i < e.size(); i++){
                cout << e[i].first + 1 << " " << e[i].second + 1 << "\n";
            }
        }
    }
    
    return 0;   
}

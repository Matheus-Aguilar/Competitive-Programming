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

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> t(n);
        vector<int> c(n, 0);
        for(int i = 0; i < n; i++) cin >> t[i];
        bool equal = true;
        int e = -1;
        for(int i = 0; i < n - 1; i++){
            if(t[i] != t[i + 1]){
                equal = false;
            }
            else{
                if(e == -1){
                    e = i;
                }
            }
        }

        if(t[n - 1] == t[0])
            e = n - 1;

        if(equal){
            cout << 1 << "\n";
            for(int i = 0; i < n; i++)
                cout << 1 << " ";
            cout << "\n";
            continue;
        }
        else{
            if(n % 2 == 0){
                cout << 2 << "\n";
                for(int i = 0; i < n; i++)
                    cout << (i % 2 ? 1 : 2) << " ";
                cout << "\n";
                continue;
            }
            else{
                if(e != -1){
                    cout << 2 << "\n";
                    bool value = true;
                    for(int i = e + 1; i < n; i++){
                        c[i] = (value ? 1 : 2);
                        value = !value;
                    }
                    for(int i = 0; i <= e; i++){
                        c[i] = (value ? 1 : 2);
                        value = !value;
                    }
                    for(int i = 0; i < n; i++)
                        cout << c[i] << " ";
                    cout << "\n";
                }
                else{
                    cout << 3 << "\n";
                    for(int i = 0; i < n - 1; i++)
                        cout << (i % 2 ? 1 : 2) << " ";
                    cout << 3 << "\n";
                }
            }
        }
    }
    
    return 0;   
}

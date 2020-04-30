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

    int primos[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    int t;
    cin >> t;
    while(t--){
        int cores[11];
        ms(cores, 0);

        int n;
        cin >> n;
        vector<int> c(n);

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            for(int j = 0; j < 11; j++){
                if(x % primos[j] == 0){
                    c[i] = j + 1;
                    cores[j]++;
                    break;
                }
            }
        }

        int m = 0;

        for(int i = 0; i < 11; i++){
            if(cores[i]){
                m++;
                for(int j = 0; j < n; j++){
                    if(c[j] == i + 1)
                        c[j] = m;
                }
            }
        }
        cout << m << "\n";

        for(int i:c) cout << i << " ";
        cout << "\n";
    }

    return 0;   
}

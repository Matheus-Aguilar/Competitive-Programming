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

    int t;
    cin >> t;

    while(t--){

        int n, cont = 1;

        cin >> n;

        vector<char> v(n);
        vector<int> ans(n);

        for(int i = 0; i < n; i++)
            cin >> v[i];

        for(int i = 0; i < n; i++){
            if(v[i] == 'D'){

                ans[i] = cont++;
                v[i] = 'X';

                for(int j = i - 1; j >= 0 && v[j] != 'X'; j--){
                    ans[j] = cont++;
                    v[j] = 'X';
                }

                if(i < n - 1 && v[i + 1] != 'X')
                    v[i + 1] = (v[i + 1] == 'D' ? 'B' : 'D');
            }
        }

        if(cont == n + 1){
            cout << "Y" << "\n";

            for(int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i==n-1];
        }
        else{
            cout << "N" << "\n";
        }
    }
    
    return 0;   
}

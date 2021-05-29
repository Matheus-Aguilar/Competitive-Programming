#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

void myReverse(char s[], int a, int b){
    for(int i = a; i < (a + b)/2; i++){
        char c = s[i];
        s[i] = s[a + b - i];
        s[a + b - i] = s[i];
    }
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        string s;
        cin >> s;

        set<pair<string, int>> st;

        for(int k = 1; k <= n; k++){
            string aux = "";
            for(int i = k; i <= n; i++){
                aux += s[i - 1];
            }

            if((n - k) & 1){
                for(int i = 0; i < k - 1; i++){
                    aux += s[i];
                }
            }
            else{
                for(int i = k - 2; i >= 0; i--){
                    aux += s[i];
                }
            }

            st.insert(make_pair(aux, k));
        }

        auto ans = *st.begin();
        cout << ans.first << "\n" << ans.second << "\n";
    }
    
    return 0;   
}

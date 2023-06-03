#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool all = true;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                all = false;
                break;
            }
        }

        if(all){
            cout << 0 << "\n";
            continue;
        }

        int par = 0, cnt[2] = {1, 0};
        long long ans = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                par = !par;            
            ans += cnt[!par];
            cnt[par]++;
        }

        int last = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(last == -1)
                    ans -= i;
                else
                    ans -= 2 * (i - last - 1);
                last = i;
            }
        }

        ans -= n - last - 1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                ans--;
        }

        cout << ans << "\n";
    }


    return 0;
}
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

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        
        int N;
        cin >> N;

        vector<string> a(N);

        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
    
        int ans = 0;

        for(int i = 1; i < N; i++){
        
            if(a[i].size() > a[i - 1].size()){
                continue;
            }

            string sub = a[i - 1].substr(0, a[i].size());
        
            if(sub < a[i]){
                while(a[i].size() < a[i - 1].size()){
                    a[i] += "0";
                    ans++;
                }
            }
            else if(sub > a[i]){
                while(a[i].size() <= a[i - 1].size()){
                    a[i] += "0";
                    ans++;
                }
            
            }
            else if(a[i] == a[i - 1]){
                a[i] += "0";
                ans++;
            }
            else{
                string sub2 = a[i - 1].substr(a[i].size(), a[i - 1].size() - a[i].size());
                string sub3 = sub2;

                for(int j = sub3.size() - 1; j >= 0; j--){
                    if(sub3[j] < '9'){
                        sub3[j]++;
                        break;
                    }
                    else{
                        sub3[j] = '0';
                        if(j == 0) sub3 = "1" + sub3;
                    }
                }
                if(sub3.size() > sub2.size()){
                    while(a[i].size() <= a[i - 1].size()){
                        a[i] += "0";
                        ans++;
                    }
                }
                else{
                    ans += sub3.size();
                    a[i] += sub3;
                }
            }
        }
    
        cout << "Case #" << t << ": " << ans << "\n";
    }
    
    return 0;   
}

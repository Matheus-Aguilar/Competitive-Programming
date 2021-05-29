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

void fix(pii &ans){
    int g = __gcd(ans.first, ans.second);
    ans.first /= g;
    ans.second /= g;
}

int lcm(int a, int b){
    return (a * b) / __gcd(a, b);
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        int n, q;
        cin >> n >> q;

        assert(n < 3);

        vector<string> s(n);
        vector<int> v(n);

        for(int i = 0; i < n; i++)
            cin >> s[i] >> v[i];
        
        pii ans = make_pair(0, 1);
        string st = "";

        for(int i = 0; i < q; i++){
            if(n == 1){    
                pii prob;

                if(s[0][i] == 'T')
                    prob = make_pair(v[0], q);
                else
                    prob = make_pair(q - v[0], q);

                fix(prob);

                if(2 * prob.first >= prob.second){
                    st += "T";
                }
                else{
                    prob.first = prob.second - prob.first;
                    st += "F";
                }

                int l = lcm(ans.second, prob.second);

                ans.first = ans.first * l / ans.second + prob.first * l / prob.second;
                ans.second = l;

                fix(ans);
            }
            else{    
                pii prob;

                if(s[0][i] == 'T')
                    prob = make_pair(v[0], q);
                else
                    prob = make_pair(q - v[0], q);
                
                fix(prob);

                if(s[1][i] == 'T'){
                    prob.first *= v[1];
                    prob.second *= q;
                }
                else{
                    prob.first *= q - v[1];
                    prob.second *= q;
                }

                fix(prob);

                if(2 * prob.first >= prob.second){
                    st += "T";
                }
                else{
                    prob.first = prob.second - prob.first;
                    st += "F";
                }

                cout << prob.first << " " << prob.second << "\n";

                int l = lcm(ans.second, prob.second);

                ans.first = ans.first * l / ans.second + prob.first * l / prob.second;
                ans.second = l;

                fix(ans);
            }
        }

        cout << "Case #" << t << ": " << st << " " << ans.first << "/" << ans.second << "\n";
    }
    
    
    return 0;   
}

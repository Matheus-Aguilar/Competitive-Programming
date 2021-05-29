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

const int K = 1000;
const double EPS = 1e-9;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
std::uniform_real_distribution<double> rng(0.0 + EPS, 1.0 - EPS);

int main(){
    optimize;

    int n;

    while(cin >> n && n){
        
        vector<string> s(n);
        vector<double> st;

        for(int i = 0; i < n; i++)
            cin >> s[i];
        
        bool ok = true;

        for(int k = 0; k < K && ok; k++){
        
            double val = PI * rng(gen) / 2.0;
            ok = true;
        
            for(int i = 0; i < n; i++){
                if(s[i] == "x"){
                    st.push_back(val);
                }
                else if(s[i] == "sin"){
                    double x = st.back();
                    st.pop_back();
                    st.push_back(sin(x));
                }
                else if(s[i] == "cos"){
                    double x = st.back();
                    st.pop_back();
                    st.push_back(cos(x));
                }
                else if(s[i] == "tan"){
                    double x = st.back();
                    st.pop_back();
                    st.push_back(tan(x));
                }
                else if(s[i] == "+"){
                    double x1 = st.back();
                    st.pop_back();
                    double x2 = st.back();
                    st.pop_back();
                    st.push_back(x1 + x2);
                }
                else if(s[i] == "-"){
                    double x1 = st.back();
                    st.pop_back();
                    double x2 = st.back();
                    st.pop_back();
                    st.push_back(x2 - x1);
                }
                else if(s[i] == "*"){
                    double x1 = st.back();
                    st.pop_back();
                    double x2 = st.back();
                    st.pop_back();
                    st.push_back(x1 * x2);
                }
            }

            if(abs(st.back()) > EPS)
                ok = false;
        }

        cout << (ok ? "Identity" : "Not an identity") << "\n";
    }
    
    return 0;   
}

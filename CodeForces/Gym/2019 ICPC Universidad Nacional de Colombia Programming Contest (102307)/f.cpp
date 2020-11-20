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

ll MDC(ll a, ll b)  { return b ? MDC(b,a%b) : a; }
ll MMC(ll a,ll b)  { return a*(b/MDC(a,b)); }
 
struct Rac{
	ll p,q;
 
	Rac(ll _p = 0LL , ll _q = 1LL) : p{_p}, q{_q} {
		ll m = MDC(abs(p),abs(q));
 
		p /= m;
		q /= m;
	}
 
	bool operator<(const Rac &a) const{
		ll m = MMC(abs(q),abs(a.q));
 
		ll u = (m/q) * p;
		ll v = (m/a.q) * a.p;
 
		if(u < v) return true;
		else return false;
	}
	Rac operator+(Rac &a){
		ll m = MMC(abs(q),abs(a.q));
 
		p = (m/q)*p;
		a.p = (m/a.q)*a.p;
 
		return Rac(p+a.p, m);
	}
	Rac operator-(Rac &a){
		ll m = MMC(abs(q),abs(a.q));
 
		p = (m/q)*p;
		a.p = (m/a.q)*a.p;
 
		return Rac(p-a.p, m);
	}
	Rac operator*(Rac &a){ return Rac(p*a.p, q*a.q); }
	Rac operator/(Rac &a){ return Rac(p*a.q, q*a.p); }
};

Rac stor(string &num){
    
    int i = 0;
    string n1 = "", n2 = "";
            
    while((num[i] >= '0' && num[i] <= '9') || num[i] == '-')
        n1 += num[i++];
    
    i++;

    while(i < num.size())
        n2 += num[i++];

    return Rac(stoll(n1), stoll(n2));
}

string rtos(Rac num){
    return to_string(num.p) + '/' + to_string(num.q);
}

void solve(string &s){
    
    int i = 0, last = -1;
    vector<string> st;

    while(i < s.size()){

        if(s[i] == '('){
            st.push_back("(");
        }
        else if(s[i] == ')'){

            string n2 = st.back();
            st.pop_back();
            
            if(st.back() == "("){
                st.pop_back();
                st.push_back(n2);
                i++;
                continue;
            }

            string op = st.back();
            st.pop_back();
            
            string n1 = st.back();
            st.pop_back();

            Rac r1 = stor(n1), r2 = stor(n2);

            st.pop_back();

            if(op[0] == '+')
                st.push_back(rtos(r1 + r2));
            else
                st.push_back(rtos(r1 - r2));
        }
        else if(s[i] == '+'){
            st.push_back("+");
        }
        else if(s[i] == '-'){
            st.push_back("-"); 
        }
        else{
            string aux = "";
            
            while((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
                aux += s[i++];
            
            aux += '/';
            ++i;
            
            while(i < s.size() && (s[i] >= '0' && s[i] <= '9'))
                aux += s[i++];

            --i;

            st.push_back(aux);
        }

        ++i;
    }

    string ans = st.back();
    st.pop_back();

    if(!st.empty()){
        
        string op = st.back();
        st.pop_back();
        string num = st.back();
        st.pop_back();

        Rac r1 = stor(num), r2 = stor(ans);

        if(op[0] == '+')
            st.push_back(rtos(r1 + r2));
        else
            st.push_back(rtos(r1 - r2));
    
        ans = st.back();
        st.pop_back();
    }

    ans = rtos(stor(ans));

    cout << ans << "\n";
}

int main(){
    optimize;

    string s;

    while(cin >> s)
        solve(s);
    
    return 0;   
}

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        string s = "";
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++){
            if(a[i] < k)
                s += '0';
            else if(a[i] == k)
                s += '1';
            else
                s += '2';
        }

        bool ans = (s.find("11") != string::npos) || (s.find("12") != string::npos) || (s.find("21") != string::npos)
        || (s.find("22") != string::npos) || (s.find("101") != string::npos) || (s.find("102") != string::npos) 
        || (s.find("201") != string::npos) || (s.find("202") != string::npos); 
    
        ans &= (s.find("1") != string::npos);
        ans |= (s.size() == 1 && s[0] == '1');

        cout << (ans ? "yes" : "no") << "\n";
    }
    
    return 0;   
}

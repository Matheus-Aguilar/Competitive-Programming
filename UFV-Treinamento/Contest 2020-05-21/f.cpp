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
    
    string s1, s2;
    cin >> s1 >> s2;

    if(s1.size() != s2.size())
        cout << "NO" << "\n";
    else{
        if(s1 == s2)
            cout << "YES" << "\n";
        else if(s2.find("1") == string::npos)
            cout << "NO" << "\n";
        else if(s1.find("1") == string::npos)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
    return 0;   
}

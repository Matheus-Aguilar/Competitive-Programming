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

const char d[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

bool palindrome(const string &s){
    for(int i = 0, j = s.size() - 1; i < j; i++, j--)
        if(s[i] != s[j])
            return false;
    return true;
}

string convert(int n, int b){
    string s = "";

    while(n > 0){
        s += d[n % b];
        n /= b;
    }

    if(s.size() == 0)
        s += "0";

    reverse(all(s));

    return s;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        
        int n;
        bool empty = true;

        cin >> n;

        for(int i = 2; i <= 16; i++){
            if(palindrome(convert(n, i))){
                cout << i << " ";
                empty = false;
            }
        }
        
        if(empty)
            cout << -1;

        cout << "\n";
    }
    
    return 0;   
}

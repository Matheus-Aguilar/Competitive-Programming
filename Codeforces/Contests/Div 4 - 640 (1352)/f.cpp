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
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string s = "";
        for(int i = 0; i < n1; i++){
            if(i % 2)
                s += '1';
            else
                s += '0';
        }

        if(s.empty()){
            if(n0)
                for(int i = 0; i < n0 + 1; i++)
                    s += '0';
            if(n2)
                for(int i = 0; i < n2 + 1; i++)
                    s += '1';
        }
        else if(s.back() == '1'){
            for(int i = 0; i < n2; i++)
                s += '1';
            for(int i = 0; i < n0 + 1; i++)
                s += '0';
        }
        else{
            for(int i = 0; i < n0; i++)
                s += '0';
            for(int i = 0; i < n2 + 1; i++)
                s += '1';
        }

        cout << s << "\n";
    }
    
    return 0;   
}

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

    ifstream in("hamming.in");

    int t;  
    in >> t;

    while(t--){
        
        int n, z1 = 0, z2 = 0, o1 = 0, o2 = 0;
        string s1, s2;
        
        in >> n >> s1 >> s2;

        for(int i = 0; i < n; i++){
            if(s1[i] == '0')
                z1++;
            else
                o1++;
        }

        for(int i = 0; i < n; i++){
            if(s2[i] == '0')
                z2++;
            else
                o2++;
        }

        cout << min(z1, o2) + min(z2, o1) << "\n";
    }
    
    return 0;   
}

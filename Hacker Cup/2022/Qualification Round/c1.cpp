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

        int n;
        cin >> n;

        vector<string> words(n);

        cin >> words[0];

        char c = (words[0][0] == '.' ? '-' : '.');

        for(int i = 1; i < n; i++)
            words[i] = c + words[i - 1];

        cout << "Case #" << t << ": " << "\n";

        for(int i = 1; i < n; i++){
            cout << words[i] << "\n";
        }
    }

    return 0;   
}

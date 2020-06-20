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
        string s;
        cin >> s;

        vector<int> del;

        for(int i = 0, j = 1, k = 2, l = 3, m = 4; m < s.size(); i++, j++, k++, l++, m++){
            if(s[i] == 't' && s[j] == 'w' && s[k] == 'o' && s[l] == 'n' && s[m] == 'e'){
                del.push_back(k + 1);
                s[k] = 'x';
            }
        }

        for(int i = 0, j = 1, k = 2; k < s.size(); i++, j++, k++){
            if((s[i] == 'o' && s[j] == 'n' && s[k] == 'e') || (s[i] == 't' && s[j] == 'w' && s[k] == 'o'))
                del.push_back(j + 1);
        }

        cout << del.size() << "\n";
        for(int i = 0; i < del.size(); i++)
            cout << del[i] << " ";
        cout << "\n";
    }
    
    return 0;   
}

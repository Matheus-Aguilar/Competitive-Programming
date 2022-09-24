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
    
    int k, l;
    cin >> k >> l;

    int level = 4;
    bool ended = false;

    vector<int> a((1 << 4), false);
    a[k - 1] = a[l - 1] = true;

    string name[level] = {"final", "semifinal", "quartas", "oitavas"}; 

    while(!ended){
        for(int i = 0; i < (1 << level) && !ended; i += 2){
            if(a[i] && a[i + 1]){
                cout << name[level - 1] << "\n";
                ended = true;
            }
            a[i/2] = a[i] | a[i + 1];
        }
        level--;
    }

    return 0;   
}

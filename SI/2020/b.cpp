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
    

    int cont = 1, i = 0;
    char a, b, voip[4] = {'V', 'O', 'I', 'P'};
    cin >> a >> b;

    while(voip[i] != a){
        i++;
        i %= 4;
    }

    i++;
    i %= 4;

    while(voip[i] != b){
        cont++;
        i++;
        i %= 4;
    }

    cout << cont << "\n";

    return 0;   
}

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

    vector<int> intervalos = {2, 4, 5, 7, 9, 11};
    vector<string> nomes = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
    vector<set<int>> notas(12);
    vector<bool> ok(12, true);

    for(int i = 0; i < 12; i++){
        notas[i].insert(i);
        for(int j = 0; j < 6; j++)
            notas[i].insert((i + intervalos[j]) % 12);
    }

    int n;
    cin >> n;

    while(n--){
        int x;
        cin >> x;
        x = (x - 1) % 12;
        for(int i = 0; i < 12; i++){
            if(ok[i] && notas[i].find(x) == notas[i].end()){
                ok[i] = false;
            }
        }
    }

    for(int i = 0; i < 12; i++){
        if(ok[i]){
            cout << nomes[i] << "\n";
            return 0;
        }
    }

    cout << "desafinado" << "\n";

    return 0;   
}

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

bool check(pii p[3]){

    if(p[0].first == p[1].first && p[1].first == p[2].first){
        if(p[0].second + p[1].second + p[2].second == p[0].first){
            return true;
        }
    }

    if(p[1].first == p[2].first){
        if(p[1].first + p[0].first == p[0].second && p[0].second == p[1].second + p[2].second){
            return true;
        }
    }

    return false;
}

int main(){
    optimize;

    pii p[3];

    for(int i = 0; i < 3; i++){
        cin >> p[i].first >> p[i].second;
    }

    bool ok = false;

    sort(p, p + 3);

    do {
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 3; j++){
                if(i & (1 << j)){
                    swap(p[j].first, p[j].second);
                }
            }

            if(check(p)){
                ok = true;
            }

            for(int j = 0; j < 3; j++){
                if(i & (1 << j)){
                    swap(p[j].first, p[j].second);
                }
            }
        }
    } while(!ok && next_permutation(p, p + 3));

    cout << (ok ? "YES" : "NO") << "\n";
    
    return 0;   
}

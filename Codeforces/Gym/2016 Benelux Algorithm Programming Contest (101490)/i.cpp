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

    int q, root, cnt = 0;
    cin >> q;

    root = sqrt(q);

    for(int i = 2; i <= root; i++){
        if(q % i == 0){
            
            cnt++;

            while(q % i == 0){
                q /= i;
            }
        }
    }

    if(q != 1)
        cnt++;

    if(cnt == 1){
        cout << "yes" << "\n";
    }
    else{
        cout << "no" << "\n";
    }
    
    return 0;   
}

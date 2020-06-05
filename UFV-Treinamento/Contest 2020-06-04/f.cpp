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

vector<bool> prime;

void crivo(ll n){
    prime.assign(n + 1, true);
    prime[0] = prime[1] = false;
    
    for(ll i = 2; i <= n; i++){
        if(prime[i]){
            for(ll j = i * i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
}

int main(){
    optimize;
    
    crivo(400010);

    int n;
    cin >> n;

    int cont1 = 0, cont2 = 0, sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1) 
            cont1++;
        else
            cont2++;
    }

    while(cont1 || cont2){
        if(!cont1){
            cout << 2 << " ";
            sum += 2;
            cont2--;
        }
        else if(!cont2){
            cout << 1 << " ";
            sum += 1;
            cont1--;
        }
        else{
            if(prime[sum + 1]){
                cout << 1 << " ";
                sum += 1;
                cont1--;
            }
            else{
                cout << 2 << " ";
                sum += 2;
                cont2--;
            }
        }
    }
    cout << "\n";

    return 0;   
}

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

    while(T--){
        
        int N, i, sum = 0;
        bool ok = false, odd = true;
        
        cin >> N >> i;

        while(!ok){
            if(odd){
                if(i % 2){
                    cout << sum + (i + 1) / 2 << "\n";
                    ok = true;
                }
                else{
                    i /= 2;
                    
                    sum += N / 2;
                    if(N % 2)
                        sum++;
                }
            }
            else{
                if(i % 2){
                    i++;
                    i /= 2;

                    sum += N / 2;
                    
                }
                else{
                    cout << sum + i / 2 << "\n";
                    ok = true;
                }
            }

            if(N % 2){
                if(!odd)
                    N++;
                odd = !odd;
            }
            
            N /= 2;
        }
    }
    
    return 0;   
}

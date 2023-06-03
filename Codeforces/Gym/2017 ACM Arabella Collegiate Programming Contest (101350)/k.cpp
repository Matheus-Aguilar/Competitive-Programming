#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int digit[10], freq[10];

void process(ll y){
    memset(freq, 0, sizeof(freq));
    
    while(y > 0){
        freq[y % 10]++;
        y /= 10;
    }

    int m = 0;

    for(int i = 0; i < 10; i++){
        m = max(m, freq[i]);
    }
    
    for(int i = 0; i < 10; i++){
        if(m == freq[i]){
            digit[i]++;
        }
    }
}

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        
        memset(digit, 0, sizeof(digit));

        long long a, b, n, x = 1;
        cin >> a >> b >> n;

        while(a * x * x + b * x <= n){
            ll y = a * x * x + b * x;
            process(y);
            x++;
        }

        int m = digit[0], d = 0;

        for(int i = 0; i < 10; i++){
            if(m < digit[i]){
                m = digit[i];
                d = i;
            }
        }

        if(m == 0)
            cout << -1 << "\n";
        else
            cout << d << "\n";
    }

    return 0;
}
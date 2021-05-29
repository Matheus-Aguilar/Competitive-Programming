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

void encode(int n, bool *a){
    a[0] = n & (1 << 3);
    a[1] = n & (1 << 2);
    a[2] = n & (1 << 1);
    a[3] = n & 1;
}

void reverse(bool *a){
    swap(a[0], a[3]);
    swap(a[1], a[2]);
}

void decrement(bool *a){
    for(int i = 3; i >= 0; i--){
        if(a[i] == 1){
            a[i] = 0;
            break;
        }
        a[i] = 1;
    }
}

int decode(bool *a){
    return (a[0] << 3) + (a[1] << 2) + (a[2] << 1) + a[3];
}


int main(){
    optimize;

    int n; bool a[4];
    cin >> n;

    encode(n, a);
    reverse(a);
    decrement(a);
    reverse(a);
    cout << decode(a) << "\n";

    return 0;   
}

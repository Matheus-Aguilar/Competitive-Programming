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
#define BLOCK_SIZE 1000000

using namespace std;

ll M = 1099511627776, s0 = 1611516670;
int start = 350125310, period = 182129209; // Computed with findCycle
int c1, c2, c3[1000];
ll sarr[1000];

ll next(ll s){
    return (s + (s >> 20) + 12345) % M;
}

void findCycle(){
    
    ll tortoise = next(s0), hare = next(next(s0));
    
    while(tortoise != hare){
        tortoise = next(tortoise);
        hare = next(next(hare));
    }

    start = 0;
    tortoise = s0;

    while(tortoise != hare){
        tortoise = next(tortoise);
        hare = next(hare);
        start++;
    }

    period = 1;
    hare = next(tortoise);

    while(tortoise != hare){
        hare = next(hare);
        period++;
    }
}

int main(){
    optimize;

    findCycle();

    cout << start << " " << period << endl << endl;

    c1 = 1, c2 = 0, c3[0] = 1;
    ll s = s0;

    sarr[0] = s0;
    
    for(int i = 1; i < start; i++){
        s = next(s);
        if(s % 2 == 0){
            c1++;
            c3[i / BLOCK_SIZE]++;
        }
        if(i % BLOCK_SIZE == 0)
            sarr[i / BLOCK_SIZE] = s;
    }

    cout << c1 << endl;

    for(int i = start; i < start + period; i++){
        s = next(s);
        if(s % 2 == 0){
            c2++;
            c3[i / BLOCK_SIZE]++;
        }
        if(i % BLOCK_SIZE == 0)
            sarr[i / BLOCK_SIZE] = s;
    }

    cout << c2 << endl;

    cout << endl;

    for(int i = 0; i < start + period; i += BLOCK_SIZE)
        cout << c3[i / BLOCK_SIZE] << endl;
    
    cout << endl;

    for(int i = 0; i < start + period; i += BLOCK_SIZE)
        cout << sarr[i / BLOCK_SIZE] << endl;

    return 0;   
}

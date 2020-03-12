#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

/* PAR
    0 = 0
    1 = 1
    2 = 2
    3 = 0
    4 = 1
    5 = 0
    6 = 1
    7 = 0
    8 = 1
    ...
*/


/*IMPAR
    0 = 0
    1 = 1
    2 = 0
    3 = 1
    4 = 2
    5 = 0
    6 = 2
    7 = 0
    8 = 1
    ...
*/

int grundy(int n, int k){
    if(!n) return 0;

    if(k % 2){
        if(n == 1 || n == 3)
            return 1;
        if(n == 2 || n % 2)
            return 0;
        if(n == 4)
            return 2;
        if(grundy(n/2, k) == 1)
            return 2;
        return 1;
    }
    else{
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        return 1 - n % 2;
    }
}

int main(){
    optimize;
    
    int n, k;
    cin >> n >> k;

    int ans = 0;
    while(n--){
        int x;
        cin >> x;
        ans ^= grundy(x, k);
    }

    cout << (ans ? "Kevin" : "Nicky") << "\n";
}
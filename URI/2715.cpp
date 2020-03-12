#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        vector<long long int>v(n);
        for(int i = 0; i < n; i++) 
            scanf("%Ld", &v[i]);
        long long int sum = accumulate(v.begin(), v.end(), 0ll);
        long long int acu = 0;
        long long int best = sum;
        for(int i = 0; i < n; i++){
            acu += v[i];
            sum -= v[i];
            best = min(abs(acu - sum), best);
        }
        printf("%Ld\n", best);
    }
}
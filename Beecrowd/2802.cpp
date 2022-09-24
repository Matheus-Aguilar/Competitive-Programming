#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    scanf("%Ld", &n);
    printf("%Ld\n", 1 + ((n -1) * n)/2 + ((n - 3) * (n - 2) * (n - 1) * n)/24 );
}
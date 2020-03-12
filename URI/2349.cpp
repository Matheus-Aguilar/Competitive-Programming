#include<cstdio>
#include<vector>

using std::vector;
using std::scanf;
using std::printf;

int main(){
    int n, c, s, r = 0, p = 1;
    scanf("%d %d %d\n", &n, &c, &s);
    if(s == 1) r++;
    while(c--){
        int x;
        scanf("%d", &x);
        p += x;
        if(p == 0) p = n;
        else if(p > n) p = 1;
        
        if(p == s) r++;
    }
    printf("%d\n", r);
}
#include<bits/stdc++.h>

using namespace std;

long double dist(int a, int b, int c, int d){
    return sqrtl((a - b) * (a - b) + (c - d) * (c - d));
}

int main(){
    int x1,y1,r1,x2,y2,r2;
    while(scanf("%d%d%d%d%d%d", &r1, &x1, &y1, &r2, &x2, &y2) == 6)
        printf("%s\n", ((r2 + dist(x1, x2, y1, y2) <= r1 ? "RICO" : "MORTO")));
}
#include<bits/stdc++.h>

using namespace std;

int radius[4][3] = {
    {20, 30, 50},
    {10, 25, 40},
    {25, 55, 70},
    {18, 38, 60}
};

int damage[4] = {200, 300, 400, 100};

int nameMap(char *type){
    if(!strcmp(type, "fire"))
        return 0;
    if(!strcmp(type, "water"))
        return 1;
    if(!strcmp(type, "earth"))
        return 2;
    if(!strcmp(type, "air"))
        return 3;
}

bool check(int y0, int y, int x, int cx, int cy, int r2){
    if(r2 - (x - cx) * (x - cx) < 0) return false;
    return (sqrt(r2 - (x - cx) * (x - cx)) + cy >= y0 && sqrt(r2 - (x - cx) * (x - cx)) + cy <= y) ||
    (-sqrt(r2 - (x - cx) * (x - cx)) + cy >= y0 && -sqrt(r2 - (x - cx) * (x - cx)) + cy <= y);
}

bool inCircle(int x0, int y0, int cx, int cy, int r2){
    return (x0 - cx) * (x0 - cx) + (y0 - cy) * (y0 - cy) <= r2;
}

bool inRetangle(int x0, int y0, int x, int y, int cx, int cy, int r2){
    int r = sqrt(r2);
    return cx - r >= x0 && cy - r >= y0 && cx + r <= x && cy + r <= y; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x0, y0, w, h, x, y;
        scanf("%d%d%d%d", &w, &h, &x0, &y0);
        x = x0 + w;
        y = y0 + h;

        char type[10];
        int l, cx, cy;
        scanf("%s%d%d%d", &type, &l, &cx, &cy);

        int r = radius[nameMap(type)][l - 1];
        r *= r;
    
        if(check(y0, y, x0, cx, cy, r) || check(y0, y, x, cx, cy, r) || check(x0, x, y0, cy, cx, r) || check(x0, x, y, cy, cx, r) || inCircle(x0, y0, cx, cy, r) || inCircle(x0, y, cx, cy, r) || inCircle(x, y0, cx, cy, r) || inCircle(x, y, cx, cy, r) || inRetangle(x0, y0, x, y, cx, cy, r))
            printf("%d\n", damage[nameMap(type)]);
        else
            printf("0\n");
    }
}
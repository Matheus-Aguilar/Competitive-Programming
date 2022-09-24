#include<bits/stdc++.h>

using namespace std;

long double integral(long double x, long double r, bool mode){
    if(mode)
        return (r * r/2) * (asinl(x/r - 1) + sinl(2 * asinl(x/r - 1))/2);
    else
        return -(r * r/2) * (asinl(x/r - 1) + sinl(2 * asinl(x/r - 1))/2) + r * x;
}

long double integralDef(long double a, long double b, long double r, bool mode){
    return integral(b, r, mode) - integral(a, r, mode);
}

int main(){
    long double r, intersectionPoint;
    while(scanf("%Lf", &r) == 1){
        if(ceill(r) == 0){
            printf("0.000 0.000 0.000\n");
            continue;
        }
        intersectionPoint = r * (1 - 1.73205080757l/2);
        long double stripedArea = 2 * (integralDef(intersectionPoint, r/2, r, true) - integralDef(intersectionPoint, r/2, r, false));
        long double otherArea = 4 * (integralDef(0, intersectionPoint, r, false) - integralDef(0, intersectionPoint, r, true));
        long double dottedArea = r * r - stripedArea - otherArea; 
        printf("%.3Lf %.3Lf %.3Lf\n", stripedArea, dottedArea, otherArea);
    }
}
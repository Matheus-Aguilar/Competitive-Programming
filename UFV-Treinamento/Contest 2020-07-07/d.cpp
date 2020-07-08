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

int dist(int xA, int yA, int xB, int yB){
    return (xA - xB) * (xA - xB) + (yA - yB) * (yA - yB);
}

bool contains(int rA, int xA, int yA, int rB, int xB, int yB){
    if(rB > rA) return false;  
    return dist(xA, yA, xB, yB) <= (rA - rB) * (rA - rB); 
}

bool intersects(int rA, int xA, int yA, int rB, int xB, int yB){
    return dist(xA, yA, xB, yB) < (rA + rB) * (rA + rB); 
}

int main(){
    optimize;

    int r, d, n;
    cin >> r >> d >> n;
    
    int cont = 0;

    while(n--){
        int xi, yi, ri;
        cin >> xi >> yi >> ri;
        if(!contains(r - d, 0, 0, ri, xi, yi) && !intersects(r - d, 0, 0, ri, xi, yi) && contains(r, 0, 0, ri, xi, yi)){
            cont++;
        }
        else if(ri == 0 && (xi * xi + yi * yi == (r - d) * (r - d)))
            cont++;
    }

    cout << cont << "\n";

    return 0;   
}

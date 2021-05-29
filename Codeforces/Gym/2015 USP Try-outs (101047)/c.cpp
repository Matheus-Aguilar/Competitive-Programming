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

void mult(double a[3][3], double b[3][3]){
    
    double c[3][3];
    ms(c, 0);
    
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j])); 
    
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            a[i][j] = c[i][j];
}

void fastExpo(double x[3][3], ll y){

    double r[3][3];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            r[i][j] = (i == j);
    
    while(y > 0){
        if(y & 1)
            mult(r, x);
        y >>= 1;
        mult(x, x);
    }

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            x[i][j] = r[i][j];
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        double a, l;
        
        cin >> a >> l >> n;
    
        a = (a * PI) / 180.0; //degree to radians

        /*
        |1 0 L| * | cos(a) -sin(a) 0| = |cos(a) -sin(a) L|
        |0 1 0|   | sin(a)  cos(a) 0|   |sin(a)  cos(a) 0|
        |0 0 1|   |   0       0    1|   |   0       0   1|
        */

       double m[3][3] = { {cos(a), -sin(a), l}, {sin(a), cos(a), 0}, {0, 0, 1} };

       fastExpo(m, n);

       double x = m[0][2];
       double y = m[1][2];

       cout << fixed << setprecision(9) << x << " " << y << "\n";
    }
    
    return 0;   
}

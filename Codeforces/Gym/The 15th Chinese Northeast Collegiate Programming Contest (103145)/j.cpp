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

typedef double Mat[3][3];

void clear(Mat a){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            a[i][j] = 0;
}

void copy(Mat a, Mat b){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            a[i][j] = b[i][j];
}

void mult(Mat a, Mat b, Mat c){

    clear(c);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }   
    }
}

void mult(Mat a, double k){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            a[i][j] *= k;
}

void sum(Mat a, Mat b){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            a[i][j] += b[i][j];
}

void identity(Mat a){
    
    clear(a);

    for(int i = 0; i < 3; i++)
        a[i][i] = 1;
}

double norm(double a, double b, double c){
    return sqrt(a * a + b * b + c * c);
}

void rotation(double x, double y, double z, double a, double b, double c, double r, double &px, double &py, double &pz){
    
    Mat R1, R2, R3, R;
    
    Mat C = {
        {0, -c, b},
        {c, 0, -a},
        {-b, a, 0}
    };

    clear(R);

    identity(R1);

    copy(R2, C);
    mult(R2, sin(r));

    mult(C, C, R3);
    mult(R3, 1 - cos(r));

    sum(R, R1);
    sum(R, R2);
    sum(R, R3);

    px = x * R[0][0] + y * R[0][1] + z * R[0][2];
    py = x * R[1][0] + y * R[1][1] + z * R[1][2];
    pz = x * R[2][0] + y * R[2][1] + z * R[2][2];
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        double a, b, c, x, y, z, r, px, py, pz, qx, qy, qz;
        cin >> a >> b >> c >> x >> y >> z;

        double n = norm(a, b, c);

        a /= n;
        b /= n;
        c /= n;

        r = (180.0 * r) / PI;

        rotation(x, y, z, a, b, c, r, px, py, pz);
        rotation(x, y, z, a, b, c, -r, qx, qy, qz);

        if(pz > qz)
            cout << fixed << setprecision(9) << px << " " << py << " " << pz << "\n";
        else
            cout << fixed << setprecision(9) << qx << " " << qy << " " << qz << "\n";
    }
    
    return 0;   
}

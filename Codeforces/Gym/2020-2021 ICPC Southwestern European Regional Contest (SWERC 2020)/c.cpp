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
#define MAXN 1010

using namespace std;

const double EPS = 1e-6;

int X, Y, N;
double x[MAXN], y[MAXN];

bool u[MAXN], d[MAXN], l[MAXN], r[MAXN];

// Geometry
double dist(double x1, double y1, double x2, double y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

// Union Find

int parent[MAXN];

void init(int n){
    iota(parent, parent + n, 0);
}

int find(int a){
    if(a == parent[a])
        return a;
    parent[a] = find(parent[a]);
    return parent[a];
}

void merge(int a, int b){
    int pa = find(a), pb = find(b);
    if(pa != pb)
        parent[pa] = pb;
}

// Binary Search

bool check(double m){
    init(N);

    const double radius = 4 * m * m;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(dist(x[i], y[i], x[j], y[j]) <= radius){
                merge(i, j);
            }
        }
    }

    ms(u, false);
    ms(d, false);
    ms(l, false);
    ms(r, false);

    for(int i = 0; i < N; i++){
        
        int p = find(i);
        
        if(x[i] - m <= 0)
            l[p] = true;
        if(x[i] + m >= X)
            r[p] = true;
        if(y[i] - m <= 0)
            d[p] = true;
        if(y[i] + m >= Y)
            u[p] = true;
    }

    for(int i = 0; i < N; i++){
        if(d[i] && u[i]) return false;
        if(l[i] && r[i]) return false;
        if(l[i] && d[i]) return false;
        if(r[i] && u[i]) return false;
    }

    return true;
}

double binSearch(double l, double r){
    while(abs(r - l) > EPS){
        double m = (l + r) / 2.0;

        if(check(m))
            l = m;
        else
            r = m;
    }
    return (l + r) / 2.0;
}

int main(){
    optimize;

    cin >> X >> Y >> N;

    for(int i = 0; i < N; i++)
        cin >> x[i] >> y[i];
    
    cout << fixed << setprecision(9) << binSearch(0, INF) << "\n";
    
    return 0;   
}

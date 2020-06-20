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
#define MAXN 3000

using namespace std;

int a, b, q, zero = -1;
int p[MAXN];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int p1, int p2){
    int ans;
    cout << "? " << p1 << " " << p2 << endl;
    cin >> ans;
    return ans;
}

int main(){
    //optimize;
    
    int n;
    cin >> n;

    iota(p, p + n, 1);
    shuffle(p, p + n, rng);

    a = p[0];
    b = p[1];
    q = query(a, b);

    for(int i = 2; i < n; i++){
        int val = query(b, p[i]);
        if(q > val){
            a = p[i];
            q = val;
        }
        else if(q == val){
            b = p[i];
            q = query(a, b);
        }
    }

    do{
        int c, q1, q2;
        
        do{
            c = p[rng() % n];
        } while(c == a || c == b);
        
        q1 = query(a, c);
        q2 = query(b, c);

        if(q1 != q2)
            zero = (q1 < q2 ? a : b);    
    } while(zero == -1);

    for(int i = 0; i < n; i++)
        p[i] = (i + 1 == zero ? 0 : query(zero, i + 1));
    
    cout << "! ";
    for(int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << endl;

    return 0;   
}

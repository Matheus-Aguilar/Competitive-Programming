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

int main(){
    //optimize;

    map<int, pii> m;
    m[4 * 8] = pii(4, 8);
    m[4 * 15] = pii(4, 15);
    m[4 * 16] = pii(4, 16);
    m[4 * 23] = pii(4, 23);
    m[4 * 42] = pii(4, 42);
    m[8 * 15] = pii(8, 15);
    m[8 * 16] = pii(8, 16);
    m[8 * 23] = pii(8, 23);
    m[8 * 42] = pii(8, 42);
    m[15 * 16] = pii(15, 16);
    m[15 * 23] = pii(15, 23);
    m[15 * 42] = pii(15, 42);
    m[16 * 23] = pii(16, 23);
    m[16 * 23] = pii(16, 23);
    m[23 * 42] = pii(23, 42);
    
    int a1, a2;
    pii p1, p2;
    vector<int> perm(6);
    
    cout << "? " << 1 << " " << 2 << endl;
    cin >> a1;
    p1 = m[a1];
    
    cout << "? " << 2 << " " << 3 << endl;
    cin >> a2;
    p2 = m[a2];

    if(p1.first == p2.first){
        perm[1] = p1.first;
        perm[0] = p1.second;
        perm[2] = p2.second;
    }
    else if(p1.first == p2.second){
        perm[1] = p1.first;
        perm[0] = p1.second;
        perm[2] = p2.first;
    }
    else if(p1.second == p2.first){
        perm[1] = p1.second;
        perm[0] = p1.first;
        perm[2] = p2.second;
    }
    else{
        perm[1] = p1.second;
        perm[0] = p1.first;
        perm[2] = p2.first;
    }

    cout << "? " << 4 << " " << 5 << endl;
    cin >> a1;
    p1 = m[a1];
    
    cout << "? " << 5 << " " << 6 << endl;
    cin >> a2;
    p2 = m[a2];

    if(p1.first == p2.first){
        perm[4] = p1.first;
        perm[3] = p1.second;
        perm[5] = p2.second;
    }
    else if(p1.first == p2.second){
        perm[4] = p1.first;
        perm[3] = p1.second;
        perm[5] = p2.first;
    }
    else if(p1.second == p2.first){
        perm[4] = p1.second;
        perm[3] = p1.first;
        perm[5] = p2.second;
    }
    else{
        perm[4] = p1.second;
        perm[3] = p1.first;
        perm[5] = p2.first;
    }

    cout << "! ";
    for(int i = 0; i < 6; i++)
        cout << perm[i] << " ";
    cout << "\n";

    return 0;   
}

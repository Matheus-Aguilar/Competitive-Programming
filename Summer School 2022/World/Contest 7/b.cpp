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

int n, m, r1, c1, r2, c2, r3, c3, p, p1, p2, p3;
bool visit[10][10];

unsigned long long m1[(1 << 20)], m2[(1 << 20)], m3[(1 << 20)], m4[(1 << 20)];
int a1, a2, a3, a4;

map<unsigned long long, int> mp;

void bt(int i, int j, int k, int di, int dj, unsigned long long mask, unsigned long long ans[], int &c){
    
    if(k <= 0){
        return;
    }

    if(i == di && j == dj){
        if(k == 1){
            ans[c++] = mask;
        }
        return;
    }

    visit[i][j] = true;
    mask ^= (1ull << (m * i + j));

    if(i > 0 && !visit[i - 1][j])
        bt(i - 1, j, k - 1, di, dj, mask, ans, c);
    if(j > 0 && !visit[i][j - 1])
        bt(i, j - 1, k - 1, di, dj, mask, ans, c);
    if(i < n - 1 && !visit[i + 1][j])
        bt(i + 1, j, k - 1, di, dj, mask, ans, c);
    if(j < m - 1 && !visit[i][j + 1])
        bt(i, j + 1, k - 1, di, dj, mask, ans, c);
    
    visit[i][j] = false;
    mask ^= (1ull << (m * i + j));
}

int main(){
    optimize;

    int t = 1;

    while(cin >> n >> m){

        if(n == 0 && m == 0)
            break;

        cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;

        p = n * m;
        p1 = p / 4;
        p2 = p / 2;
        p3 = (3 * p) / 4;

        a1 = a2 = a3 = a4 = 0;

        unsigned long long aux = 0;

        for(int i = p; i < 64; i++){
            aux |= (1ull << i);
        }

        bt(0, 0, p1, r1, c1, 0, m1, a1);
        bt(r1, c1, p2 - p1 + 1, r2, c2, 0, m2, a2);
        bt(r2, c2, p3 - p2 + 1, r3, c3, 0, m3, a3);
        bt(r3, c3, p - p3 + 1, 0, 1, 0, m4, a4);

        for(int i = 0; i < a4; i++){
            m4[i] |= (1ull << 1);
        }

        for(int i = 0; i < a1; i++){
            for(int j = 0; j < a2; j++){
                if((m1[i] & m2[j]) == 0ull){
                    mp[m1[i] ^ m2[j]]++;
                }
            }
        }
        
        ll sum = 0;

        for(int i = 0; i < a3; i++){
            for(int j = 0; j < a4; j++){
                if((m3[i] & m4[j]) == 0ull){
                    unsigned long long x = (m3[i] ^ m4[j]);
                    sum += mp[(~x) ^ aux];
                }
            }
        }
    
        cout << "Case " << t++ << ": " << sum << "\n";

        mp.clear();
    }

    return 0;   
}

// 0 6 12
// 7 8 13 14 15
// 5 11 16 17
// 1 2 3 4 9 10
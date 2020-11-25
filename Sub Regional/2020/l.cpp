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
#define MAXN 50

using namespace std;

int l, c, n;
int ok[MAXN][MAXN];

char board[MAXN][MAXN];

vector<int> word(26, 0), window(26, 0);

int main(){
    optimize;
    
    cin >> l >> c;

    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            cin >> board[i][j];

    vector<vector<int>> line;

    //Top -- (0, i)
    for(int i = 0; i < c; i++){
        line.push_back({0, i, 1, 0});
        line.push_back({0, i, 1, 1});
        line.push_back({0, i, 1, -1});
    }
    
    //Bottom -- (l - 1, i)
    for(int i = 0; i < c; i++){
        line.push_back({l - 1, i, -1, 0});
        line.push_back({l - 1, i, -1, 1});
        line.push_back({l - 1, i, -1, -1});
    }

    //Left -- (i, 0)
    for(int i = 0; i < l; i++){
        line.push_back({i, 0, 0, 1});
        line.push_back({i, 0, 1, 1});
        line.push_back({i, 0, -1, 1});
    }

    //Right -- (i, c - 1)
    for(int i = 0; i < l; i++){
        line.push_back({i, c - 1, 0, -1});
        line.push_back({i, c - 1, 1, -1});
        line.push_back({i, c - 1, -1, -1});
    }

    // for(int i = 0; i < line.size(); i++){
    //     for(int j = line[i][0], k = line[i][1]; j < l && k < c && j >= 0 && k >= 0; j += line[i][2], k += line[i][3]){
    //         cout << board[j][k];
    //     }
    //     cout << "\n";
    // }

    cin >> n;

    while(n--){
        string s;
        cin >> s;

        fill(all(word), 0);

        for(int i = 0; i < s.size(); i++)
            word[s[i] - 'A']++;

        for(int i = 0; i < line.size(); i++){
            
            int cont = 0;
            
            fill(all(window), 0);

            for(int j = line[i][0], k = line[i][1]; j < l && k < c && j >= 0 && k >= 0; j += line[i][2], k += line[i][3]){
                
                if(cont == s.size())
                    window[board[j - cont * line[i][2]][k - cont * line[i][3]] - 'A']--;
                else
                    cont++;

                window[board[j][k] - 'A']++;

                if(window == word){
                
                    for(int j2 = j - (cont - 1) * line[i][2], k2 = k - (cont - 1) * line[i][3]; j2 != j || k2 != k; j2 += line[i][2], k2 += line[i][3])
                        ok[j2][k2] |= (1 << n);

                    ok[j][k] |= (1 << n);
                }
            }   
        }
    }

    int ans = 0;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            ans += (__builtin_popcount(ok[i][j]) > 1);
        }
    }
    cout << ans << "\n";

    return 0;   
}

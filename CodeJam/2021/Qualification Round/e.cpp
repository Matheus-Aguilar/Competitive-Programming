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
    optimize;

    int T, P;
    cin >> T >> P;

    vector<string> score(100);
    vector<int> p(100);
    vector<double> sus(100);
    vector<int> q(10000);
    vector<int> pos(10000);
    vector<pii> aux(10000); 

    for(int t = 1; t <= T; t++){
        
        for(int i = 0; i < 100; i++)
            cin >> score[i];
        
        for(int i = 0; i < 100; i++){
            p[i] = 0;
            for(int j = 0; j < 10000; j++){
                if(score[i][j] == '1')
                    p[i]++;
            }
        }

        for(int i = 0; i < 10000; i++){
            q[i] = 0;
            for(int j = 0; j < 100; j++){
                if(score[j][i] == '1')
                    q[i]++;
            }
            aux[i] = make_pair(-q[i], i);
        }

        sort(all(aux));

        for(int i = 0; i < 10000; i++){
            pos[aux[i].second] = i + 1;
        }

        int ans = -1;

        for(int i = 0; i < 100; i++){
            
            sus[i] = 0;
            
            for(int j = 0; j < 10000; j++){
                
                if(score[i][j] == '0' && pos[j] <= p[i] && p[i] > 1){
                    sus[i] += 1 - 0.5 * (pos[j] - 1) / (p[i] - 1);
                }

                if(score[i][j] == '1' && pos[j] > p[i] && (10000 - p[i]) > 1){
                    sus[i] += 0.5 + 0.5 * (pos[j] - p[i] - 1) / (10000 - p[i] - 1);
                }
            }

            if(ans == -1 || sus[ans] < sus[i])
                ans = i;
        }

        cout << "Case #" << t << ": " << ans + 1 << "\n";
    }
    
    return 0;   
}

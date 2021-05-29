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

void print(vector<pair<string, int>> &steps){
    cout << steps.size() << "\n";
    for(int i = 0; i < steps.size(); i++)
        cout << steps[i].second << " " << steps[i].first << "\n";
}

int main(){
    optimize;
    
    int n, m, k;
    cin >> n >> m >> k;

    if(4 * n * m - 2 * n - 2 * m < k){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        vector<pair<string, int>> steps;
        
        if(m > 1){
            steps.push_back(make_pair("R", min(k, m - 1)));
            k -= min(k, m - 1);
        }

        if(k == 0){
            print(steps);
            return 0;
        }

        if(m > 1){
            steps.push_back(make_pair("L", min(k, m - 1)));
            k -= min(k, m - 1);
        }

        if(k == 0){
            print(steps);
            return 0;
        }

        for(int i = 0; i < n - 1; i++){
            steps.push_back(make_pair("D", 1));
            k--;
            if(k == 0){
                print(steps);
                return 0;
            }

            if(m > 1){
                if(k >= 3 * m - 3){
                    steps.push_back(make_pair("RUD", m - 1));
                    k -= 3 * m - 3;    
                }
                else{
                    if(k >= 3) steps.push_back(make_pair("RUD", k/3));
                    if(k % 3 == 1)
                        steps.push_back(make_pair("R", 1));
                    else if(k % 3 == 2)
                        steps.push_back(make_pair("RU", 1));
                    print(steps);
                    return 0;
                }

                if(k == 0){
                    print(steps);
                    return 0;
                }

                steps.push_back(make_pair("L", min(k, m - 1)));
                k -= min(k, m - 1);
            }
            if(k == 0){
                print(steps);
                return 0;
            }   
        }

        if(n > 1){
            steps.push_back(make_pair("U", min(k, n - 1)));
            print(steps);
        }
        return 0;
    }

    return 0;   
}

#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 200200

using namespace std;

ll nums[MAXN];

vector<ll> sums;
unordered_map<ll, vector<pii>> um;

void precalc(){
    for(ll i = 0; i < 220; i++){
        nums[i] = i * i * i * i;
    }

    for(int i = 0; i < 220; i++){
        for(int j = i; j < 220; j++){
            sums.push_back(nums[i] + nums[j]);
            um[nums[i] + nums[j]].emplace_back(i, j);
        }
    }

    sort(all(sums));
    sums.resize(unique(all(sums)) - sums.begin());
}

vector<vector<ll>> quads;

int main(){
    optimize;

    precalc();

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        int l = 0, r = sums.size() - 1;
        quads.clear();

        while(l <= r){
            
            ll sum = sums[l] + sums[r];
            
            if(sum < n){
                l++;
            } else if(sum > n){
                r--;
            } else {
                
                for(auto i : um[sums[l]]){
                    for(auto j : um[sums[r]]){
                        
                        vector<ll> quad;

                        if(i.second > j.first)
                            continue;

                        quad.emplace_back(i.first);
                        quad.emplace_back(i.second);
                        quad.emplace_back(j.first);
                        quad.emplace_back(j.second);

                        sort(all(quad));
                        quads.push_back(quad);
                    }
                }
                
                l++;
                r--;
            }
        }

        sort(all(quads));

        cout << quads.size() << "\n";

        for(int i = 0; i < quads.size(); i++){
            cout << quads[i][0] << " " << quads[i][1] << " " << quads[i][2] << " " << quads[i][3] << "\n";
        }
    }

    return 0;   
}

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
    
    int m, n, k, s;
    cin >> m >> k >> n >> s;
    
    vector<int> a(m);
    vector<int> b(s);

    vector<int> cont(500010, 0);
    vector<int> mCont(500010, 0);

    set<int> notOk;

    for(int i = 0; i < m; i++)
        cin >> a[i];
    for(int i = 0; i < s; i++){
        cin >> b[i];
        mCont[b[i]]++;
        notOk.insert(b[i]);
    }

    int i = 0, j = 0;
    cont[a[0]]++;
    if(cont[a[0]] >= mCont[a[0]]) 
        notOk.erase(a[0]);
    while(i < m && j < m && i <= j){
        if(notOk.empty()){
            if(i/k + (m - max(j + 1, i + k))/k >= n - 1){
                vector<int> rem;
                for(int x = 0; x < i % k; x++)
                    rem.push_back(x + 1);

                int sz = rem.size();

                for(int x = i; x <= j; x++){
                    if(mCont[a[x]] <= 0 && ((i - sz)/k) * k != ((j - rem.size())/k) * k)
                        rem.push_back(x + 1);
                    else
                        mCont[a[x]]--;
                }
                cout << rem.size() << "\n";
                for(int x:rem) cout << x << " ";
                cout << "\n";
                return 0;
            }
            else{
                cont[a[i]]--;
                if(cont[a[i]] < mCont[a[i]]) 
                    notOk.insert(a[i]);
                i++;
            }
        }
        else{
            j++;
            if(j >= m) continue;
            cont[a[j]]++;
            if(cont[a[j]] >= mCont[a[j]]) 
                notOk.erase(a[j]);
        }
    }

    cout << -1 << "\n";

    return 0;   
}
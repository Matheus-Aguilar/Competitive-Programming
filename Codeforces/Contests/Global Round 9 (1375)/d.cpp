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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> cont(n + 1, 0);
        vector<int> op;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            cont[a[i]]++;
        }

        bool ord = true;
        for(int i = 1; i < n && ord; i++)
            ord = (a[i - 1] <= a[i]);

        while(!ord){
            int mex = -1;
            for(int i = 0; i <= n && mex == -1; i++)
                mex = (cont[i] ? -1 : i);
            if(mex != n){
                cont[a[mex]]--;
                cont[mex]++;
                a[mex] = mex;
                op.push_back(mex + 1);
            }
            else{
                int pos = -1;
                for(int i = 0; i < n && pos == -1; i++)
                    pos = (a[i] == i ? -1 : i);
                cont[a[pos]]--;
                cont[mex]++;
                a[pos] = mex;
                op.push_back(pos + 1);
            }

            ord = true;
            for(int i = 1; i < n && ord; i++)
                ord = (a[i - 1] <= a[i]);
        }

        cout << op.size() << "\n";
        for(int i = 0; i < op.size(); i++)
            cout << op[i] << " ";
        cout << "\n";
    }
    
    return 0;   
}

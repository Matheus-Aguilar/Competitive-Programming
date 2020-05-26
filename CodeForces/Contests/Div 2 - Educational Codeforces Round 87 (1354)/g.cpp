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

int query(int l1, int r1, int l2, int r2){
    cout << "? " << (r1 - l1 + 1) << " " << (r2 - l2 + 1) << endl;
    for(int i = l1; i <= r1; i++)
        cout << i << " ";
    cout << endl;
    for(int i = l2; i <= r2; i++)
        cout << i << " ";
    cout << endl;

    string ans;
    cin >> ans;

    if(ans == "FIRST") return 1;
    if(ans == "SECOND") return -1;
    if(ans == "EQUAL") return 0;
    exit(0);
}

int main(){
    //optimize;
    srand(time(NULL));
    
    int t;
    cin >> t;
    while(t--){
        int n, k, ans = -1;
        cin >> n >> k;
        vector<int> op(n - 1);
        iota(all(op), 2);
        random_shuffle(all(op));
        for(int i = 0; i < min(n - 1, 30) && ans == -1; i++){
            if(query(1, 1, op[i], op[i]) < 0)
                ans = 1;
        }

        if(ans != -1){
            cout << "! " << ans << endl;
            continue;
        }

        int i, j;

        for(i = 1, j = 2; j < n; i *= 2, j *= 2){
            if(query(1, i, i + 1, j) > 0)
                break;
        }

        i++;
        j = min(j, n);
        while(i < j){
            int k = i + (j - i)/2;
            if(query(1, k - i + 1, i, k) > 0)
                j = k;
            else
                i = k + 1;
        }
        cout << "! " << i << endl;
    }

    return 0;   
}

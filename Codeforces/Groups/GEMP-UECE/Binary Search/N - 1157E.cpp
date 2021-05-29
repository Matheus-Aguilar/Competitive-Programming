#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    int n;
    cin >> n;

    vector<int> a(n);
    multiset<int> b;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b.insert(x);
    }
    for(int i = 0; i < n; i++){
        int best = n - a[i];
        multiset<int>::iterator it = b.lower_bound(best);

        if(it == b.end()){
            best = *(b.begin());
            b.erase(b.begin());
        }
        else{
            best = *it;
            b.erase(it);
        }

        cout << (a[i] + best) % n << " ";
    }

    cout << "\n";

    return 0;   
}

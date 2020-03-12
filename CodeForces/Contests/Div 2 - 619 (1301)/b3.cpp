#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int f(int x, vector<int> &a){
    int m = 0;
    
    for(int i = 0; i < a.size() - 1; i++){
        if(a[i] != -1 && a[i + 1] != -1)
            m = max(m, abs(a[i] - a[i + 1]));
        else if(a[i] != -1)
            m = max(m, abs(a[i] - x));
        else if(a[i + 1] != -1)
            m = max(m, abs(a[i + 1] - x));
    }

    return m;
}

int ternarySearch(int start, int end, vector<int> &a){
    while(start < end){
        int m1 = start + (end - start)/3;
        int m2 = end - (end - start)/3;

        int f1 = f(m1, a);
        int f2 = f(m2, a);

        if(f1 > f2)
            start = m1 + 1;
        else
            end = m2 - 1;
    }
    return start;
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int best = ternarySearch(0, INF + 1, a);

        cout << f(best, a) << " " << best << "\n"; 
    }
    return 0;   
}

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

double area(double a, double b, double c){
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        bool found = false;

        cin >> n;

        vector<double> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(all(a));

        double best = INFLL;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                int l = lower_bound(all(a), a[j] - a[i]) - a.begin();
                int r = upper_bound(all(a), a[i] + a[j]) - a.begin() - 1;

                if(l == i)
                    l++;
                if(l == j)
                    l++;
                if(r == j)
                    r--;
                if(r == i)
                    r--;
                if(l > r)
                    continue;
                
                found = true;
                best = min(best, area(a[i], a[j], a[l]));
                best = min(best, area(a[i], a[j], a[r]));
            }
        }

        if(!found)
            cout << -1 << "\n";
        else
            cout << fixed << setprecision(9) << best << "\n";
    }
    
    return 0;   
}

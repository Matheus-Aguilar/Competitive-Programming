#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int main(){

    optimize;

    int t;
    cin >> t;

    unordered_map<string, double> val;

    while(t--){
        int n, c;
        cin >> c >> n;

        val.clear();

        for(int i = 0; i < c; i++){
            string name;
            double value;
            cin >> name >> value;
            val[name] = value;
        }

        val["JD"] = 1.0;

        double total = 0;

        for(int i = 0; i < n; i++){
            string name;
            double value;
            cin >> value >> name;
            total += value * val[name];
        }

        cout << fixed << setprecision(6) << total << "\n";
    }

    return 0;
}
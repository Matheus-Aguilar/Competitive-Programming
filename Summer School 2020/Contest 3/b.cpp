#include<bits/stdc++.h>
#define ll long long
#define optimize ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main(){
    optimize;
    
    int t, i = 0;
    cin >> t;

    while(t--){
        string s;

        cout << "5 1 5 6" << endl;

        while(cin >> s && s != "GAME"){
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            if(x0 == 5) x0--;
            if(x1 == 5) x1--;
            int ansx0 = 5 - x0, ansx1 = 5 - x1, ansy0 = 7 - y0, ansy1 = 7 - y1;
            cout << min(ansx0, ansx1) << " " << min(ansy0, ansy1) << " " << max(ansx0, ansx1) << " " << max(ansy0, ansy1) << endl; 
        }
    }
}
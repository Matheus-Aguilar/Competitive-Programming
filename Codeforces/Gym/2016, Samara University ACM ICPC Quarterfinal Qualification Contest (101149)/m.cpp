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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    //optimize;

    int n, a, b;
    char res;
    cin >> n;

    vector<int> v(n);
    iota(all(v), 1);
    shuffle(all(v), rng);
    
    cout << "? " << v[0] << " " << v[1] << endl;
    cin >> res;

    if(res == '<'){
        a = v[0];
        b = v[1];
    }
    else{
        a = v[1];
        b = v[0];
    }

    for(int i = 2; i < n; i++){
        cout << "? " << a << " " << v[i] << endl;
        cin >> res;

        if(res == '<'){
            cout << "? " << b << " " << v[i] << endl;
            cin >> res;
            if(res == '>')
                a = v[i];
            else{
                a = b;
                b = v[i];
            }
        }
    }

    cout << "! " << a << endl;

    return 0;   
}

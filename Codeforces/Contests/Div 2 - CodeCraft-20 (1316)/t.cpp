#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    string s;
    int k;
    
    cin >> s >> k;

    for(int i = 0, j = k - 1; j < s.size(); i++, j++){
        reverse(s.begin() + i, s.begin() + j + 1);
    }

    cout << s << endl;

    return 0;   
}

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
#define MAXN 500010

using namespace std;

int main(){
    optimize;

    int acu = 0;
    string s;
    deque<int> d;
    
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            acu++;
        else if(s[i] == ')')
            acu--;
        else
            d.push_back(i);
    }

    while(!d.empty()){
        if(acu <= 0){
            s[d.front()] = '(';
            d.pop_front();
            acu++;
        }
        else{
            s[d.back()] = ')';
            d.pop_back();
            acu--;
        }
    }

    acu = 0;

    for(int i = 0; i < s.size() && acu >= 0; i++){
        if(s[i] == '(')
            acu++;
        else
            acu--;
    }

    if(acu != 0)
        cout << "Impossible" << "\n";
    else
        cout << s << "\n";
    
    return 0;   
}

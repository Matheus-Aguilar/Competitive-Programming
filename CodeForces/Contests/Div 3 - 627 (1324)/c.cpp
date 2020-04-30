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

int n;
string s;

bool check(int x){
    int last = n + 1;

    for(int i = n; i >= 0; i--){
        if(s[i] == 'R'){
            if(last - i <= x)
                last = i;
            else
                return false;
        }
    }
    return true;
}

int binSearch(int start, int end){
    while(start < end){
        int middle =  start + (end - start)/2;
        if(check(middle))
            end = middle;
        else
            start = middle + 1;
    }
    return start;
}

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        n = s.size();
        s = 'R' + s;
        cout << binSearch(1, n + 2) << "\n";
    }
    return 0;   
}

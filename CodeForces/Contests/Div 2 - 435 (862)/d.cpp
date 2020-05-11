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

int question(string &s){
    int ans;
    cout << "? " << s << endl;
    cin >> ans;
    return ans;
}

void answer(int zero, int one){
    cout << "! " << zero << " " << one << endl;
}

void build(int l, int r, int n, string &s, bool mode){
    s = "";
    for(int i = 0; i < n; i++){
        if(l <= i && i <= r){
            if(!mode)
                s += '0';
            else
                s += '1';
        }
        else{
            if(!mode)
                s += '1';
            else
                s += '0';
        }
    }
}

int find(int l, int r, int base, bool mode){
    int n = r + 1;
    string s;
    while(l < r){
        int m = l + (r - l)/2;
        build(m + 1, r, n, s, mode);
        int ans = question(s);
        if(r - m == ans - base)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    //optimize;
    
    int n, zero, one;
    cin >> n;

    string s;
    build(0, n - 1, n, s, 0);
    int ans = question(s);
    build(0, n - 2, n, s, 0);
    if(question(s) > ans){
        zero = n;
        one = find(0, n -1, ans, 1) + 1;
    }
    else{
        one = n;
        build(0, n - 1, n, s, 1);
        ans = question(s);
        zero = find(0, n - 1, ans, 0) + 1;
    }

    answer(zero, one);

    return 0;   
}

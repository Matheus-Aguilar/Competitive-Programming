#include<bits/stdc++.h>

using namespace std;

int m;

bool cmp(const int &a, const int &b){
    if(a % m != b % m)
        return a % m < b % m;
    else if(a % 2 && b % 2)
        return a > b;
    else if(!(a % 2) && !(b % 2))
        return a < b;
    else
        return a % 2;
}

int main(){
    int n;
    while(cin >> n >> m){
        cout << n << " " << m << "\n";
        if(!n && !m) return 0;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < n; i++)
            cout << v[i] << "\n";
    }
}
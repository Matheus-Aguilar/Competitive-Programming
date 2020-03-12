#include<bits/stdc++.h>
#define optimize ios_base:sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

void solve(string &s, list<int> &l, int n){
    int i = 0;
    bool front = true;
    while(i < s.size()){
        if(s[i++] == 'R')
            front = !front;
        else{
            if(n == 0){
                cout << "error" << "\n";
                return;
            }
            if(front)
                l.pop_front();
            else
                l.pop_back();
            n--;
        }
    }

    if(!front)
        reverse(l.begin(), l.end());

    cout << "[";

    if(n == 0){
        cout << "]\n";
        return;
    }

    for(auto it = l.begin(); it != prev(l.end()); it++){
        cout << *it << ",";
    }

    cout << l.back() << "]\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int n, x;
        char aux;
        list <int> l;

        cin >> s;
        cin >> n;
        
        cin >> aux;

        if(!n){
            cin >> aux;
        }
        else{
            for(int i = 0; i < n; i++){
                cin >> x >> aux;
                l.push_back(x);
            }
        }

        solve(s, l, n);
    }
}
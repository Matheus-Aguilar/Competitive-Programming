#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    string s;
    cin >> s;

    list<int> open;
    list<int> close;
    list<int> operations;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            open.push_back(i + 1);
        else
            close.push_back(i + 1);
    }

    while(!open.empty() && !close.empty() && open.front() < close.back()){
        operations.push_front(open.front());
        operations.push_back(close.back());
        open.pop_front();
        close.pop_back();
    }

    if(operations.empty())
        cout << "0" << "\n";
    else{
        cout << "1" << "\n";
        cout << operations.size() << "\n";
        operations.sort();
        for(int i:operations){
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;   
}

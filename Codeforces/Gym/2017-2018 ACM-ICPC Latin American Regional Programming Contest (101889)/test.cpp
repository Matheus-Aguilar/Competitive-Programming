#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int agrc, char **argv){

    int n = atoi(argv[1]);

    bool inv = false;
    deque<char> d;

    for(int i = 0; i < n; i++){
        char c = rng() % ('z' - 'a' + 1) + 'a';
    
        if(inv)
            d.push_front(c);
        else
            d.push_back(c);

        if(c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u')
            inv = !inv;
    }

    if(inv)
        reverse(d.begin(), d.end());

    for(char c : d){
        cout << c;
    }

    cout << "\n";

    return 0;
}
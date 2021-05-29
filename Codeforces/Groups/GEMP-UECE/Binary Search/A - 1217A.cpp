#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int s, i, p, k;

bool check(int x){
    return (s + x) > (i + p - x);
}

int binSearch(int start,  int end){
    while(start < end){
        int middle = start + (end - start)/2;

        if(check(middle))
            end = middle;
        else
            start = middle + 1;
    }

    return start - 1;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        cin >> s >> i >> p;
        
        k = binSearch(0, p + 1);

        cout << p - k << "\n";
    }

    return 0;   
}

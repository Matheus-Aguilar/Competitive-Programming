#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int a, b, n;

bool check(int x){
    return a/x + b/x >= n;
}

int binSearch(int start, int end){
    while(start < end){
        int middle =  start + (end - start)/2;
        
        if(check(middle))
            start = middle + 1;
        else
            end = middle;
    }
    return start - 1;
}

int main(){
    optimize;
    
    cin >> n >> a >> b;

    cout << binSearch(1, min(a, b) + 1) << "\n";

    return 0;   
}

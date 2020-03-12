#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int n, m, a[101];

bool check(int x){

    if(!x) return true;

    int sum = 0;
    for(int i = 1; i <= 100; i++){
        sum += a[i]/x;
        if(sum >= n) return true;
    }
    return false;
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

    cin >> n >> m;
    
    while(m--){
        int x;
        cin >> x;
        ++a[x];
    }

    cout << binSearch(0, 101) << "\n";

    return 0;   
}

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
#define MAXN 100100

using namespace std;

int n, f;
int m[MAXN];

bool check(int x){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += x/m[i];
        if(sum >= f)
            return true;
    }
    return false;
}

int binSearch(int start, int end){
    while(start < end){
        int middle = start + (end - start)/2;
        
        if(check(middle))
            end = middle;
        else
            start = middle + 1;
    }
    return start;
}

int main(){
    optimize;
    
    cin >> n >> f;
    
    for(int i = 0; i < n; i++)
        cin >> m[i];
    
    cout << binSearch(1, 100000001) << "\n";
    
    return 0;   
}

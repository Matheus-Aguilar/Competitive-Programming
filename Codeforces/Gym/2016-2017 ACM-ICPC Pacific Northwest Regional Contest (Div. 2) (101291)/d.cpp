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

int main(){
    optimize;

    int n, k, r;
    cin >> n >> k >> r;

    vector<int> a(n, 0);

    for(int i = 0; i < k; i++){
        int pos;
        cin >> pos;
        a[pos - 1] = 1;
    }

    int sum = 0, cont = 0;
    deque<int> d;

    for(int i = 0; i < r; i++){
        if(a[i] == 1)
            sum++;
        else
            d.push_back(i);
    }

    while(sum < 2){
        
        a[d.back()] = 1;
        d.pop_back();
        
        sum++;
        cont++;
    }

    for(int i = r; i < n; i++){
        if(d.front() == i - r) 
            d.pop_front();
        sum -= a[i - r];

        if(a[i] == 1)
            sum++;
        else
            d.push_back(i);

        while(sum < 2){
            a[d.back()] = 1;
            d.pop_back();
            
            sum++;
            cont++;
        }
    }

    cout << cont << "\n";
    
    return 0;   
}

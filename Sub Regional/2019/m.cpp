#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int n, c, t;
vector<int> p;

bool check(int x){
    int sum = 0, player = 1;
    for(int i = 0; i < p.size(); i++){
        sum += p[i];
        if(sum > x){
            sum = 0;
            player++;
            i--;
            if(player > c) return false;
        }
    }
    return true;
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

    cin >> n >> c >> t;

    p.resize(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];

    cout << (int)ceil(binSearch(1, 1000000001) / (t * 1.0)) << "\n";

    return 0;   
}

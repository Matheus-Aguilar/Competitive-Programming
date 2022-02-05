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

void solve(vector<int> &a){
    int code = 0;

    for(int i = 0; i < a.size(); i++)
}

int main(){
    optimize;

    for(int i1 = 0; i1 <= 10; i1++){
        for(int i2 = 0; i2 <= 10; i2++){
            for(int i3 = 0; i3 <= 10; i3++){
                for(int i4 = 0; i4 <= 10; i4++){
                    for(int i5 = 0; i5 <= 10; i5++){
                        vector<int> a; 
                        if(i1 != 0) a.push_back(i1);
                        if(i2 != 0) a.push_back(i2);
                        if(i3 != 0) a.push_back(i3);
                        if(i4 != 0) a.push_back(i4);
                        if(i5 != 0) a.push_back(i5);
                        solve(a);
                    }
                }
            }
        }
    }
    
    return 0;   
}

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

bool cmp(int p1, int t1, int x1, int p2, int t2, int x2){
    if(p1 != p2) return p1 > p2;
    if(t1 != t2) return t1 > t2;
    return x1 > x2;
}

int main(){
    optimize;
    
    int n;
    cin >> n;

    int p1 = 0, p2 = 0, t1 = 0, t2 = 0, x1 = 0, x2 = 0;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        if(s == "M")
            continue;
        else if(s == "X"){
            p1 += 10;
            t1++;
            x1++;
        }
        else if(s == "10"){
            p1 += 10;
            t1++;
        }
        else{
            p1 += stoi(s);
        }
    }

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        if(s == "M")
            continue;
        else if(s == "X"){
            p2 += 10;
            t2++;
            x2++;
        }
        else if(s == "10"){
            p2 += 10;
            t2++;
        }
        else{
            p2 += stoi(s);
        }
    }

    if(cmp(p1, t1, x1, p2, t2, x2))
        cout << "Yuju" << "\n";
    else if(cmp(p2, t2, x2, p1, t1, x1))
        cout << "Yerin" << "\n";
    else
        cout << "Shoot-off" << "\n";

    return 0;   
}

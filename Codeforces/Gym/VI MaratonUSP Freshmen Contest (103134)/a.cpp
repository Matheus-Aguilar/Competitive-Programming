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

char kobus[5] = {'k', 'o', 'b', 'u', 's'};

int getPos(char c){
    if(c == kobus[0])
        return 0;
    if(c == kobus[1])
        return 1;
    if(c == kobus[2])
        return 2;
    if(c == kobus[3])
        return 3;
    if(c == kobus[4])
        return 4;
    return (c - 'a') + 5;
}

bool cmp(const string &a, const string &b){
    for(int i = 0; i < a.size() || i < b.size(); i++){
        if(a[i] != b[i]){
            int i1 = getPos(a[i]);
            int i2 = getPos(b[i]);
            return i1 < i2;
        }
    }
    return a.size() < b.size();
}

int main(){
    optimize;

    int n;
    bool ok = true;
    cin >> n;

    vector<string> names(n + 1);

    for(int i = 0; i < n; i++){
        cin >> names[i];
    }

    names[n] = "kobus";

    do{
        sort(all(names), cmp);
        if(names[0] == "kobus"){
            cout << kobus << "acdefghijlmnpqrtvwxyz" << "\n";
            return 0;
        }
    } while(next_permutation(kobus, kobus + 5));
        
    cout <<  "sem chance" << "\n";

    return 0;   
}

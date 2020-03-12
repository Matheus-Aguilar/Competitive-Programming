#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int a, b, p;
string s;
int bus[100000];
int tram[100000];
int n;

bool check(int x){

    int money = p;

    while(money >= 0){
        if(x >= n - 1) return true;

        if(s[x] == 'A'){
            money -= a;
            x = bus[x];
        }
        else{
            money -= b;
            x = tram[x];
        }
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

void precalc(){

    int next = n - 1;

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'A')
            bus[i] = next;
        else
            next = i;
    }

    next = n - 1;

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'B')
            tram[i] = next;
        else
            next = i;
    }
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        cin >> a >> b >> p;
        cin >> s;
        n = s.size();
        precalc();
        cout << binSearch(0, n) + 1 << "\n";
    }

    return 0;   
}

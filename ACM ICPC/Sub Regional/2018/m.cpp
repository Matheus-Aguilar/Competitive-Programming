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

#define MAXN 2001

int n, m;
bitset<MAXN> A[MAXN];
int B[MAXN];
bitset<MAXN> x;
bool notFree[MAXN];

bool valid(char c){
    return c == ' ' || isdigit(c);
}

bool countNot(const std::string& referenceString) {

    string subString = "not";

    const size_t step = subString.size();

    size_t count(0);
    size_t pos(0) ;

    while( (pos=referenceString.find(subString, pos)) !=std::string::npos) {
        pos +=step;
        ++count ;
    }

    return !(count & 1);
}

void sanitize(string &s){
    string s2 = "";
    for(int i = 0; i < s.size(); i++){
        if(valid(s[i]))
            s2 += s[i];
    }
    s = s2;
}

void parse(stringstream &ss, int i){
    int x;
    while(ss >> x){
        A[i][x - 1] = (A[i][x - 1] ^ 1);
        notFree[x - 1] = true;
    }
}

//XOR-SAT do Macacario do ITA
bool gaussxor(){
    int cnt = 0;
    bitset<MAXN> vis; vis.set();
    for(int j = m - 1, i; j >= 0; j--){
        for(i = cnt; i < n; i++){
            if(A[i][j]) break;
        }
        if(i == n) continue;
        swap(A[i], A[cnt]); swap(B[i], B[cnt]);
        i = cnt++; vis[j] = 0;
        for(int k = 0; k < n; k++){
            if(i == k || !A[k][j]) continue;
            A[k] ^= A[i]; B[k] ^= B[i];
        }
    }

    x = vis;
    for(int i = 0; i < n; i++){
        int acum = 0;
        for(int j = 0; j < m; j++){
            if(!A[i][j]) continue;
            if(!vis[j]){
                vis[j] = 1;
                x[j] = acum^B[i];
            }
            acum ^= x[j];
        }
        if(acum != B[i]) return false;
    }
    return true;
}

int main(){
    optimize;
    
    cin >> n >> m;
    cin.ignore();

    for(int i = 0; i < n; i++){
        stringstream ss;
        string s;
        getline(cin, s);
        B[i] = countNot(s);
        sanitize(s);
        ss << s;
        parse(ss, i);
    }

    if(gaussxor()){
        for(int i = 0; i < m; i++){
            if(notFree[i])
                cout << (x[i] ? "T" : "F");
            else
                cout << "T";
        }
        cout << "\n";
    }
    else{
        cout << "impossible" << "\n";
    }

    return 0;   
}

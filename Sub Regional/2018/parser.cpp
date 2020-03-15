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
        A[i][m - x] = (A[i][m - x] ^ 1);
        notFree[x - 1] = true;
    }
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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << A[i][j] << " ";
        }
        cout << "= " << B[i] << "\n";
    }

    return 0;   
}

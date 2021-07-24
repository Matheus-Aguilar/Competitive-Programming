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

int getVal(char c){
    return c - '0';
}

char getDigit(int v){
    return v + '0';
}

struct BigInt{
    string d;

    BigInt() {}

    BigInt(const string &s){
        d = s;
        reverse(all(d));
        fix();
    }

    void fix(){
        while(!d.empty() && d.back() == '0')
            d.pop_back();
        if(d.empty()) d.push_back('0');
    }

    BigInt & operator=(const BigInt &b){
        d = b.d;
    }

    BigInt & operator+=(const BigInt &b){
        
        int carry = 0;

        while(d.size() < b.d.size()){
            d.push_back('0');
        }

        int i;

        for(i = 0; i < d.size(); i++){
            
            int val = getVal(d[i]) + carry;
            if(i < b.d.size()) val += getVal(b.d[i]);
            
            carry = 0;

            if(val >= 10){
                carry = 1;
                val -= 10;
            }

            d[i] = getDigit(val);
        }

        if(carry == 1){
            d.push_back('1');
            carry = 0;
        }
    }

    bool operator<(const BigInt &b) const{
        if(d.size() != b.d.size()) 
            return d.size() < b.d.size();
        
        for(int i = d.size() - 1; i > 0; i--){ 
            if(d[i] != b.d[i]){
                return d[i] < b.d[i];
            }
        }

        return d[0] < b.d[0];
    }

    bool operator==(const BigInt &b) const{
        return !(*this < b || b < *this);
    }

    bool operator<=(const BigInt &b) const{
        return *this < b || *this == b;
    }
};

int main(){
    optimize;
    
    int n;
    string str;
    BigInt s, sum("0");

    cin >> n >> str;

    vector<pair<BigInt, string>> p(n);
    vector<string> ans;

    s = BigInt(str);

    for(int i = 0; i < n; i++){
        cin >> p[i].second >> str;
        p[i].first = BigInt(str);
    }

    sort(all(p));
    reverse(all(p));

    for(int i = 0; i < n; i++){
        
        BigInt aux = sum;
        aux += p[i].first;
        
        if(aux <= s){
            sum = aux;
            ans.push_back(p[i].second);
        }
    }

    if(sum == s){
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n";
    }
    else{
        cout << 0 << "\n";
    }
    
    return 0;   
}

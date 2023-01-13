#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

string add(string &s1, string &s2){
    
    string sum = "";
    int carry = 0;
    
    for(int i = s1.size() - 1, j = s2.size() - 1; i >= 0 || j >= 0; i--, j--){
        
        int d1 = (i >= 0 ? s1[i] - '0' : 0);
        int d2 = (j >= 0 ? s2[j] - '0' : 0);
        int d = d1 + d2 + carry;
        
        if(d >= 10){
            carry = 1;
            d -= 10;
        } else {
            carry = 0;
        }
        
        sum += (d + '0');
    }
    
    if(carry > 0)
        sum += '1';
    
    reverse(sum.begin(), sum.end());
    
    return sum;
}

string multOneDigit(string &s, char digit){
    string mult = "";
    int carry = 0;
    
    for(int i = s.size() - 1; i >= 0; i--){
        int d = (s[i] - '0') * (digit - '0') + carry;
        
        if(d >= 10){
            carry = d / 10;
            d %= 10;
        } else {
            carry = 0;
        }
        
        mult += (d + '0');
    }
    
    if(carry > 0)
        mult += (carry + '0');
    
    reverse(mult.begin(), mult.end());
    
    return mult;
}

string multiply(string &s1, string &s2){
    string ans = "0";
    
    for(int i = 0; i < s2.size(); i++){
        string mult = multOneDigit(s1, s2[i]);
        mult += string(s2.size() - i - 1, '0');
        ans = add(ans, mult);
    }
    
    return ans;
}

void extraLongFactorials(int n) {
    string ans = "1";
    
    for(int i = 2; i <= n; i++){
        string term = to_string(i);
        ans = multiply(ans, term);
    }
    
    cout << ans << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

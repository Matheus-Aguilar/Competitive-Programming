#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    
    string t = "";
    
    for(int i = 0; i < s.size(); i++)
        if(s[i] != ' ')
            t += s[i];
    
    int n = t.size();
    int r = sqrt(n);
    
    int rows = r, cols = r;
    
    if(rows * cols < n)
        cols++;
    if(rows * cols < n)
        rows++;
    
    string ans = "";
    
    for(int j = 0; j < cols; j++){
        for(int i = 0; i < rows; i++){
            if(i * cols + j < n)
                ans += t[i * cols + j];
        }
        ans += ' ';
    }
    
    ans.pop_back();
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {
    
    int pos = -1;
    
    for(int i = (int) w.size() - 2; i >= 0; i--){
        if(w[i] < w[i + 1]){
            pos = i;
            break;
        }
    }
    
    if(pos == -1)
        return "no answer";
        
    int pos2 = -1;
    
    for(int i = (int) w.size() - 1; i > pos; i--){
        if(w[pos] < w[i]){
            pos2 = i;
            break;
        }
    }
    
    swap(w[pos], w[pos2]);
    reverse(w.begin() + pos + 1, w.end());
    
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

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

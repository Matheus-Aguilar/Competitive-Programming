#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;

void add_to_output(string &output, char c, const string &s){
    
    output += "[ ";
    output += c;
    output += ' ';

    for(int i = 0; i < (int)s.size(); i++){
        output += s[i];
        output += " ";
    }

    output += "]\n";
}

int main (int argc, char const *argv [])
{
    string text, output;

    cin >> text;

    string u = text;

    sort(all(u));
    u.erase(unique(all(u)), u.end());

    vector<int> cont(u.size(), 0);
    vector<vector<string>> ans(u.size());

    #pragma omp parallel for
    for(int i = 0; i < (int)u.size(); i++){

        string perm = text;
        perm.erase(perm.find(u[i]), 1);

        do{
            ans[i].emplace_back(perm);
            cont[i]++;
        } while(next_permutation(all(perm)));
    }
    
    for(int i = 0; i < (int)u.size(); i++){
        for(int j = 0; j < cont[i]; j++){
            add_to_output(output, u[i], ans[i][j]);
        }
    }

    cout << output << "\n";

    return 0 ;
}

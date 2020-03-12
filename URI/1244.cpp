#include<bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b){
    return a.size() > b.size();
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string line;
        stringstream ss;
        getline(cin, line);

        ss << line;

        vector<string>words;
        string word;
        while(ss >> word)
            words.push_back(word);
        stable_sort(words.begin(), words.end(), cmp);
        
        for(int i = 0; i < words.size() - 1; i++){
            cout << words[i] << " ";
        }
        cout << words.back() << "\n";
    }
}
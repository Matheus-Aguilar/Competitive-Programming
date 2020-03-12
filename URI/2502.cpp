#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, c;
    while(cin >> c >> n){
        string s1, s2;
        unsigned char ascii[256];
        iota(ascii, ascii + 256, 0);
        
        cin.ignore();

        getline(cin, s1);
        getline(cin, s2);
        for(int i = 0; i < s1.size(); i++){
            if(isalpha(s1[i]) && isalpha(s2[i])){
                swap(ascii[tolower(s1[i])], ascii[tolower(s2[i])]);
                swap(ascii[toupper(s1[i])], ascii[toupper(s2[i])]);
            }
            else if(isalpha(s1[i])){
                ascii[tolower(s1[i])] = ascii[toupper(s1[i])] = s2[i];
                ascii[s2[i]] = tolower(s1[i]);
            }
            else if(isalpha(s2[i])){
                ascii[tolower(s2[i])] = ascii[toupper(s2[i])] = s1[i];
                ascii[s1[i]] = tolower(s2[i]);
            }
            else{
                swap(ascii[s1[i]], ascii[s2[i]]);
            }
        }
        while(n--){
            string s3;
            getline(cin, s3);
            for(int i = 0; i < s3.size(); i++)
                cout << ascii[s3[i]];
            cout << "\n";
        }
        cout << "\n";
    }
}
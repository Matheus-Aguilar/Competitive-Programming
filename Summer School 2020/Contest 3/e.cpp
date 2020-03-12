#include<bits/stdc++.h>
#define optimize ios_base:sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, rotated;
        cin >> s;
        int size = sqrt(s.size());
        rotated = s;
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                rotated[(size - j - 1) * size + i] = s[i * size + j];
        cout << rotated << "\n";
    }
}
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

int main(){
    optimize;

    int n, errors = 0;
    vector<int> pos;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    n = s1.size();
    
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i] && s1[i] != s3[i] && s2[i] != s3[i]){
            pos.push_back(i);
            errors += 2;
        }
        else if(s1[i] != s2[i] || s1[i] != s3[i]){
            pos.push_back(i);
            errors++;
        }
    }

    if(errors > 3){
        cout << "Impossible" << "\n";
    }
    else if(pos.size() == 3){
        int miss[3];
        for(int i = 0; i < 3; i++){
            if(s1[pos[i]] == s2[pos[i]])
                miss[i] = 3;
            else if(s1[pos[i]] == s3[pos[i]])
                miss[i] = 2;
            else
                miss[i] = 1;    
        }

        if(miss[0] != miss[1] && miss[0] != miss[2] && miss[1] != miss[2]){
            string s = s1;
            for(int i = 0; i < 3; i++)
                if(miss[i] == 1)
                    s[pos[i]] = s2[pos[i]];
            cout << s << "\n";
        }
        else{
            cout << "Impossible" << "\n";
        }
    }
    else if(pos.size() == 2){
        
        int j = pos[0], k = pos[1];
        
        if(s1[j] != s2[j] && s1[j] != s3[j] && s2[j] != s3[j]){
            string s = s1;

            if(s1[k] == s2[k])
                s[j] = s3[j];
            else if(s1[k] == s3[k])
                s[j] = s2[j];
            else
                s[k] = s2[k];

            cout << s << "\n";
        }
        else if(s1[k] != s2[k] && s1[k] != s3[k] && s2[k] != s3[k]){
            string s = s1;

            if(s1[j] == s2[j])
                s[k] = s3[k];
            else if(s1[j] == s3[j])
                s[k] = s2[k];
            else
                s[j] = s2[j];

            cout << s << "\n";
        }
        else{
            int miss[2];
            for(int i = 0; i < 2; i++){
                if(s1[pos[i]] == s2[pos[i]])
                    miss[i] = 3;
                else if(s1[pos[i]] == s3[pos[i]])
                    miss[i] = 2;
                else
                    miss[i] = 1;    
            }

            if(miss[0] == miss[1])
                cout << "Ambiguous" << "\n";
            else{
                string s = s1;

                if(miss[0] == 1)
                    s[j] = s2[j];
                if(miss[1] == 1)
                    s[k] = s2[k];

                cout << s << "\n";
            }
        }
    }
    else{
        cout << "Ambiguous" << "\n";
    }

    return 0;   
}

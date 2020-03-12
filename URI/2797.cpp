#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
    vector<vector<int>>v(n, vector<int>(m));
    vector<bool>hasStudent(m, false);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &v[i][j]);
            hasStudent[j] = hasStudent[j] || (bool)v[i][j];
        }
    }

    for(int j = 0; j < m; j++){
        if(j && hasStudent[j - 1] && hasStudent[j]){
            cout << "N\n";
            return 0;
        }

        int type1 = -1, type2 = -1;

        for(int i = 0; i < n; i++){
            if(v[i][j] == 1){
                if(type1 != -1){
                    if(i - type1 <= c){
                        cout << "N\n";
                        return 0;
                    }
                }
                type1 = i;
            }
            else if(v[i][j] == 2){
                if(type2 != -1){
                    if(i - type2 <= c){
                        cout << "N\n";
                        return 0;
                    }
                }
                type2 = i;
            }
        }
    }

    cout << "S\n";
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    int l;
    char c;
    int cl, cc2, c2;
    char cc;    
    int t = 0;
    while(scanf("%d%c", &cl, &cc) == 2){
        if(!cl) return 0;
        vector<vector<bool>>board(8, vector<bool>(8, true));
        for(int i = 1; i <= 8; i++){
            scanf("%d%c", &l, &c);
            --l;
            c2 = (int)(c - 'a');
            if(l > 0){
                if(c2 > 0)
                    board[l - 1][c2 - 1] = false;
                if(c2 < 7)
                    board[l - 1][c2 + 1] = false;
            }
        }

        --cl;
        cc2 = (int)(cc - 'a');

        int res = 0;

        if(cl > 1){
            if(cc2 > 0)
                res += (int)board[cl - 2][cc2 - 1];
            if(cc2 < 7)
                res += (int)board[cl - 2][cc2 + 1];
        }
        //cerr << res << endl;
        if(cl < 6){
            if(cc2 > 0)
                res += (int)board[cl + 2][cc2 - 1];
            if(cc2 < 7)
                res += (int)board[cl + 2][cc2 + 1];
        }
        //cerr << res << endl;
        if(cc2 > 1){
            if(cl > 0)
                res += (int)board[cl - 1][cc2 - 2];
            if(cl < 7)
                res += (int)board[cl + 1][cc2 - 2];
        }
        //cerr << res << endl;
        if(cc2 < 6){
            if(cl > 0)
                res += (int)board[cl - 1][cc2 + 2];
            if(cl < 7)
                res += (int)board[cl + 1][cc2 + 2];
        }
        //cerr << res << endl;
        
        printf("Caso de Teste #%d: %d movimento(s).\n", ++t, res);
    }
}
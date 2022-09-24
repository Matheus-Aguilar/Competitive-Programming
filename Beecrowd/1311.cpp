#include<bits/stdc++.h>

using namespace std;

struct soldier{
    int left, right;
    int v;
    soldier(int l = -1, int r = -1, int v_ = 0) : left(l), right(r), v(v_){}
};

int main(){
    int n, b;
    while(scanf("%d%d", &n, &b) == 2){
        if(n == 0 && b == 0) return 0;
        vector <soldier> army(n);

        if(army.size() == 1){
            army[0] = soldier(-1, -1, 1);
        }
        else{
            army[0] = soldier(-1, 1, 1);
            for(int i = 2; i < n; i++)
                army[i - 1] = soldier(i - 2, i, i);
            army[n - 1] = soldier(n - 2, -1, n); 
        }
        while(b--){
            int l, r;
            scanf("%d%d", &l, &r);
            //cin >> l >> r;
            int left, right;
            left = army[l - 1].left;
            right = army[r - 1].right;

            if(left != -1) cout << army[left].v << " ";
            else cout << "* ";

            if(right != -1) cout << army[right].v << "\n";
            else cout << "*\n";

            if(left != -1)
                army[left].right = right;
            if(right != -1)
                army[right].left = left;
        }
        cout << "-\n";
    }
}
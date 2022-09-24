#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int>v(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        int elem;
        int pos;
        int d = 2;
        scanf("%d", &elem);
        for(int i = 0; i < n; i++){
            if(elem == v[i]){
                pos = i + 1;
                break;
            }
        }

        while(pos >= d){
            if(pos % d == 0){
                cout << "N\n";
                goto fim;
            }
            pos -= pos/d;
            d++;
        }
        cout << "Y\n";
        fim:
        int aas = 0;
    }
}
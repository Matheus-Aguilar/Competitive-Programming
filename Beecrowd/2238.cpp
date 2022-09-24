#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int root = ceil(sqrt(c/a));
    int ca = c/a;

    if(c % a != 0){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= root; i++){
        //cerr << i << " " << a * i << " " << a * i % b << " " << d % (i * a) << endl; 
        if(ca % i == 0 && a * i % b != 0 && d % (i * a) != 0){
            cout << a * i << endl;
            return 0;
        }
    }

    for(int i = root; i >= 1; i--){

        int comp = ca/i;

        //cerr << comp << " " << a * comp << " " << a * comp % b << " " << d % (comp * a) << endl;

        if(ca % comp == 0 && a * comp % b != 0 && d % (comp * a) != 0){
            cout << a * comp << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
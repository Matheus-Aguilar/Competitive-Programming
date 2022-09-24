#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(!n) break;
        int start = 1;
        int tab = ceil((n - 1) * log10(4));

        for(int i = 0; i < n; i++){
            int now = start;
            for(int j = 0; j < n - 1; j++){
                cout << setw(tab) << now << " ";
                now *= 2; 
            }
            cout << setw(tab) << now << "\n";
            start *= 2;
        }
        cout << "\n";
    }
}
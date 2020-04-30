#include<iostream>
#include<ctime>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int main(int agrc, char **argv){
    optimize;

    srand(time(NULL));

    int t = atoi(argv[1]);
    
    cout << t << "\n";

    while(t--){
        int r = rand() % 10 + 1;
        int c = rand() % 5 + 1;

        cout << r << " " << c << "\n";

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << rand() % 1000000 + 1 << " ";
            }
            cout << "\n";
        }
    }

    return 0;   
}

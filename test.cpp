#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    srand(time(0));

    int p = atoi(argv[1]);
    cout << p << "\n";
    for(int i = 0; i < p; i++){
        int q = rand()%1000 + 1;
        if(i == p - 1) q = 9997;
        if(q % 2 == 0) q++;
        if((q/2 + 1)%10==0) q += 2;
        cout << i + 1 << " " << q << "\n";
        for(int j = 0; j < q; j++){
            int aux = (rand()%100000 + 1) * (rand()%2==0?1:-1);
            if((j + 1)%10 == 0 || j == q - 1)
                cout << aux << "\n";
            else
                cout << aux << " ";
        }
    }
}
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    srand(time(0));
    
    int n =  atoi(argv[1]);
    int cont = 0;
    int wins[3] = {0};

    while(cont++ != n){
        int a1, a2, a3, r;
        a1 = a2 = a3 = rand() % 3;
        r = rand() % 3;
        set <int> l;
        l.insert(0); l.insert(1); l.insert(2);
        
        if(a1 == r){
            l.erase(r);
            if(rand()%2 == 0){
                a3 = a2 = *(l.begin());
                if(rand()%2 == 0)
                    a3 = a2 = *(++l.begin());
            }
            else{
                a3 = *(l.begin());
                if(rand()%2 == 0)
                    a3 = *(++l.begin());
            }
        }
        else{
            l.erase(a1);
            if(rand()%2 == 0){
                a3 = a2 = r;
            }
            else{
                a3 = r;
            }
        }

        if(a1 == r)
            wins[0]++;
        if(a2 == r)
            wins[1]++;
        if(a3 == r)
            wins[2]++;
    }

    cout << "A1: " << fixed << setprecision(2) << wins[0]/(1.0 * cont) << "%\n";
    cout << "A2: " << fixed << setprecision(2) << wins[1]/(1.0 * cont) << "%\n";
    cout << "A3: " << fixed << setprecision(2) << wins[2]/(1.0 * cont) << "%\n";    
}
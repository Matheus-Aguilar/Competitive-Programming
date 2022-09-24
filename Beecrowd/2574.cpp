#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n, g;
    cin >> n >> g;
    vector<int>v(n * n);
    for(long long int i = 0; i < n * n; i++){
        //v[i] = 1;
        scanf("%li", &v[i]); //Coisa magica que faz a questao passar no tempo S2
    }

    long long int t = 1;
    bool deubom = false;
    long long int a = 0;
    while(!deubom){
        deubom = true;
        if(t == 1){
            for(long long int i = 0; i < n * n; i++){
                a++;
                if(g > v[i]){
                    deubom = false;
                    //cerr << "falsou2\n";
                }
            }       
        }
        else{
            long long int k = 0;
            for(long long int i = 0; i < n/(t/2); i += 2){
                for(long long int j = 0; j < n/(t/2); j += 2){
                    //cout << i * n/(t/2) + j << " " << i * n/(t/2) + n/(t/2) + j << " " << i * n/(t/2) + j + 1 << " " << i * n/(t/2) + n/(t/2) + j + 1 << " " << k<< endl; 
                    v[k++] = v[i * n/(t/2) + j] + v[i * n/(t/2) + n/(t/2) + j] + v[i * n/(t/2) + j + 1] + v[i * n/(t/2) + n/(t/2) + j + 1];
                    //cout << g << "--" << v[k-1] << "--" << k -1 << " " << deubom << endl;
                    a++;
                    if(g > v[k - 1]){
                        deubom = false;
                        //cerr << "falsou\n";
                    }
                }
            }

            // // cerr << t << " " << n << endl;
            // for(long long int i = 0; i < n/(t); i += 1){
            // for(long long int j = 0; j < n/(t); j += 1){
            //         cout << v[i * n/t + j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
        //cerr << t << " hhh\n" << endl;
        t *= 2;
        //if(deubom) break;
    }
    t /= 2;

    cout << (n * n)/(t * t) << endl;
}
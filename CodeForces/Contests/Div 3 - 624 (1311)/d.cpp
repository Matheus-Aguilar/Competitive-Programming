#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int a, b, c;

int calc(int A, int B, int C){
    return abs(A - a) + abs(B - b) + abs(C - c);
}

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;

        int bestAns = INF, bestA, bestB, bestC;

        for(int i = 1; i <= b + c; i++){
            int A, B, C, ans = INF;
            for(int j = i; j <= b + c; j += i){
                
                if(calc(i, j, c/j * j) < calc(i, j, c/j * j + j)){
                    ans = calc(i, j, c/j * j);
                    A = i;
                    B = j;
                    C = c/j * j;
                }
                else{
                    ans = calc(i, j, c/j * j + j);
                    A = i;
                    B = j;
                    C = c/j * j + j;
                }

                if(ans < bestAns){
                    bestAns = ans;
                    bestA = A;
                    bestB = B;
                    bestC = C;
                }
            }
        }

        cout << bestAns << "\n" << bestA << " " << bestB << " " << bestC << "\n";
    }
    return 0;   
}

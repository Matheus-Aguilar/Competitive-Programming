#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 100100

using namespace std;

int n;
int arr[MAXN];
int cont[27];

int solve(int a, int b){
    int best = cont[b], i = 0, j = n - 1, now = cont[b];
    while(i < j){
        if(arr[i] == a && arr[j] == a){
            i++, j--;
            now += 2;
            best = max(best, now);
        }
        else if(arr[i] == a){
            while(arr[j] != a && i < j){
                if(arr[j] == b) now--;
                j--;
            }
        }
        else if(arr[j] == a){
            while(arr[i] != a && i < j){
                if(arr[i] == b) now--;
                i++;
            }
        }
        else{
            if(arr[i] == b) now--;
            if(arr[j] == b) now--;
            i++, j--;
        }
    }
    return best;
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ms(cont, 0);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            cont[arr[i]]++;
        }
        
        int best = 0;
        
        for(int i = 1; i <= 26; i++){
            for(int j = 1; j <= 26; j++){
                if(i == j) continue;
                best = max(best, solve(i, j));
            }
        }

        cout << best << "\n";
    }
    
    return 0;   
}

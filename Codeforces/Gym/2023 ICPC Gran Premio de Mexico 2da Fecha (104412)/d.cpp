#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 1001000

using namespace std;

int m, n;
int a[MAXN], b[MAXN];

int lps[MAXN], cnt = 0;

void kmp(){
    memset(lps, -1, sizeof(lps));

    int i = 0, j = -1;
    
    while(i < m){
        while(j >= 0 && a[i] != a[j]){
            j = lps[j];
        }
        lps[++i] = ++j;
    }

    i = 0, j = 0;

    while(i < n){
        
        while(j >= 0 && b[i] != a[j]){
            j = lps[j];
        }

        i++;
        j++;

        if(j == m){
            cnt++;
            j = lps[j];
        }
    }
}

int main(){

    optimize;

    cin >> m >> n;

    for(int i = 0; i < m; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++)
        cin >> b[i];

    if(m > n){
        cout << 0 << "\n";
        return 0;
    }

    if(m == 1){
        cout << n << "\n";
        return 0;
    }

    for(int i = 0; i < m - 1; i++){
        a[i] = a[i] - a[i + 1];
    }

    for(int i = 0; i < n - 1; i++){
        b[i] = b[i] - b[i + 1];
    }

    m--;
    n--;

    kmp();

    cout << cnt << "\n";

    return 0;
}
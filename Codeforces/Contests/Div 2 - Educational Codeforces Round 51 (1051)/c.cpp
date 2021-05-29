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

using namespace std;

int freq[101];
int nums[101];

int main(){
    optimize;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        freq[nums[i]]++;
    }

    int nice = 0;
    int fix = -1;

    for(int i = 1; i <= 100; i++){
        if(freq[i] == 1)
            nice++;
        if(freq[i] >= 3)
            fix = i;
    }

    if(nice % 2 == 0 || fix != -1){

        cout << "YES" << "\n";
        
        int niceFound = 0;

        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == 1){
                cout << (niceFound < nice/2 ? 'B' : 'A');
                niceFound++;
            }
            else if(nice % 2 != 0 && fix == nums[i]){
                cout << 'B';
                fix = -1;
            }
            else{
                cout << 'A';
            }
        }
        cout << "\n";
    }
    else{
        cout << "NO" << "\n";
    }

    return 0;   
}

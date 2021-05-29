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

int main(){
    //optimize;

    int m1, m2, m3, m4;
    cout << "? 1 2" << endl;
    cin >> m1;
    cout << "? 2 3" << endl;
    cin >> m2;
    cout << "? 4 5" << endl;
    cin >> m3;
    cout << "? 5 6" << endl;
    cin >> m4;
    int a[] = {4, 8, 15, 16, 23, 42};
    do{
        if(a[0] * a[1] == m1 && a[1] * a[2] == m2 && a[3] * a[4] == m3 && a[4] * a[5] == m4){
            cout << "! " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << endl;
            break;
        }
    } while(next_permutation(a, a + 6));

    return 0;   
}

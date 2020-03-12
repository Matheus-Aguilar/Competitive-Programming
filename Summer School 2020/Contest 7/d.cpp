#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main(){
    optimize;
    
    int a[4], b[4];

    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> b[0] >> b[1] >> b[2] >> b[3];

    int A = accumulate(a, a + 4, 0);
    int B = accumulate(b, b + 4, 0);

    if(A > B)
        cout << "Gunnar" << "\n";
    else if(B > A)
        cout << "Emma" << "\n";
    else
        cout << "Tie" << "\n"; 

    return 0;
}

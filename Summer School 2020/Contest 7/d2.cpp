#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main(){
    optimize;
    
    int g = 0, e = 0;

    int a[4], b[4];

    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> b[0] >> b[1] >> b[2] >> b[3];

    for(int i = a[0]; i <= a[1]; i++)
        for(int j = a[2]; j <= a[3]; j++)
            for(int k = b[0]; k <= b[1]; k++)
                for(int l = b[2]; l <= b[3]; l++)
                    if(i + j > k + l) g++;
                    else if(i + j < k + l) e++;

    if(g > e)
        cout << "Gunnar" << "\n";
    else if(e > g)
        cout << "Emma" << "\n";
    else
        cout << "Tie" << "\n"; 

    return 0;
}

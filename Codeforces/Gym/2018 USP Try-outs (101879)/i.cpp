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

//n pecas vao de a para c, com b como auxiliar

void hanoi(int n, char a, char b, char c, bool &special, bool odd){
    if(n == 1){
        if(special){
            special = false;

            if(odd)
                cout << 'B' << " " << 'C' << "\n";
            else
                cout << 'C' << " " << 'B' << "\n";
        }
        else{
            cout << a << " " << c << "\n";
        }
    }
    else{
        hanoi(n - 1, a, c, b, special, odd);
        cout << a << " " << c << "\n";
        hanoi(n - 1, b, a, c, special, odd);
    }
}

int main(){
    optimize;

    int n, k, moves;
    bool special = false, odd;

    cin >> n >> k;

    moves = (1 << n) - 1;
    odd = n % 2;

    if(k < moves)
        cout << "N" << "\n";
    else{

        cout << "Y" << "\n";

        while(k - 1 > moves){
            cout << 'A' << " " << 'B' << "\n";
            cout << 'B' << " " << 'A' << "\n";
            k -= 2;
        }

        if(k > moves){

            special = true;

            if(odd)
                cout << 'A' << " " << 'B' << "\n";
            else
                cout << 'A' << " " << 'C' << "\n";
        }

        hanoi(n, 'A', 'B', 'C', special, odd);

        k -= (1 << n) - 1;
    }

    return 0;   
}

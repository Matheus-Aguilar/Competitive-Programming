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
#define MAXN 1000100

using namespace std;

char a[MAXN], b[MAXN];

bool check(){
    bool A = false, B = false;
    for(int i = 0; a[i] && (!A || !B); i++)
        A |= (bool)(a[i] == '1'), B |= (bool)(b[i] == '1');
    return A == B;
}

int main(){
    //optimize;

    scanf("%s", &a);
    scanf("%s", &b);

    printf("%s\n", (strlen(a) == strlen(b) && check() ? "YES" : "NO"));
    

    return 0;   
}

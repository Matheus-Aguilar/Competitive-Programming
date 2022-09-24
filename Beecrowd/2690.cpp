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

char code[52];
char words[10][7] = {"GQaku", "ISblv", "EOYcmw", "FPZdnx", "JTeoy", "DNXfpz", "AKUgq", "CMWhr", "BLVis", "HRjt"};

int m(char c){
    if(c >= 'a' && c <= 'z')
        return c - 'a';
    return (c - 'A') + 26;
}

void preCalc(){
    for(int i = 0; i < 10; i++)
        for(int j = 0; words[i][j]; j++)
            code[m(words[i][j])] = (i + '0');    
}

int main(){
    //optimize;

    preCalc();

    int n;
    scanf("%d", &n);

    char s[40], t[40];

    while(n--){
        
        scanf(" %[^\n]", s);

        int i, j;

        for(i = 0, j = 0; s[i] && j < 12; i++)
            if(s[i] != ' ')
                t[j++] = code[m(s[i])];
        
        t[j] = '\0';

        printf("%s\n", t);
    }

    return 0;   
}

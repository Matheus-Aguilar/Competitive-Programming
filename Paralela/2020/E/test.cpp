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
#define MAX 10000

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int agrc, char **argv){
    optimize;

    int n = atoi(argv[1]);
    
    ifstream file("primes.txt");

    vector<string> s1(n), s2(n), s(n);
    vector<int> primes(MAX);
    for(int i = 0; i < MAX; i++){
        file >> primes[i];
    }
    
    for(int i = 0; i < n; i++){
        s[i] = to_string(primes[4 + rng() % (MAX - 4)]);
        int pos = rng() % (s[i].size() - 1);
        s1[i] = s[i].substr(0, pos + 1);
        s2[i] = s[i].substr(pos + 1, s[i].size() - pos - 1);
    }

    shuffle(all(s1), rng);
    shuffle(all(s2), rng);

    cout << n << "\n";

    for(int i = 0; i < n; i++)
        cout << s1[i] << "\n";
    
    for(int i = 0; i < n; i++)
        cout << s2[i] << "\n";

    return 0;   
}

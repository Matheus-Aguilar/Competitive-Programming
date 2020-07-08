#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>
#define MAXN 1000000

using namespace std;

int n, k;
pii freq[MAXN];

bool check(int x){
    int sum = 0;
    for(int i = 0; freq[i].first/x; i++){
        sum += freq[i].first/x;
        if(sum >= k) return true;
    }
    return false;
}

int binSearch(int start, int end){
    while(start < end){
        int middle = start + (end - start)/2;

        if(check(middle))
            start = middle + 1;
        else
            end = middle;
    }

    return start - 1;
}

int main(){
    optimize;

    cin >> n >> k;

    for(int i = 0; i < MAXN; i++){
        freq[i].first = 0;
        freq[i].second = i;
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x].first++;
    }

    sort(freq, freq + MAXN, greater<pii>());

    int best = binSearch(1, n + 1);

    int total = 0;

    for(int i = 0; freq[i].first/best; i++){
        int copies = freq[i].first/best;
        for(int j = 0; j < copies; j++){
            cout << freq[i].second << " ";
            total++;
            if(total == k){
                cout << "\n";
                return 0;
            }
        }
    }

    return 0;   
}

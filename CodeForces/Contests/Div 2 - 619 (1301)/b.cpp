#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int maxK, minK;

bool check(int m, vector<int> &a){
    
    maxK = INF, minK = 0;
    
    for(int i = 0; i < a.size() - 1; i++){
        if(a[i] != -1 && a[i + 1] != -1){
            if(abs(a[i] - a[i + 1]) > m){
                return false;
            }
        }
        else if(a[i + 1] != -1){
            maxK = min(INF, min(maxK, a[i + 1] + m));
            minK = max(0, max(minK, a[i + 1] - m));
        }
        else if(a[i] != -1){
            maxK = min(INF, min(maxK, a[i] + m));
            minK = max(0, max(minK, a[i] - m));
        }

        if(minK > maxK) return false;
    }
    return true;
}

int binSearch(int start, int end, vector<int> &a){
    while(start < end){
        int middle = start + (end - start)/2;

        if(check(middle, a))
            end = middle;
        else
            start = middle + 1;
    }
    return start;
}

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int m = binSearch(0, INF + 1, a);

        check(m, a);

        cout << m << " " << minK << "\n";
    }

    return 0;   
}

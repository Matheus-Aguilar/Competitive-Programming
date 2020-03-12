#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAXN 1010

using namespace std;

int dist[MAXN][MAXN];
pair<int, int> cars[MAXN];
pair<int, int> candidates[2 * MAXN];

int n, h, w, nBrute;

int manhattan(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void bfs(){
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        dist[cars[i].first][cars[i].second] = 0;
        q.push(cars[i]);
    }

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        if(cur.first > 0 && dist[cur.first - 1][cur.second] == -1){
            dist[cur.first - 1][cur.second] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(cur.first - 1,cur.second));
        }
        if(cur.second > 0 && dist[cur.first][cur.second - 1] == -1){
            dist[cur.first][cur.second - 1] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(cur.first,cur.second - 1));
        }
        if(cur.first < h - 1 && dist[cur.first + 1][cur.second] == -1){
            dist[cur.first + 1][cur.second] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(cur.first + 1,cur.second));
        }
        if(cur.second < w - 1 && dist[cur.first][cur.second + 1] == -1){
            dist[cur.first][cur.second + 1] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(cur.first,cur.second + 1));
        }
    }
}

bool bruteForce(int x){
    for(int i = 0; i < nBrute; i++)
        for(int j = i + 1; j < nBrute; j++)
            if(manhattan(candidates[i], candidates[j]) >= x)
                return true;
    return false;
}

bool check(int x){

    nBrute = 0;

    for(int j = 0; j < w; j++){
        int low = MAXN + 1, high = -1;
        for(int i = 0; i < h; i++){
            if(dist[i][j] >= x){
                low = min(i, low);
                high = max(i, high);
            }
        }

        if(low != MAXN + 1) candidates[nBrute++] = make_pair(low, j);
        if(high != -1 && low != high) candidates[nBrute++] = make_pair(high, j);
    }

    return bruteForce(x);
}

int binarySearch(int start, int end){
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
    int t;
    cin >> t;
    while(t--){
        cin >> n >> w >> h;

        if(!n){
            cout << h + w - 2 << endl;
            continue;
        }

        for(int i = 0; i < h; i++)
            fill(dist[i], dist[i] + w, -1);
        for(int i = 0; i < n; i++)
            cin >> cars[i].second >> cars[i].first;
        bfs();
        cout << binarySearch(1, w + h + 1) << "\n";   
    }
}
#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

struct UnionFind{
    vector<int> parent;
    UnionFind(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    void MergeSets(int a, int b){
        if(FindParent(a) == FindParent(b)) return;
        parent[FindParent(a)] = FindParent(b);
    }
    int FindParent(int x){
        if(parent[x] == x) return x;
        parent[x] = FindParent(parent[x]);
        return parent[x];
    }
};

struct Point{
    int x, y;
};

struct Sensor{
    int radius;
    Point center;
};

int dist(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); 
}

bool intersects(Sensor &a, Sensor &b){
    return dist(a.center, b.center) <= (a.radius + b.radius) * (a.radius + b.radius); 
}

int main(){
    optimize;
    
    int n, m, k;
    cin >> m >> n >> k;

    UnionFind uf(k);
    vector<Sensor> s(k);

    vector<bool> top(k, false);
    vector<bool> bottom(k, false);
    vector<bool> left(k, false);
    vector<bool> right(k, false);

    for(int i = 0; i < k; i++)
        cin >> s[i].center.x >> s[i].center.y >> s[i].radius;

    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k; j++){
            if(intersects(s[i], s[j])){
                uf.MergeSets(i, j);
            }
        }
    }

    for(int i = 0; i < k; i++){
        if(s[i].center.x - s[i].radius <= 0) left[uf.FindParent(i)] = true;
        if(s[i].center.x + s[i].radius >= m) right[uf.FindParent(i)] = true;
        if(s[i].center.y - s[i].radius <= 0) bottom[uf.FindParent(i)] = true;
        if(s[i].center.y + s[i].radius >= n) top[uf.FindParent(i)] = true;
    }

    bool possible = true;

    for(int i = 0; i < k; i++){
        if((left[i] && right[i]) || (top[i] && bottom[i]) || (left[i] && bottom[i]) || (top[i] && right[i]))
            possible = false;
    }

    cout << (possible ? "S" : "N") << "\n";

    return 0;   
}

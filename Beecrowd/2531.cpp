#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int total = 0;
    priority_queue <int> pq;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        total += x;
        if(i % k == 0){
            pq.push(-x);
        }
        else{
            x = max(x, -pq.top());
            pq.pop();
            pq.push(-x);
        }
    }

    while(!pq.empty()){
        total += pq.top();
        pq.pop();
    }

    cout << total << endl;
}
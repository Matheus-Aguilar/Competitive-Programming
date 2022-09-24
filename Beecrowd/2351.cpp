#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int total = 0, cont = 0;
    priority_queue <int> pq;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        total += x;
        if(cont % k == 0 && cont){
            pq.push(-x);
            cont = 0;
        }
        else if(!pq.empty()){
            x = max(x, -pq.top());
            pq.pop();
            pq.push(-x);
            cont++;
        }
        else{
            cont++;
        }
        
    }

    while(!pq.empty()){
        total += pq.top();
        pq.pop();
    }

    cout << total << endl;
}
#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAXN 1825510
#define INF 0xffffff
 
using namespace std;
 
struct planet{
    int h, r, t, d;
};
 
bool dia[MAXN];
planet p[30];
 
int main(){
    optimize;
 
    int n;
    cin >> n;
 
    int day_length = 0;
 
    for(int i = 0; i < n; i++){
        cin >> p[i].h >> p[i].r >> p[i].t;
        if(p[i].t > p[i].r)
            p[i].d = p[i].t - (p[i].r + 1);
        else
            p[i].d = p[i].h + p[i].t - p[i].r - 1;
        day_length = max(day_length, p[i].h);
    }
 
    int total_hours = 1825 * day_length;

    for(int i = 0; i < n; i++){
        if(p[i].t < p[i].r)
            for(int j = 0; j < p[i].t; j++)
                dia[j] = true;
        
        for(int j = p[i].r + 1; j < total_hours; j += p[i].h){
            for(int k = j; k < (j + p[i].d) && k < total_hours; k++){
                dia[k] = true;
            }
        }
    }
 
    for(int i = 0; i < total_hours; i++){
        if(!dia[i]){
            cout << i << "\n";
            return 0;
        }
    }
 
    cout << "impossible" << "\n";
}
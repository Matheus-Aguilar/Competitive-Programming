#include<bits/stdc++.h>

using namespace std;

int maxPrefix(string &prev, string &now){
    for(int i = 0; i < now.size(); i++)
        if(prev[i] != now[i])
            return i;
    return now.size();
}

int main(){
     int n;
     while(scanf("%d", &n) == 1){
        vector<string> numbers(n);
        char aux[201];

        for(int i = 0; i < n; i++){
            scanf("%s", aux);
            numbers[i] = aux;
        }

        sort(numbers.begin(), numbers.end());
        
        int savings = 0;
        
        for(int i = 1; i < n; i++)
            savings += maxPrefix(numbers[i - 1], numbers[i]);

        printf("%d\n", savings);
     }
}
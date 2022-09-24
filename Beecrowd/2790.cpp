#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int>d(6, 0);
    while(n--){
        int x;
        scanf("%d", &x);
        transform(d.begin(), d.end(), d.begin(), [](int a){return a + 1;});
        --d[x - 1];
        ++d[7 - x - 1];
    }

    cout << *min_element(d.begin(), d.end()) << endl;
}
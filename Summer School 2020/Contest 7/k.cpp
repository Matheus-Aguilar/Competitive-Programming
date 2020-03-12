#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main(){
    optimize;
    int c, n, onTrain = 0;
    bool valid = true;
    cin >> c >> n;

    while(n--){
        int in, out, wait;
        cin >> out >> in >> wait;
        onTrain -= out;
        if(onTrain < 0) valid = false;
        onTrain += in;
        if(onTrain > c) valid = false;
        if(onTrain < c && wait) valid = false;
    }

    if(onTrain) valid = false;

    cout << (!valid ? "im" : "") << "possible" << "\n";
    return 0;
}

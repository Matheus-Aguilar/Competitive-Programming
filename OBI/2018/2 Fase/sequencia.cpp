#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n, l, h;
    cin >> n >> l >> h;
    vector<long long int>v(n);
    vector<long long int>s(n);
    vector<long long int>si;
    for(long long int i = 0; i < v.size(); i++) cin >> v[i];
    long long int specials = 0;
    for(long long int i = 0; i < s.size(); i++){ 
        cin >> s[i];
        if(s[i]) {
            specials++;
            si.push_back(i);
        }
    }

    if(specials == 0){
        long long int best = 0;
        long long int now = 0;
        for(long long int i = 0; i < v.size(); i++){
            now += v[i];
            if(now < 0) now = 0;
            best = max(best, now);
        }
        cout << best << endl;
        return 0;
    }

    vector<long long int>b(specials, 0);
    vector<long long int>a(specials, 0);
    vector<long long int>b2(specials + 1, 0);
    long long int bi = 0, ai = -1, acuB = 0, acuA = 0;
    long long int bestAux = 0;
    long long int aux = 0;
    for(long long int i = 0; i < n; i++){
        acuB += v[i];
        b2[bi] += v[i];
        acuA += v[i];
        if(!s[i])
            aux += v[i];
        if(aux < 0) aux = 0;
        bestAux = max(bestAux, aux);
        if(s[i]){
            aux = 0;
            b[bi] = acuB;
            bi++;
            ai++;
            acuB = acuA = 0;
        }
        else if(acuB < 0){
            acuB = 0;
        }
        if(ai != -1)
            a[ai] = max(a[ai], acuA);
    }

    long long int best = -1e9;
    if(l == 0) best = 0;

    for(long long int i = 0; i < specials && h; i++){
        long long int now = b[i];
        if(l <= 1){
            best = max(best, now + a[i]);
        }
        for(long long int j = 1; j < h && i + j < specials; j++){
            long long int k = i + j;
            now += b2[k];
            if(j + 1 >= l){
                best = max(best, now + a[k]);
            }
        }
    }

    if(l == 0){
        for(long long int i = 0; i < specials; i++){
            best = max(best, b[i] - v[si[i]]);
        }
        long long int now = 0;
        for(int i = si.back() + 1; i < n; i++){
            now += v[i];
            if(now < 0) now = 0;
            best = max(best, now);
        }
        now = 0;
        for(int i = 0; i < si[0]; i++){
            now += v[i];
            if(now < 0) now = 0;
            best = max(best, now);
        }
        best = max(best, bestAux);
    }

    cout << best << endl;
}
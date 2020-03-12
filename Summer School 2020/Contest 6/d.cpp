#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0xffffff
#define pii pair<int, int>

using namespace std;

vector<pii> steps;

void selection_sort(string &W){
    int n = W.size();

    for(int i = 0; i < n; i++){

        char maior = W[0];
        int maior_indice = 0;

        for(int j = 1; j < n - i; j++){
            if(maior <= W[j]){
                maior = W[j];
                maior_indice = j;
            }
        }

        if(n - i - 1 != maior_indice){
            swap(W[n - i - 1], W[maior_indice]);
            steps.push_back(pii(n - i, maior_indice + 1));
        }
    }
}

int main(){
    optimize;

    string W;
    cin >> W;

    selection_sort(W);

    for(int i = steps.size() - 1; i >= 0; i--)
        cout << steps[i].first << " " << steps[i].second << "\n";
}
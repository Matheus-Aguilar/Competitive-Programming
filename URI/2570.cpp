#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d %d\n", &n, &m, &k);
    //cin >> n >> m >> k;
    vector<pair<int, int>>rl(n, make_pair(-1, -1));
    vector<pair<int, int>>rc(m, make_pair(-1, -1));
    vector<pair<char, int>>score = {{'R', 0}, {'H', 0}, {'C', 0}, {'P', 0}};

    for(int i = 0; i < k; i++){
        char op;
        int pos;
        scanf("%c %d\n", &op, &pos);
        if(op == 76)
            rl[pos - 1] = make_pair(i % 4, i);
        else
            rc[pos - 1] = make_pair(i % 4, i);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(rl[i].first == -1 && rc[j].first == -1)
                continue;
            else if(rl[i].first == rc[j].first)
                score[rl[i].first].second++;
            else if(rl[i].second > rc[j].second)
                score[rl[i].first].second++;
            else
                score[rc[j].first].second++;
        }
    }

    cout << score[0].first << score[0].second;
    for(int i = 1; i < 4; i++) 
        cout << " " << score[i].first << score[i].second;
    cout << endl;
}
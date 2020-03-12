#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int mapa(char c){
    if(c >= '2' && c <= '9') return (int)(c - '1');
    if(c == 'A') return 0;
    if(c == 'D') return 9;
    if(c == 'Q') return 10;
    if(c == 'J') return 11;
    return 12;
}

struct Player{
    Player(){
        memset(cards, 0, sizeof(cards));
        jokerEnded = false;
    }
    int cards[14];
    bool jokerEnded;
};

void setCards(int index, string &s, Player p[]){
    for(int i = 0; i < s.size(); i++)
        p[index].cards[mapa(s[i])]++;
}

void passCard(int index, int index2, Player p[]){
    if(p[index].cards[13] && p[index].jokerEnded){
        p[index].jokerEnded = false;
        p[index].cards[13]--;
        p[index2].cards[13]++;
    }
    else{
        if(p[index].cards[13]) p[index].jokerEnded = true;
        int biggest = -1;
        for(int i = 0; i < 13; i++){
            if(p[index].cards[i] < p[index].cards[biggest] || biggest == -1){
                if(p[index].cards[i]) biggest = i;
            }
        }
        p[index].cards[biggest]--;
        p[index2].cards[biggest]++;
    }
}

bool hasWon(int index, Player p[]){
    int sum = 0;
    bool fourEquals = false;
    for(int i = 0; i < 14; i++){
        sum += p[index].cards[i];
        fourEquals |= (p[index].cards[i] == 4);
    }
    return (sum == 4) && fourEquals;
}

int main(){
    optimize;
    
    int n, k;
    cin >> n >> k;
    --k;

    Player p[n];

    p[k].cards[13] = 1;
    int winner = -1;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        setCards(i, s, p);
        if(hasWon(i, p)){
            winner = i + 1;
            break;
        }
    }

    while(winner == -1){
        passCard(k, (k + 1) % n, p);
        if(hasWon(k, p)) winner = k + 1;
        k = (k + 1) % n;
    }

    cout << winner << "\n";

    return 0;   
}

#include<bits/stdc++.h>
#define DEBUG_

using namespace std;

void kmpTable(string &w, vector<int> &t){
    
    t.resize(w.size() + 1);

    t[0] = -1;
    
    int i, j;

    for(i = 1, j = 0; i < w.size(); i++, j++){
        if(w[i] == w[j])
            t[i] = t[j];
        else{
            t[i] = j;
            j = t[j];
            while(j >= 0 && w[i] != w[j])
                j = t[j];
        }
    }

    t[i] = j;
}

bool kmpSearch(string &s, string &w){
    
    vector<int> t;
    
    kmpTable(w, t);

    int i = 0, j = 0;
    
    while(i < s.size()){
        if(w[j] == s[i]){
            ++i, ++j;
            if(j == w.size())
                return true;
        }
        else{
            j = t[j];
            if(j < 0)
                ++i, ++j;
        }
    }

    return false;
}

int noteMap(char *note){
    int value;
    switch(note[0]){
        case 'C':
            value = 0;
            break;
        case 'D':
            value = 2;
            break;
        case 'E':
            value = 4;
            break;
        case 'F':
            value = 5;
            break;
        case 'G':
            value = 7;
            break;
        case 'A':
            value = 9;
            break;
        case 'B':
            value = 11;
            break;
        
    }

    if(note[1] == '#')
        ++value;
    else if(note[1] == 'b')
        --value;

    return value - (value > 11 ? 12 : 0) + (value < 0 ? 12 : 0);
}

bool kmpSearch(string &s, vector<string> &w){
    for(int i = 0; i < w.size(); i++)
        if(kmpSearch(s, w[i]))
            return true;
    return false;
}

int main(){
    int m, t, cont = 1;
    while(scanf("%d%d", &m, &t) == 2, m || t){
        string s = "";
        vector<string>w(12, "");

        char note[2];

        for(int i = 0; i < m; i++){
            scanf("%s", &note);
            s += ('A' + noteMap(note));
        }

        for(int i = 0; i < t; i++){
            scanf("%s", &note);
            for(int j = 0; j < 12; j++)
                w[j] += ('A' + (noteMap(note) + j ) % 12);
        }

        printf("%c\n", (kmpSearch(s, w) ? 'S' : 'N'));
    }
}
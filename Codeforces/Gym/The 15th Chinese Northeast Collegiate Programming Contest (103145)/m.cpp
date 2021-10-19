#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

map<string, string> m;

void precalc(){
    m["iu"] = "q"; m["q"] = "q"; 
    m["en"] = "f"; m["f"] = "f";
    m["ei"] = "w"; m["w"] = "w"; 
    m["eng"] = "g"; m["g"] = "g";
    m["e"] = "e"; 
    m["ang"] = "h"; m["h"] = "h";
    m["uan"] = "r"; m["r"] = "r"; 
    m["an"] = "j"; m["j"] = "j";
    m["ue"] = "t"; m["t"] = "t";
    m["uai"] = "k"; m["ing"] = "k"; m["k"] = "k";
    m["un"] = "y"; m["y"] = "y"; 
    m["uang"] = "l"; m["iang"] = "l"; m["l"] = "l";
    m["sh"] = "u"; m["u"] = "u"; 
    m["ou"] = "z"; m["z"] = "z";
    m["ch"] = "i"; m["i"] = "i"; 
    m["ia"] = "x"; m["ua"] = "x"; m["x"] = "x";
    m["uo"] = "o"; m["o"] = "o"; 
    m["ao"] = "c"; m["c"] = "c";
    m["ie"] = "p"; m["p"] = "p"; 
    m["zh"] = "v"; m["ui"] = "v"; m["v"] = "v";
    m["a"] = "a"; 
    m["in"] = "b"; m["b"] = "b";
    m["ong"] = "s"; m["iong"] = "s"; m["s"] = "s"; 
    m["iao"] = "n"; m["n"] = "n";
    m["ai"] = "d"; m["d"] = "d"; 
    m["ian"] = "m"; m["m"] = "m";
}

string process(string &word){
    if(word.size() == 1)
        return word + word;
    if(word.size() == 2)
        return word;
    
    if(m.find(word) != m.end()){
        return word[0] + m[word];
    }

    for(int i = 1; i < word.size(); i++){
        string sub1 = word.substr(0, i), sub2 = word.substr(i, word.size() - i);

        if(m.find(sub1) != m.end() && m.find(sub2) != m.end()){
            return m[sub1] + m[sub2];
        }
    }

    assert(false);
}

int main(){
    optimize;

    precalc();

    string line, word, ans;

    while(getline(cin, line)){
        stringstream ss;
        ss << line;

        ans = "";

        while(ss >> word){
            ans += process(word);
            ans += ' ';
        }

        ans.pop_back();
        cout << ans << '\n';
    }
    
    return 0;   
}

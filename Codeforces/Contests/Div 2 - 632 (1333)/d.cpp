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

int insertionSort(string s){
    int inv = 0;
    for(int i = 0; i < s.size(); i++){
        int j = i - 1;
        char tmp = s[i];
        while(j >= 0 && s[j] > tmp){
            inv++;
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = tmp;
    }
    return inv;
}

int bubbleSort(string s){
    int cycles = 0;
    bool sorted = false;
    for(int i = 0; i < s.size() && !sorted; i++){
        sorted = true;
        for(int j = 0; j < s.size() - 1; j++){
            if(s[j] > s[j + 1]){ 
                swap(s[j], s[j + 1]);
                j++;
                sorted = false;
            }
        }
        cycles++;
    }
    return cycles - 1;
}

int main(){
    optimize;

    int n, k, minK, maxK;
    string s;

    cin >> n >> k >> s;

    maxK = insertionSort(s);
    minK = bubbleSort(s);

    //cout << minK << " " << maxK << "\n";

    if(k < minK || k > maxK){
        cout << -1 << "\n";
    }
    else{
        vector<int> cand;
        for(int i = 0; i < s.size() - 1; i++)
            if(s[i] == 'R' && s[i + 1] == 'L')
                cand.push_back(i);

        while(k){
            if(k == maxK){
                int pos = cand.back();
                cand.pop_back();
                swap(s[pos], s[pos + 1]);
                cout << 1 << " " << pos + 1 << "\n";
                if(pos > 0 && s[pos - 1] == 'R') cand.push_back(pos - 1);
                if(pos < n - 2 && s[pos + 2] == 'L') cand.push_back(pos + 1);
                k--, maxK--;
            }
            else{
                int quant = min((int)cand.size(), maxK - k + 1);
                cout << quant << " ";
                while(quant--){
                    int pos = cand.back();
                    cout << pos + 1 << " ";
                    swap(s[pos], s[pos + 1]);
                    cand.pop_back();
                    maxK--;
                }
                cout << "\n";

                k--;

                cand.clear();
                for(int i = 0; i < s.size() - 1; i++)
                    if(s[i] == 'R' && s[i + 1] == 'L')
                        cand.push_back(i);
            }
        }
    }

    return 0;   
}

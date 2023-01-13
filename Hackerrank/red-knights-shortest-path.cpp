#include <bits/stdc++.h>
#define MAXN 500
#define INF 0x3f3f3f3f

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'printShortestPath' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER i_start
 *  3. INTEGER j_start
 *  4. INTEGER i_end
 *  5. INTEGER j_end
 */

int dist[MAXN][MAXN];
pair<int, int> par[MAXN][MAXN];
string preMov[MAXN][MAXN];

const int moves[6][2] = {{-2, -1}, {-2, 1}, {0, 2}, {2, 1}, {2, -1}, {0, -2}};
const string movStr[6] = {"UL", "UR", "R", "LR", "LL", "L"}; 

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    
    memset(dist, INF, sizeof(dist));
    
    queue<pair<int, int>> q;
    
    dist[i_start][j_start] = 0;
    par[i_start][j_start] = make_pair(-1, -1);
    q.emplace(i_start, j_start);
    
    while(!q.empty()){
        
        pair<int, int> u = q.front();
        q.pop();
        
        int i = u.first;
        int j = u.second;
        
        for(int k = 0; k < 6; k++){
            int i2 = i + moves[k][0];
            int j2 = j + moves[k][1];
            
            if(i2 >= 0 && j2 >= 0 && i2 < n && j2 < n && dist[i2][j2] == INF){
                dist[i2][j2] = dist[i][j] + 1;
                par[i2][j2] = make_pair(i, j);
                preMov[i2][j2] = movStr[k];
                q.emplace(i2, j2);
            }
        }  
    }
    
    if(dist[i_end][j_end] == INF){
        cout << "Impossible" << endl;
    } else {
        cout << dist[i_end][j_end] << endl;
        
        vector<string> op;
        
        while(i_end != i_start || j_end != j_start){
            op.push_back(preMov[i_end][j_end]);
            pair<int, int> p = par[i_end][j_end];
            i_end = p.first;
            j_end = p.second;    
        }
        
        reverse(op.begin(), op.end());
        
        for(int i = 0; i < op.size(); i++)
            cout << op[i] << " \n"[i+1==op.size()];
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int i_start = stoi(first_multiple_input[0]);

    int j_start = stoi(first_multiple_input[1]);

    int i_end = stoi(first_multiple_input[2]);

    int j_end = stoi(first_multiple_input[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

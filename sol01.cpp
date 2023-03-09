/**
 * Complexity: O(k * m * log(n))
 */
#include <bits/stdc++.h>

using namespace std;


ofstream out("output.txt");

#define INF ULONG_MAX

int C, R, S;
vector<int> len_S;
vector<vector<int>> matrix;
set<pair<int,int>> wormhole;

typedef uint64_t ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, int> li;
typedef vector<vector<int>> vvi;

int main(int argc, char *argv[]) {
    ifstream in;
    in.open(argv[1], ios::in);
    in >> C >> R >> S;
    len_S.resize(S);
    matrix.resize(R, vector<int>(C));

    int fuffa;
    for (int i = 0; i < S; i++) {
        in >> fuffa;
        len_S.push_back(fuffa);
    }
    string cella;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            in >> cella;
            if (cella == "*"){
                matrix[i][j] = -1;
                wormhole.insert(make_pair(i,j));
            }
            else {
                matrix[i][j] = stoi(cella);
            }
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }


    for (int snake=0; snake < S; snake++){
        
    }


}
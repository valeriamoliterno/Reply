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
vector<vector<bool>> visited;
set<pair<int,int>> wormhole;
vector<vector<string>> paths;

string savepath(int snake, int cur_c, int cur_r, int next_c, int next_r){

        // movimento
        if ((next_c == cur_c) && (next_r== cur_r-1)){
            paths[snake].push_back("U");
        }else if ((next_c == cur_c) && (next_r== cur_r+1)){
            paths[snake].push_back("D");
        }else if ((next_c == cur_c-1) && (next_r== cur_r)){
            paths[snake].push_back("L");
        }else if ((next_c == cur_c+1) && (next_r== cur_r)){
            paths[snake].push_back("R");
        } else {
            //wormhole
            paths[snake].push_back(to_string(next_r));  // occhio che sono da leggere al contrario
            paths[snake].push_back(to_string(next_c));
        }

}

pair<int,int> choosestart(){
    return make_pair(rand()%C,rand()%R);
    //sistemare
}

vector<pair<int,int>> choosenext(int snake, int c, int r, int l){
    vector<pair<int,int>> papabili;
    // papabili.push_back(make_pair(1,2));
    // int maxPath;
    // if (l==1){
    //     maxPath=max({matrix[r-1][c]*(visited[r-1][c] ? -1 : 1), 
    //         matrix[r+1][c]*(visited[r+1][c] ? -1 : 1),  
    //         matrix[r][c-1]*(visited[r][c-1] ? -1 : 1),  
    //         matrix[r][c+1]*(visited[r][c+1] ? -1 : 1)});
    // }
    if (!visited[c][r+1]){
        papabili.push_back(make_pair(c,r+1));
    }    
    if (!visited[c][r-1]){
        papabili.push_back(make_pair(c,r-1));
    }
    if (!visited[c+1][r]){
        papabili.push_back(make_pair(c+1,r));
    }
    if (!visited[c-1][r]){
        papabili.push_back(make_pair(c-1,r));
    }
    
    //todo
//vedi come scegliere il buco nero
//ritorna classifica dei  vicini POSSIBILI con vec<pair<int>>
    return papabili;
}

bool movefrom(int snake, int c, int r, int l){
    // [c,r] gia' visitata e sistemata
    if (l==0) return true;

    bool successful=false;
    int count=0;
    vector<pair<int,int>> next_cells = choosenext(snake, c, r, l);   //
    while (!successful && count < next_cells.size()){
        int next_c= next_cells[count].first;
        int next_r= next_cells[count].second;

        if(matrix[next_c][next_r]!=-1){     // atterri in un punto normale
            visited[next_c][next_r] = true;
        }
        savepath(snake, c, r, next_c, next_r);
        bool successful = movefrom(snake, next_c, next_r, l-1);
        count++;
        if (!successful){
            //backtrack
            visited[next_c][next_r] = false;
            paths[snake].pop_back();
            if (matrix[c][r]==-1){
                // distinguere buchi
                paths[snake].pop_back();
            }

        }
    }

    return successful;
}

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
        pair<int,int> start = choosestart();
        movefrom(snake,start.first,start.second,len_S[snake]-1);
        
    }





    in.close(); out.close();
}
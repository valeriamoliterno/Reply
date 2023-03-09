/**
 * Complexity: O(k * m * log(n))
 */
#include <bits/stdc++.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

#define INF ULONG_MAX

int C, R, S;
vector<int> len_S;

typedef uint64_t ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, int> li;
typedef vector<vector<int>> vvi;

int main(int argc, char *argv[]) {
    in >> C >> R >> S;
    len_S.resize(S);

    // for (int i = 0; i < m; i++) {
    //     int a, b;
    //     ll c;
    //     in >> a >> b >> c;
    //     if (a == b) continue;
    //     edges[i] = {a, b, c, c, false};
    //     g[a].emplace_back(i);
    // }
}
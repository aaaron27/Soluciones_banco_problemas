#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w; cin >> n >> w;

    srand(time(nullptr));

    set<pair<int, int>> edges;

     while ((int)edges.size() < w) {
        
        int u = rand() % n + 1;
        int v = rand() % n + 1;

        
        if (u != v) {
            if (u > v) std::swap(u, v);
            edges.insert({u, v});
        }
    }

    cout << n << ' ' << w << '\n';
    for (auto &[i,j] : edges) cout << i << ' ' << j << '\n';

    return 0;
}

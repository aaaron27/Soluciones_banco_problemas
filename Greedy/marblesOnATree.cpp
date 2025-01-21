#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)a.size())

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
    int n;
    while(true){
        cin >> n;
        if (!n) break;

        vi c(n, 0);
        vi cnt(n, 0);
        vvi adj(n);

        for (int i = 0; i < n; i++){
            int vertex; cin >> vertex; vertex--;
            int m; cin >> m;
            c[vertex] = m;

            int j; cin >> j;
            for (int k = 0; k < j; k++){
                int vertex2; cin >> vertex2; vertex2--;
                adj[vertex2].push_back(vertex);
                cnt[vertex]++;
            }
        }

        queue<int> zeros;
        for (int i = 0; i < n; i++){
            if (cnt[i] == 0) zeros.push(i);
        }

        int res = 0;
        while(!zeros.empty()){
            int t = zeros.front(); zeros.pop();

            if ((int)adj[t].size() > 0){
                int t2 = adj[t][0];
                cnt[t2]--;

                if (cnt[t2] == 0) zeros.push(t2);

                int diff = c[t] - 1;
                c[t2] += diff;
                res += abs(diff);
            }
        }

        cout << res << '\n';
    }
}

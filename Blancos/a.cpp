#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) (cout << (n) << '\n')
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(v.rbegin(),v.rend())
#define MOD 1000000007
#define sz(a) (int)a.size()
#define read(a) for(auto &i: a) cin >> i
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX = 2e5+20;

const int X[4] = {-1, 1, 0, 0};
const int Y[4] = {0, 0, -1, 1};

int main(){
    int x,y; cin >> y >> x;
    vvi h(x, vi(y));

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) cin >> h[i][j];
    }

    vector<vector<bool>> vis(x, vector<bool>(y));

    int res = 0;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if (vis[i][j]) continue;

            queue<pair<int,int>> garden;
            garden.push({i, j});
            vis[i][j] = true;

            int c = 0;
            bool is = false;

            while(!garden.empty()){
                auto &[k,l] = garden.front(); garden.pop();
                c++;

                for (int d = 0; d < 4; d++){
                    int dx = k + X[d];
                    int dy = l + Y[d];

                    if (dx >= 0 && dx < x && dy >= 0 && dy < y){
                        if (!vis[dx][dy] && h[dx][dy] == h[k][l]){
                            garden.push({dx,dy});
                            vis[dx][dy] = true;
                        }
                        if (h[dx][dy] < h[k][l]) is = true;
                    }
                }

            }
            if (!is) res += c;
        }
    }

    cout << res << '\n';

    return 0;
}

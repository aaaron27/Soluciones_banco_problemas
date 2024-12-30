#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;

        // will store the prices based on the maximal weight
        // of each person
        vi precios(31);

        // input (prices and weights) and construct DP
        for (int i = 0; i < N; i++){
            int P, W;
            cin >> P >> W;

            // 30 because 1 <= W <= 30
            for (int j = 30; j >= W; j--){
                precios[j] = max(precios[j], precios[j-W]+P);
            }
        }

        int G, res = 0;
        cin >> G;
        while(G--){
            int MW;
            cin >> MW;
            res += precios[MW];
        }
        cout << res << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int p = 1 + rand() % 10000;
    int c = 1 + rand() % 10000;

    cout << n << ' ' << p << ' ' << c << '\n';
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int random1 = 1 + rand() % 10000;
            cout << i+1 << ' ' << j+1 << ' ' << random1 << '\n';
        }
    }

    return 0;
}

#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt(2, 1000, "n");
    inf.readSpace();
    inf.readInt(1, 10000, "p");
    inf.readSpace();
    inf.readInt(1, 10000, "l");
    inf.readEoln();

    int calc = (n*(n-1))/2;
    for (int i = 0; i < calc; i++){
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v =inf.readInt(1, n, "v");
        inf.readSpace();
        inf.readInt(1, 10000, "c");
        inf.readSpace();

        ensure(u != v);
        
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}

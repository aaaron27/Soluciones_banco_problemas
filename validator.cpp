#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(2, 50, "n");
    inf.readSpace();
    int w = inf.readInt(1, (n * (n+1)) / 2, "w");
    inf.readEoln();

    for (int i = 0; i < w; w++){
        inf.readInt(1, n, "u");
        inf.readSpace();
        inf.readInt(1, n, "v");
        inf.readEoln();
    }

    inf.readEof();
}

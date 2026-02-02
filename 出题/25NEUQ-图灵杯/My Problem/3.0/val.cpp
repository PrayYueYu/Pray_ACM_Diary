#include "testlib.h"
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 1000, "T");
	inf.readEoln();
    for (int i = 0; i < T; ++i) {
        inf.readLong(1LL, (1LL << 60) - 1ll, "h");
		inf.readEoln();
    }
    inf.readEof();
    return 0;
}


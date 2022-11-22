#include "library.h"

int main(int argc, char **argv) {
    // validate the params
    if (argc == 5) {
        if (strcmp(argv[1], "-a") == 0) {
            if (strstr(argv[3], ".txt") != NULL) {
                doCommand1(argv[2], argv[3], argv[4]);
            } else {
                doCommand3(argv[2], argv[3], argv[4]);
            }
        } else {
            doCommand4(argv[2], argv[3], argv[4]);
        }

    } else if (argc == 6) {
        if (strcmp(argv[1], "-a") == 0) {
            doCommand2(argv[2], argv[3], argv[4], argv[5]);
        } else {
            doCommand5(argv[2], argv[3], argv[4], argv[5]);
        }

    } else {
        cout << "Invalid params" << endl;
        return 0;
    }
    return 225;
}





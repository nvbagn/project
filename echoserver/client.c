#include <stdio.h>

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        printf("Connect to server: %s\n", argv[i]);
    }

    return 0;
}

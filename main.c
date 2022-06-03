#include <stdio.h>
#include "encoder.h"

int main() {
    char text[] = "value";
    char key[] = "value";
    char encoded[] = "qawoi";
    printf("Encoded: %s \n", encodeWord(text, key));
    printf("Decoded: %s", decodeWord(encoded, key));
    return 0;
}

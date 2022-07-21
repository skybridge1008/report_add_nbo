#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t hbo_hexmaker(uint32_t* p) {
   uint32_t a1 = (*p & 0xff000000);
   uint32_t a2 = (*p & 0x00ff0000);
   uint32_t a3 = (*p & 0x0000ff00);
   uint32_t a4 = (*p & 0x000000ff);
   uint32_t result = a4 <<24 | a3 << 8 | a2 >> 8 | a1 >> 24;
   return result;
}

uint32_t hbo_String(FILE* a) {
    uint32_t *BUFFER;
    int fa = fread(BUFFER, 1, 4, a);
    uint32_t hbo_a = hbo_hexmaker(BUFFER);
    //printf("%x\n", hbo_a);
    return hbo_a;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("you need two file");
        return 0;
    }

    FILE *a = fopen(argv[1], "rb");
    FILE *b = fopen(argv[2], "rb");

    if (a == NULL || b == NULL){
        printf("fopenError\n");
        return 1;
    }
    uint32_t hex_String_A = hbo_String(a);
    uint32_t hex_String_B = hbo_String(b);
    uint32_t hex_String_Sum = hex_String_A + hex_String_B;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", hex_String_A, hex_String_A, hex_String_B, hex_String_B, hex_String_Sum, hex_String_Sum);
    fclose(a);
    fclose(b);
    return 0;
}

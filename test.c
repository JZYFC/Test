#include<stdio.h>
#include<math.h>

int main() {
    int16_t a[] = {
            0x000d,
            0x0063,
            0x001d,
            0x0008,
            0x0073,
            0x002e,
            0x003b,
            0x005f,
            0x000b,
            0x001e,
            0x005f,
            0x001e,
            0x0028,
            0x0047,
            0x0000,
            0x003b,
            0x0064,
            0x0015,
            0x000d,
            0x006f,
            0x003d,
            0x0027,
            0x0049,
            0x0031,
            0x0001,
            0x0064,
            0x0006,
            0x000b,
            0x006f,
            0x0001,
            0x0000,
            0x0021,
            0x005c
    };
    for (int i = 0; i < 33; i+=3) {
        int base = 2 * i;
        a[base + 1] ^= a[base];
        a[base + 2] ^= a[base + 1];
        a[base] ^= a[base + 1];
    }
    return 0;
}

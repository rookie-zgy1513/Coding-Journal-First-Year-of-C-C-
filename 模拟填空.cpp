#include <stdio.h>
int popcount(int x) {
    int cnt = 0;
    while (x)
        cnt++, x &= x - 1;
    return cnt;
}
int main() {
    int x = 0x12345678;
    int y = 0x7fffffff;
    int z = 0x43654290;
    printf("%d,%d,%d", popcount(x), popcount(y), popcount(z));
    return 0;
}
#include <stdio.h>
int main(void) {
    int a = 0;
    int i = 0;

    scanf("%d", &a);
    for (i = 1; i <= a; ++i) {
        if (a % i == 0) {
            printf("%d ", i);
        }
    }
}
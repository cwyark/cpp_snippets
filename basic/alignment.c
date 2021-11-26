#include <stdlib.h>
#include <stdio.h>

typedef struct _s1 {
    char a[5];
} s1;

int main() {
    s1 p[10];
    printf("sizeof(p) is %lu\n", sizeof(p));
    printf("sizeof(s1) is %lu\n", sizeof(s1));
    printf("sizeof(*p) is %lu\n", sizeof(*p));
    printf("sizeof(*(p+1)) is %lu\n", sizeof(*(p+1)));
    printf("address if p is 0x%x\n", p);
    for (int i = 0; i < 10; i++) {
        printf("the struct p[%d] address =%p\n", i, p + i);
    }
}
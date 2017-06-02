#include <stdio.h>
#include <stdint.h>
#include <string.h>
 #include <stdlib.h>
struct AB {
    int len;
    char a[0];
}__attribute__ ((__packed__));

typedef struct AB a_t;

char payload[1400];
uint8_t tmp[] = {0x01, 0x02, 0x03, 0x04};
int main()
{
    printf("sizeof(st): %d\n", sizeof(a_t));

    a_t x;
    memset(&x, 0, sizeof(a_t));
    x.len = 20;
    x.a = malloc(10);
    strncpy(x.a, "hello", 5);

printf("%s -%d  len: %d\n", __func__, __LINE__, x.len);
printf("%s -%d  topic: %s\n", __func__, __LINE__, x.a);
    printf("sizeof(st): %d\n", sizeof(a_t));
#if 0
    printf("data :\n");
    for (i = 0; i < sizeof(tmp); i++)
            printf("%02x ", a->buf[i]);
    printf("\n\n");
#endif
//    free(x.a);
    return 0;
}

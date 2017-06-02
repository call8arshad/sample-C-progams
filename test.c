#include <stdio.h>
#include "test.h"
#define TEST 1
int main()
{
#if 0
    FILE *fp;
    int distance = 232;

    fp = fopen("/tmp/resetcode.tmp", "w+");
    fprintf(fp, "%d\n", distance);
    fclose(fp);
    rename("/tmp/resetcode.tmp", "/tmp/resetcode");
#endif
    printf("HelloWorld!.......\n");
    fun();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int fleet_backoffs[8] ={5, 10, 20, 30, 60, 120, 240, 900};

int main()
{
    //char *hostname = "24CB20A3A0";
    char *hostname = "24CB20A517";


    uint64_t host = strtoll(hostname, NULL, 16);
    printf("%s -- %llu\n", hostname, host);
    printf("sizeof--> long long int: %d uint64_t: %d\n",
                    sizeof(long long int), sizeof(uint64_t));

    printf("fleet_backoffs[0]: %d\n", fleet_backoffs[0]);
    fleet_backoffs[0] = 33;
    printf("newfleet_backoffs[0]: %d\n", fleet_backoffs[0]);

    return 0;
}

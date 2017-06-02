#include <stdio.h>
//#include <socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sock = -1;
//#define SERVER  "localhost"
#define SERVER  "127.0.0.1"

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    printf("socket: %d\n", sock);

    struct linger linger_opt;
    linger_opt.l_onoff = 0;
    linger_opt.l_linger = 0;
    setsockopt(sock, SOL_SOCKET, SO_LINGER,
               &linger_opt, sizeof(linger_opt));
    int sock_flag = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
               &sock_flag, sizeof(sock_flag));

    struct sockaddr_in to;
    to.sin_family = AF_INET;
    to.sin_addr.s_addr = inet_addr(SERVER);
    to.sin_port = htons(4908);

    sendto(sock, "Hello", 5, 0, (struct sockaddr *)&to, sizeof(to));

    close(sock);

    return 0;
}

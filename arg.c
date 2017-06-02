#include <stdio.h>
#include <string.h>
#include <unistd.h>

int port;
char HostAddress[255];
char certDirectory[255];
int publishCount;


#define PATH_MAX 200
#define AWS_IOT_MQTT_PORT            8883
#define AWS_IOT_MQTT_CLIENT_ID       "FleetTracker_PUB"
#define AWS_IOT_MY_THING_NAME        "unitcom/message"
#define AWS_IOT_ROOT_CA_FILENAME     "rootCA.crt"
#define AWS_IOT_CERTIFICATE_FILENAME "remote.cert.pem"
#define AWS_IOT_PRIVATE_KEY_FILENAME "remote.private.key"

char rootCA_name[PATH_MAX + 1] = AWS_IOT_ROOT_CA_FILENAME;
char clientCRT[PATH_MAX + 1] = AWS_IOT_CERTIFICATE_FILENAME;
char clientKey[PATH_MAX + 1] = AWS_IOT_PRIVATE_KEY_FILENAME;

void help_print(char *app_name)
{
    printf("usage: %s  [-h HostAddress] [-p Port] [-d CertDirectory]\n\t\t"
             "[-r rootCA (file.cert)] [-c clientCRT(file.pem)]\n\t\t"
             "[-k clientKey (file.key)] [-t topic name]\n", app_name);
}

void parseInputArgs(int argc, char **argv) {
    int opt;

    while(-1 != (opt = getopt(argc, argv, "h:p:d:x:c:t:k:r:"))) {
        switch(opt) {
            case 'h':
                strcpy(HostAddress, optarg);
                printf("Host %s", optarg);
                break;
            case 'p':
                port = atoi(optarg);
                printf("arg %s", optarg);
                break;
            case 'd':
                strcpy(certDirectory, optarg);
                printf("cert root directory %s", optarg);
                break;
            case 'x':
                publishCount = atoi(optarg);
                printf("publish %s times\n", optarg);
                break;
            case 'r':
                strcpy(rootCA_name, optarg);
                printf("cootCa %s\n", optarg);
                break;
            case 'c':
                strcpy(clientCRT, optarg);
                printf("clientCRT %s\n", optarg);
                break;
            case 'k':
                strcpy(clientKey, optarg);
                printf("clientKey %s\n", optarg);
                break;
            case 't':
                break;
            case '?':
printf("%s -- %d I am in que\n", __func__, __LINE__);
                if(optopt == 'c') {
                    printf("Option -%c requires an argument.", optopt);
                } else if(isprint(optopt)) {
                    printf("Unknown option `-%c'.", optopt);
                } else {
                    printf("Unknown option character `\\x%x'.", optopt);
                }
                help_print(argv[0]);
                break;
            default:
                help_print(argv[0]);
                printf("Error in command line argument parsing");
                break;
        }
    }
}


int main(int argc, char **argv)
{
    printf("I am in %s\n", __func__);

    parseInputArgs(argc, argv);

#if 0
    help_print(*argv);


    printf("rootCA_name: %s\nclientCRT: %s\nclientKey: %s\n\n",
            rootCA_name, clientCRT, clientKey);
#endif

    return 0;
}

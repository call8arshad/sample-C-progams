#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

string LogErrorFile = "";

string getDateTime(time_t timeval)
{
    tm *ptm;

    time(&timeval);
    ptm = gmtime(&timeval);
    char buffer[20];

    sprintf(buffer, "%04d/%02d/%02d %02d:%02d:%02d",
            ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,
            ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
    string timestr = buffer;
    return timestr;
}

void logError(string error)
{
    time_t timeval;
    string datetime = getDateTime(timeval);
    cerr << "errr: " << error.c_str() << endl;
    if (LogErrorFile == "") {
        cerr << datetime << " " << error << endl;
    }
}

void fun(string frame)
{
    cerr << "in side fun() frame: " << frame << endl;
}


int main()
{
    string server = "192.168.20.100";
    string moving_str = "60";
    string stopped_str = "900";
    string dataMode_str = "2";
    int t = 20;
    char *tmp = (char *)"my-log";

    logError("hello ----------" +t);
    cout << "FleetConfig:" << server
         << " MovingInterval:" << moving_str
         << " StoppedInterval:" << stopped_str
         << " dataMode_str:" << dataMode_str << endl;

    logError("sending: " +(string)tmp);
    return 0;
}

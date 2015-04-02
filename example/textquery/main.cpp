#include "TextQuery.h"
#include "QueryServer.h"
#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char *argv[])
{
    QueryServer server(InetAddress(8989), "in.txt");
    server.start();
    return 0;
}

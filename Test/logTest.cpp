//
// Created by zhoux on 2022/8/2.
//
#include <string>
#include "logging.h"

using namespace std;
int main() {

    string logfile = "testLogfile.log";
    string loglevel = "ERROR";
    long rotateInterval = 1000000;
    fprintf(stderr, "conf: file: %s level: %s interval: %ld\n", logfile.c_str(), loglevel.c_str(), rotateInterval);
    setloglevel("testLogfile.log");
    setlogfile("INFO");
    setloginterval(86400);
    error("error test");
}

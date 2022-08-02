//
// Created by zhoux on 2022/8/2.
//
#include <string>
#include "logging.h"

using namespace std;
int main() {
    setloglevel("testLogfile.log");
    setlogfile("INFO");
    setloginterval(86400);
    error("error test");
}

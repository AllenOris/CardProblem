#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

const int L = 2000000;
const double eps = 1e-2;

#define _ok 0
#define _wa 1
#define quitf(x,...) exit(x)
#define lld "%lld"

#define pb push_back

typedef long long ll;

bool flag = 0;

FILE *f_in, *f_out, *f_user;
 
bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

double read_float(FILE *f) {
    double ret;
    if(fscanf(f, "%lf", &ret) != 1) {
        exit(_wa);
    }
    return ret;
}
double out_read_float(FILE *f) {
    double ret;
    if(fscanf(f, "%lf", &ret) != 1) {
        flag = 1;
    }
    return ret;
}

void read_until_eof(FILE *f) {
    char ch = fgetc(f);
    while (ch != EOF && is_whitespace(ch)) {
        ch = fgetc(f);
    }
    if (ch != EOF) {
        exit(_wa);
    }
}

int main(int argc, char* argv[]) {
    f_out = fopen(argv[2], "r");
    f_user = fopen(argv[3], "r");

    while(1) {
        double x = out_read_float(f_out);
        if (flag == 1) {
            break;
        }
        double y = read_float(f_user);
        if (x != x || y != y) {
            exit(_wa);
        }
        if (fabs(x - y) > eps) {
            exit(_wa);
        }
    }
    read_until_eof(f_user);
    return 0;
}



#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    double b = DBL_MAX;
    float c = FLT_MAX;
    printf("INT MAX = %d\n", a);
    printf("DOUBLE MAX = %f\n", b);
    printf("FLOAT MAX = %f\n", c);
    printf("SIZE OF INT = %d\n", sizeof(a));
    printf("SIZE OF DOUBLE = %d\n", sizeof(b));
    printf("SIZE OF FLOAT = %d\n", sizeof(c));
    return 0;
}
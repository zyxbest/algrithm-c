#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int a = 123;
    char *str;

    itoa(a, str, 10);
    printf("%s", str);
    return 0;
}

#include "c0_String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void assign(String &s, char *chars)
{
}

int main(int argc, char const *argv[])
{
    String s = {.data = "helloworld", .length = 0};

    printf("%s\n", s.data);
    return 0;
}

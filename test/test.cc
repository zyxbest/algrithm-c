#include <stdio.h>
#include <iostream>

using namespace std;
void test(int &x)
{
    x = 12;
}
int main(int argc, char const *argv[])
{
    int x = 1;
    test(x);
    printf("之后的x: %d", x);
    cout << 1;
    return 0;
}

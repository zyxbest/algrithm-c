#include <stdio.h>
int x = 1;
int *p;
void test(int *x)
{
    // printf("内部变量*x: %d x:%p\n", *x, x);
    *x = 1;
}
int main(int argc, char const *argv[])
{
    printf("全局变量x: %d &x:%p\n", x, &x);
    printf("全局指针p: %d &p:%p\n", p, &p);
    test(&x);
    test(p);
    return 0;
}

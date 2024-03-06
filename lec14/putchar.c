#include <stdio.h>
#include <unistd.h>

int main()
{
    putchar('a');
    sleep(2);
    putchar('b');
    getchar();
    //putchar('\n');

}

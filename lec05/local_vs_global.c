#include <stdio.h>

int itsGlobal = 0;
int main()
{
    int itsLocal = 1;
    printf("Global %d Local %d\n", itsGlobal, itsLocal);
    {
        int itsLocal = 2;
        itsGlobal = 4;
        printf("Global %d Local %d\n", itsGlobal, itsLocal);
    }
    printf("Global %d Local %d\n", itsGlobal, itsLocal);
    return 0;
}

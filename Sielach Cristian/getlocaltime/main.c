#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SYSTEMTIME lt;

    GetLocalTime(&lt);

    printf("%02d/%02d/%d",lt.wDay,lt.wMonth,lt.wYear);

    return 0;
}


#include	"doce.h"
#include 	<stdio.h>
#include 	<string.h>

int main(int argc, char* argv[])
{
    if (argc > 1 && strcmpi(argv[1], "-test") == 0)
		return doce__test();
    return doce__main();
}

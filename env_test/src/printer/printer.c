#include "global.h"
#include "hedo.h"

void   print_enva(char **env)
{
    int i;

    i = 0;
    while (env[i])
        printf("%s\n", env[i++]);
}
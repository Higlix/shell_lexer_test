#include "global.h"

#include "env.h"

int     get_element_size(char **env)
{
    int size;

    size = 0;
    while (env[size])
        size++;
    return (size);
}
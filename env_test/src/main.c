#include "global.h"

#include "hedo.h"
#include "env.h"

t_inst  g_inst;

void    print_env(char **env)
{
    int i;

    i = 0;
    while (env[i])
        printf("%s\n", env[i++]);
}

int main(int argc, char **argv, char **env)
{
    if (env_init(env))
        return (ERROR);
    print_env(g_inst.env);
    printf("--------------------------------\n");
    env_var_set("SARP", "16");
    print_env(g_inst.env);
    printf("--------------------------------\n");
    env_var_unset("SARP");
    print_env(g_inst.env);
    printf("--------------------------------\n");
    return (0);
}
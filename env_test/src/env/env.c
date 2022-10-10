#include "global.h"

#include "env.h"

char    **env_realloc(char **env, char *str)
{
    char **new;
    int var_size;
    int idx;

    idx = 0;
    var_size = get_element_size(env);
    new = (char **) malloc(sizeof(char *) * (var_size + 2));
    while (idx < var_size)
    {
        new[idx] = ft_strdup(env[idx]);
        free(env[idx]);
        idx++;
    }
    new[idx] = str;
    new[idx + 1] = NULL;
    free(env);
    return (new);
}

char    **copy_env(char **env)
{
    char **new;
    int var_size;
    int idx;

    var_size = get_element_size(env);
    idx = 0;
    new = (char **) malloc(sizeof(char *) * (var_size + 1));
    while (idx < var_size)
    {
        new[idx] = ft_strdup(env[idx]);
        idx++;
    }
    new[idx] = NULL;
    return (new);
}

int env_init(char **env)
{
    if (env == NULL)
        return (ERROR);
    g_inst.state = 123;
    g_inst.env = copy_env(env);
    return (0);
}
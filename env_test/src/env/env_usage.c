#include "global.h"

#include "env.h"

int env_var_unset(const char *name)
{
    char **new;
    int var_size;
    int idx;
    int env_i;

    var_size = get_element_size(g_inst.env);
    idx = 0;
    env_i = 0;
    new = (char **) malloc(sizeof(char *) * var_size);
    while (idx < var_size - 1)
    {
        if (!ft_strncmp(name, g_inst.env[env_i], ft_strlen(name)))
            env_i++;
        new[idx] = ft_strdup(g_inst.env[env_i]);
        idx++;
        env_i++;
    }
    new[idx] = NULL;
    free(g_inst.env);
    g_inst.env = new;
    return (0);
}

int env_var_set(const char *name, const char *value)
{
    char *s1;
    char *s2;

    if (!name || !value)
        return (ERROR);
    s1 = ft_strjoin(name, "=");
    s2 = ft_strjoin(s1, value);
    free(s1);
    g_inst.env = env_realloc(g_inst.env, s2);
    return (0);
}
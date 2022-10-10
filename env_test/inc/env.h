#ifndef ENV_H
# define ENV_H

# include <stdlib.h>


int     env_var_set(const char *name, const char *value);
int     env_var_unset(const char *name);


int     env_init(char **env);
char    **env_realloc(char **env, char *str);

int     get_element_size(char **env);

#endif
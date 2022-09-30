#ifndef HEDO_H
# define HEDO_H

# define PROMPT "$> "
# define HEDONISIM 1
# define ERROR -1

# define WHITESPACES " \t\n"
# define QUOTES "\"\'"

# define TEXT 1
# define PIPE 2
# define S_QUOTE 4
# define D_QUOTE 8

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

typedef struct s_data   t_data;
typedef struct s_token  t_token;

struct  s_token
{
    char    *token;
    int     flags; //id
};

struct  s_data
{
    t_list  *tokens;
    char    **env;
    char    *input;
};

t_list  *lexx_input(char *input);

void    test_lex(t_list *tok_list);

#endif
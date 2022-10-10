#ifndef GLOBAL_H
# define GLOBAL_H

# define PROMPT "$> "
# define HEDONISIM 1
# define ERROR -1

# include "libft.h"

typedef struct s_inst   t_inst;

struct s_inst
{
	char    **env;
	int		state;
};

extern t_inst   g_inst;

#endif
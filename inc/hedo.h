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
# define TOK_CONNECTED 16
# define BRACKET_C 32
# define BRACKET_O 64
# define REDIR 128

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
    char    *token; // tokens in strings
    int     flags; // id
};

struct  s_data
{
    t_list  *tokens;
    char    **env;
    char    *input;
};

//LEXER
t_list      *lexx_input(char *input);
int         lexer_token_redir(char *input, int *i, t_list **tokens);
int         lexer_token_pipe(char *input, int *i, t_list **tokens);
int         lexer_token_text(char *input, int *i, t_list **tokens);
int         lexer_token_quote(char *input, int *i, t_list **tokens);
int         lexer_token_bracket(char *input, int *i, t_list **tokens);
int		    quote_len(char *input);
int         text_len(char *input);
int         other_len(char *chr);

//TOKEN
t_list      *token_create(char *str, int id);
t_token     *getContent(t_list *token);
void        del_token(void  *content);

//TEST.c
void        test_lex(t_list *tok_list);

#endif
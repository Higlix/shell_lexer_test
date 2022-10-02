#include "hedo.h"

t_token *new_token(char *str, int flag)
{
	t_token *token;

	token = (t_token *) malloc(sizeof(t_token));
	token->flags = flag;
	token->token = str;
	return (token);
}

t_list  *token_create(char *str, int id)
{
	t_list  *new;

	new = (t_list *) malloc(sizeof(t_list));
	new->content = (void *) new_token(str, id);
	new->next = NULL;
	return (new);
}

t_token *getContent(t_list *token)
{
    return (token->content);
}

void    del_token(void  *content)
{
    t_token *token;

    token = (t_token *) content;
    free(token->token);
    free(token);
}
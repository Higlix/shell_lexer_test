#include "hedo.h"

void    test_lex(t_list *tok_list)
{
    t_token     *token;

    while (tok_list)
    {
        token = (t_token *) tok_list->content;
        printf("flag/id->%d  ", token->flags);
        printf("token->%s\n\n", token->token);
        tok_list = tok_list->next;
    }
}
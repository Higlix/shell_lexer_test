#include "hedo.h"

void    test_lex(t_list *tok_list)
{
    while (tok_list)
    {
        printf("flag-> %d  ", getContent(tok_list)->flags);
        printf("token-> %s\n\n", getContent(tok_list)->token);
        tok_list = tok_list->next;
    }
}
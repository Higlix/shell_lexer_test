#include "hedo.h"

t_list  *lexx_input(char *input)
{
	t_list  *tokens;
	int     i;

	tokens = NULL;
	i = 0;
	while (input[i] && input)
	{
		if (lexer_token_pipe(input, &i, &tokens) == ERROR)
			break ;
        if (lexer_token_bracket(input, &i, &tokens) == ERROR)
            break ;
        if (lexer_token_redir(input, &i, &tokens) == ERROR)
            break ;
		if (lexer_token_text(input, &i, &tokens) == ERROR)
			break ;
		if (lexer_token_quote(input, &i, &tokens) == ERROR)
			break ;
		while (input[i] && ft_strchr(WHITESPACES, input[i]))
			i++;
	}
    if (input[i] != '\0')
        ft_lstclear(&tokens, del_token);
	return (tokens);
}
#include "hedo.h"

int     lexer_token_text(char *input, int *i, t_list **tokens)
{
	t_list  *token;
	char    *token_str;
	int     len;

	len = text_len(&input[*i]);
	if (len > 0)
	{
		token_str = ft_substr(input, *i, len);
		token = token_create(token_str, TEXT);
		ft_lstadd_back(tokens, token);
		(*i) += len;
        if (!ft_strchr(WHITESPACES, input[*i]) && other_len(&input[*i]) == 0)
			getContent(token)->flags |= TOK_CONNECTED;
	}
	return (0);
}

int     lexer_token_pipe(char *input, int *i, t_list **tokens)
{
	t_list  *token;
	char    *token_str;

	if (input[*i] == '|')
	{
		token_str = ft_substr(input, *i, 1);
		if (token_str == NULL)
			return (ERROR);
		token = token_create(token_str, PIPE);
		if (token == NULL)
			return (ERROR);
		ft_lstadd_back(tokens, token);
		(*i)++;
	}
	return (0);
}

int		lexer_token_quote(char *input, int *i, t_list **tokens)
{
	t_list	*token;
	char	*token_str;
	int		len;

	len = quote_len(&input[*i]);
    if (len == ERROR)
        return (ERROR);
	if (len > 0)
	{
		token_str = ft_substr(input, *i + 1, len - 2);
		if (input[*i] == '\'')
			token = token_create(token_str, S_QUOTE);
		else
			token = token_create(token_str, D_QUOTE);
		ft_lstadd_back(tokens, token);
		(*i) += len;
        if (!ft_strchr(WHITESPACES, input[*i]) && other_len(&input[*i]) == 0)
			getContent(token)->flags |= TOK_CONNECTED;        
	}
	return (0);
}

int     lexer_token_bracket(char *input, int *i, t_list **tokens)
{
    char    *token_str;
    t_list  *token;

    if (input[*i] == ')' || input[*i] == '(')
    {
        token_str = ft_substr(input, *i, 1);
        if (input[*i] == ')')
            token = token_create(token_str, BRACKET_C);
        else
            token = token_create(token_str, BRACKET_O);
        ft_lstadd_back(tokens, token);
        (*i)++;
    }
    return (0);
}

int     lexer_token_redir(char *input, int *i, t_list **tokens)
{
    char    *token_str;
    int     len;
    t_list  *token;

    len = 0;
    while (ft_isdigit(input[*i + len]))
        len++;
    if (input[*i + len] == '>' || input[*i + len] == '<')
    {
        if (input[*i + len] == input[*i + len + 1])
            len++;
        len++;
        token_str = ft_substr(input, *i, len);
        token = token_create(token_str, REDIR);
        ft_lstadd_back(tokens, token);
        (*i)+=len;
    }
    return (0);
}
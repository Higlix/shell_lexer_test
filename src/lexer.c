#include "hedo.h"

t_token *new_token(char *str, int flag)
{
	t_token *token;

	token = (t_token *) malloc(sizeof(t_token));
	token->flags = flag;
	token->token = str;
	return (token);
}

t_list  *tokenCreate(char *str, int id)
{
	t_list  *new;

	new = (t_list *) malloc(sizeof(t_list));
	new->content = (void *) new_token(str, id);
	new->next = NULL;
	return (new);
}

int     text_len(char *input, int *i)
{
	int len;
	int idx;
	
	idx = (*i);
	len = 0;
	while (input[idx])
	{
		if (ft_strchr(QUOTES, input[idx]))
			break ;
		if (ft_strchr(WHITESPACES, input[idx]))
			break ;
		idx++;
		len++;
	}
	return (len);
}

int		quote_len(char *input)
{
	int 	i;
	char	quote;

	if (ft_strchr(QUOTES, input[0]) == NULL)
		return(0);
	quote = input[0];
	i = 1;
	while (input[i])
	{
		if (input[i] == quote)
			break ;
		i++;
	}
	if (input[i] != quote)
	{
		printf("You didn't close your quotesions\n");
		exit(1);
	}
	return (i + 1);
}

int     lexer_token_text(char *input, int *i, t_list **tokens)
{
	t_list  *token;
	char    *token_str;
	int     len;

	len = text_len(input, i);
	if (len > 0)
	{
		token_str = ft_substr(input, *i, len);
		token = tokenCreate(token_str, TEXT);
		ft_lstadd_back(tokens, token);
		(*i) += len;
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
		token = tokenCreate(token_str, PIPE);
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
	if (len > 0)
	{
		token_str = ft_substr(input, *i, len);
		if (input[*i] == '\'')
			token = tokenCreate(token_str, S_QUOTE);
		else
			token = tokenCreate(token_str, D_QUOTE);
		ft_lstadd_back(tokens, token);
		(*i) += len;
	}
	return (0);
}

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
		if (lexer_token_text(input, &i, &tokens) == ERROR)
			break ;
		if (lexer_token_quote(input, &i, &tokens) == ERROR)
			break ;
		while (input[i] && ft_strchr(WHITESPACES, input[i]))
			i++;
	}
	return (tokens);
}
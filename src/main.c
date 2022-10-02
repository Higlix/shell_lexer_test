#include "hedo.h"

void    shellLoop(t_data *data)
{
    while (HEDONISIM)
    {
        data->input = readline(PROMPT);
        add_history(data->input);
        data->tokens = lexx_input(data->input);
        if (data->tokens == NULL)
            continue ;
		test_lex(data->tokens);
    }
}

int main(int argc, char **argv, char **evar)
{
    t_data  data;

    data.env = evar;
    shellLoop(&data);
    return (0);
}
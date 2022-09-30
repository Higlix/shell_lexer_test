#include "hedo.h"

void    shellLoop(t_data *data)
{
    while (HEDONISIM)
    {
        data->input = readline(PROMPT);
        data->tokens = lexx_input(data->input);
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
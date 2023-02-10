#include "pipex.h"

static bool	message_wrong_input(void)
{
	ft_printf("error: wrong input, please give the following:\n");
	ft_printf("[pipex] [infile] [cmd1] [cmd2] [outfile]\n");
	return (false);
}

bool	p_input_parsing(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (message_wrong_input());
	return (true);
}

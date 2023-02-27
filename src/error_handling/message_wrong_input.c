#include "pipex.h"

// error message wrong input one pipe with option for
// extra message bonus
bool	message_wrong_input(int bonus)
{
	ft_printf("error: wrong input, please give the following:\n");
	ft_printf("[./pipex] [infile] [cmd1] [cmd2] [outfile]\n");
	if (bonus)
		ft_printf("--> two commands (cmd) or more\n");
	return (false);
}

// error message wrong input for here_doc
bool	message_wrong_input_here_doc(void)
{
	ft_printf("error: wrong input, please give the following:\n");
	ft_printf("[./pipex] [here_doc] [LIMITER] [cmd] [cmd1] [outfile]\n");
	return (false);
}

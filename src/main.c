#include "pipex.h"

int main(int argc, char **argv)
{
	int 	a;

	if (!p_input_parsing(argc, argv))
		return (0);
	a = ft_atoi(argv[1]);
	pipex(a);
	return (0);
}
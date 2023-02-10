#include "pipex.h"

void	perror_and_exit(char *str)
{
	perror(str);
	exit(1);
}

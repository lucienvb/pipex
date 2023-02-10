#include "pipex.h"

void	wait_for_child(void)
{
	int	i;

	i = 2;
	while (i)
	{
		wait(NULL);
		i--;
	}
}

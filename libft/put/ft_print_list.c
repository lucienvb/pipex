#include "libft.h"

void	ft_print_list(char **list)
{
	int i;

	if (!list || list[0] == NULL)
		return ;
	i = 0;
	while (list[i])
		ft_printf("%s\n", list[i++]);
}

#include "pipex.h"

char	*strjoin_three(char *s1, char *s2, char *s3)
{
	char *join_three;

	join_three = ft_strjoin(s1, s2);
	join_three = ft_strjoin(join_three, s3);
	return (join_three);
}

int	access_to_index(char **path, char *system_call)
{
	int		i;
	char	*syst_call_to_path;

	i = 0;
	while (path[i])
	{
		syst_call_to_path = strjoin_three(path[i], "/", system_call);
		if (access(syst_call_to_path, F_OK) == 0 && access(syst_call_to_path, X_OK) == 0)
			return (i);
//		ft_printf("syst_call_to_path: %s\n", syst_call_to_path);
		i++;
	}
	return (-1);
}

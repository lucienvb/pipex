#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



static char	**join_three(char *s1, char *s2, char *s3)
{
	char		**ret;

	ret = malloc(4 * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[0] = ft_strdup(s1);
	ret[1] = ft_strdup(s2);
	ret[2] = ft_strdup(s3);
	ret[3] = NULL;
	return (ret);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*new_envp[] = {NULL};
	char	**file_tmp;
	char	*file;

	(void)argc;
	(void)envp;
	file_tmp = ft_split(argv[2], ' ');
	file = ft_strjoin("/bin/", file_tmp[0]);
	file_tmp = join_three(file_tmp[0], file_tmp[1], argv[1]);
	if (execve(file, file_tmp, new_envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	return (0);
}


//int main(int argc, char **argv)
//{
//	int 	a;
//
//	if (!p_input_parsing(argc, argv))
//		return (0);
//	a = ft_atoi(argv[1]);
//	pipex(a);
//	return (0);
//}
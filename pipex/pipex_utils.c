/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:41:33 by tdutel            #+#    #+#             */
/*   Updated: 2023/02/20 13:06:27 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	**split_path;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	split_path = ft_split(path, ':');
	free(path);
	return (split_path);
}

char	**path_arg_cat(char **src, char *root_arg, char **argv)
{
	int		i;
	char	**pathsrc;

	pathsrc = malloc(sizeof(char *) * (5 + 3));
	i = 0;
	while (i < 5)
	{
		pathsrc[i] = ft_strjoin(src[i], root_arg);
		i++;
	}
	pathsrc[i] = ft_strdup("libft/libft.a");
	pathsrc[i + 1] = ft_strdup(argv[2]);
	pathsrc[i + 2] = NULL;
	return (pathsrc);
}

int	process(char **argv, int index, char **envp, char **src)
{
	char	**path_cmb;
	int		i;
	char	**split_argv;
	char	*root_arg;

	split_argv = ft_split(argv[index], ' ');
	root_arg = ft_strjoin("/", split_argv[0]);
	path_cmb = path_arg_cat(src, root_arg, argv);
	i = 0;
	while (access(path_cmb[i], X_OK) == -1 && path_cmb[i])
		i++;
	if (!path_cmb[i])
	{
		return (-1);
	}
	free(split_argv[0]);
	split_argv[0] = path_cmb[i];
	free(root_arg);
	free(path_cmb);
	return (execve(split_argv[0], split_argv, envp));
}

void	ft_error_exit(int p)
{
	if (p == 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (p == 1)
		ft_putendl_fd("4 args", STDERR_FILENO);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:31:08 by tdutel            #+#    #+#             */
/*   Updated: 2023/02/20 13:06:52 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**src;
	pid_t	id;
	pid_t	id1;
	int		file;
	int		pipe_fd[2];

	pipe(pipe_fd);
	check_parse(argc, argv);
	src = get_path(envp);
	id = fork();
	file = 0;
	if (id == 0)
		file = program_launcher(argv, pipe_fd, envp, src);
	if (file == 1)
		ft_error_exit(0);
	id1 = fork();
	if (id1 == 0)
	{
		file = program_launcher2(argc, argv, pipe_fd);
		if (file == 1)
			ft_error_exit(0);
		if (process(argv, 3, envp, src) == -1)
			ft_error_exit(0);
	}
	return (ft_clear_and_wait(pipe_fd, src));
}

int	program_launcher(char **argv, int pipe_fd[2], char **envp, char **src)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		return (1);
	dup2(file, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(file);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	file = process(argv, 2, envp, src);
	if (file == -1)
		return (1);
	return (0);
}

int	program_launcher2(int argc, char **argv, int pipe_fd[2])
{
	int	file;

	file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		return (1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(file);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (0);
}

int	ft_clear_and_wait(int pipe_fd[2], char **src)
{
	int	i;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
	i = 0;
	while (src[i])
		free(src[i++]);
	free(src);
	return (0);
}

void	check_parse(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5)
		ft_error_exit(1);
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_putendl_fd("empty args", STDERR_FILENO);
			exit (1);
		}
		i++;
	}
	if (access(argv[1], F_OK) == -1)
	{
		ft_putendl_fd("No available file", STDERR_FILENO);
		exit (1);
	}
	if (access(argv[argc - 1], W_OK) == -1 && access(argv[argc - 1], F_OK) == 0)
	{
		ft_putendl_fd("Permission denied", STDERR_FILENO);
		exit (1);
	}
}

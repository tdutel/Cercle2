/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:41:17 by tdutel            #+#    #+#             */
/*   Updated: 2023/02/20 13:38:50 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

//pipec.c//
void	check_parse(int argc, char **argv);
int		program_launcher(char **argv, int pipe_fd[2], char **envp, char **src);
int		program_launcher2(int argc, char **argv, int pipe_fd[2]);
int		ft_clear_and_wait(int pipe_fd[2], char **src);

//pipex_utils.c//
char	**get_path(char **envp);
char	**path_arg_cat(char **src, char *root_arg, char **argv);
char	**get_args(char **path_cmb, int ind, char **s_a, char *input);
int		process(char **argv, int index, char **envp, char **src);
void	ft_error_exit(int p);

#endif

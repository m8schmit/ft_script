/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:42:59 by mschmit           #+#    #+#             */
/*   Updated: 2015/02/12 16:30:17 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

char	*ft_get_env(char **env, char *var_env)
{
	char	**tmp;
	int		i;

	i = 0;
	while (*env[i])
	{
		if (!ft_strncmp(var_env, env[i], ft_strlen(var_env)))
		{
			tmp = ft_strsplit(env[i], '=');
			return (tmp[1]);
		}
		i++;
	}
	return (0);
}

int		readfd(t_overseer *overseer)
{
	fd_set	fd;
	char	buf[256];
	int		numread;

	FD_SET(0, &fd);
	FD_SET(overseer->fdm, &fd);
	if (select(overseer->fdm + 1, &fd, NULL, NULL, NULL) == -1)
		return (-1);
	if (FD_ISSET(0, &fd))
	{
		if ((numread = read(0, buf, 256)) <= 0)
			errordisplay(overseer, "numRead fail", 1);
		write(overseer->fdm, buf, numread);
	}
	if (FD_ISSET(overseer->fdm, &fd))
	{
		if ((numread = read(overseer->fdm, buf, 256)) <= 0)
		{
			footerdisplay(overseer);
			ttyresetnexit(overseer);
		}
		write(1, buf, numread);
		write(overseer->scriptfd, buf, numread);
	}
	return (0);
}

void	checkarg(t_overseer *overseer, char **av, int ac)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	overseer->aflg = 0;
	overseer->qflg = 0;
	overseer->filename = NULL;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			while (av[i][j])
			{
				overseer->aflg = (av[i][j] == 'a') ? 1 : overseer->aflg;
				overseer->qflg = (av[i][j] == 'q') ? 1 : overseer->qflg;
				j++;
			}
			j = 0;
		}
		else if (av[i] != NULL && av[i][0] != '-')
			overseer->filename = av[i];
	}
}

void	openscriptfd(t_overseer *overseer)
{
	int		fd;
	char	*filename;

	filename = (overseer->filename) ? overseer->filename : "typescript";
	if (overseer->aflg == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 00644);
	overseer->scriptfd = fd;
}

int		main(int ac, char **av, char **env)
{
	t_overseer	overseer;
	pid_t		childpid;

	backupterm(&overseer);
	if (env[0] == NULL)
		errordisplay(&overseer, "Env no found.", 1);
	if ((childpid = ptyfork(&overseer)) == 0)
	{
		overseer.shell[0] = ft_get_env(env, "SHELL");
		if (overseer.shell[0] == NULL)
			overseer.shell[0] = "/bin/zsh";
		overseer.shell[1] = NULL;
	}
	execve(overseer.shell[0], overseer.shell, env);
	checkarg(&overseer, av, ac);
	openscriptfd(&overseer);
	if (ft_ttysetraw(&overseer) == -1)
		errordisplay(&overseer, "raw mode fail", 1);
	if (overseer.filename && access(overseer.filename, W_OK))
		errordisplay(&overseer, "ft_script: Error: Permission denied.", 1);
	headerdisplay(&overseer);
	while (42)
		readfd(&overseer);
}

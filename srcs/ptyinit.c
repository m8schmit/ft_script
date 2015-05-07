/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptyinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:38:55 by mschmit           #+#    #+#             */
/*   Updated: 2015/03/27 17:17:09 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

void	ttyresetnexit(t_overseer *overseer)
{
	if (ioctl(0, TIOCSETA, &overseer->origin) == -1)
		write(2, "ttyReset fail", ft_strlen("ttyReset fail"));
	else
	{
		close(overseer->fdm);
		close(overseer->fds);
		close(overseer->scriptfd);
		_Exit(0);
	}
}

void	backupterm(t_overseer *overseer)
{
	if (ioctl(0, TIOCGETA, &overseer->origin) == -1)
	{
		errordisplay(overseer, "tcgetattr fail", 1);
	}
	if (ioctl(0, TIOCGWINSZ, &overseer->winsize) == -1)
	{
		errordisplay(overseer, "TIOCGWINSZ fail", 1);
	}
}

int		ptymasteropen(t_overseer *overseer, int bufsize)
{
	int				fdm;
	char			*p;
	struct stat		sbuf;

	p = 0;
	if ((fdm = open("/dev/ptmx", O_RDWR | O_NOCTTY)) == -1)
		errordisplay(overseer, "open master fd fail", 1);
	if (ioctl(fdm, TIOCPTYGRANT) == -1)
		errordisplay (overseer, "grantpt fail", 1);
	if (ioctl(fdm, TIOCPTYUNLK) == -1)
		errordisplay(overseer, "unlockpt fail", 1);
	if (ioctl(fdm, TIOCPTYGNAME, overseer->ptsnamebuf) != 0)
		if (stat(overseer->ptsnamebuf, &sbuf) == 0)
			p = overseer->ptsnamebuf;
	if (ft_strlen(p) < (size_t)bufsize)
		ft_strncpy(overseer->ptsnamebuf, p, bufsize);
	else
		errordisplay(overseer, "ptsnamebuf overflow", 1);
	if ((overseer->fds = open(overseer->ptsnamebuf, O_RDWR)) == -1)
		errordisplay(overseer, "open slave fd fail0", 1);
	return (fdm);
}

void	ptyforkbis(t_overseer *overseer)
{
	if (setsid() == -1)
		errordisplay(overseer, "setsid fail", 1);
	if ((overseer->fds = open(overseer->ptsnamebuf, O_RDWR)) == -1)
		errordisplay(overseer, "open slave fd fail", 1);
	if (ioctl(overseer->fds, TIOCSCTTY) == -1)
		errordisplay(overseer, "ioctl TIOCSCTTY fail", 1);
	if (ioctl(overseer->fds, TIOCSETA, &overseer->origin) == -1)
		errordisplay(overseer, "Set slave tty attributes fail", 1);
	if (ioctl(overseer->fds, TIOCSWINSZ, &overseer->winsize) == -1)
		errordisplay(overseer, "Set slave tty window size fail", 1);
	if (dup2(overseer->fds, 0) != 0)
		errordisplay(overseer, "open STDIN fail", 1);
	if (dup2(overseer->fds, 1) != 1)
		errordisplay(overseer, "open STDOUT fail", 1);
	if (dup2(overseer->fds, 2) != 2)
		errordisplay(overseer, "open STDERR fail", 1);
	if (overseer->fds > 2)
		close(overseer->fds);
}

pid_t	ptyfork(t_overseer *overseer)
{
	pid_t	childpid;
	int		fdm;

	fdm = ptymasteropen(overseer, 128);
	if ((childpid = fork()) == -1)
	{
		close(fdm);
		errordisplay(overseer, "fork fail", 1);
	}
	else if (childpid != 0)
	{
		overseer->fdm = fdm;
		return (childpid);
	}
	else
	{
		ptyforkbis(overseer);
		close(fdm);
	}
	return (0);
}

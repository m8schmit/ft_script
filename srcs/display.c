/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:10:47 by mschmit           #+#    #+#             */
/*   Updated: 2015/02/12 16:30:07 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

int		ft_ttysetraw(t_overseer *overseer)
{
	t_term term;

	if (ioctl(0, TIOCGETA, &term) == -1)
		return (-1);
	if (&overseer->origin != NULL)
		overseer->origin = term;
	term.c_lflag &= ~(ICANON | ECHONL | ISIG | IEXTEN | ECHO);
	term.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
					| INLCR | IGNCR | ICRNL | IXON);
	term.c_cflag &= ~(CSIZE | PARENB);
	term.c_cflag |= CS8;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	ioctl(0, TIOCSETA, &term);
	return (0);
}

void	headerdisplay(t_overseer *overseer)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	if (overseer->qflg == 0)
	{
		ft_putstr_fd("Script started, output file is ", 1);
		if (overseer->filename != NULL)
			ft_putendl_fd(overseer->filename, 1);
		else
			ft_putendl_fd("typescript", 1);
		ft_putstr_fd("Script started on ", overseer->scriptfd);
		ft_putendl_fd(ctime(&tv.tv_sec), overseer->scriptfd);
	}
}

void	footerdisplay(t_overseer *overseer)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	if (overseer->qflg == 0)
	{
		ft_putstr_fd("\nScript done, output file is ", 1);
		if (overseer->filename != NULL)
			ft_putendl_fd(overseer->filename, 1);
		else
			ft_putendl_fd("typescript", 1);
		ft_putstr_fd("Script done on ", overseer->scriptfd);
		ft_putendl_fd(ctime(&tv.tv_sec), overseer->scriptfd);
	}
}

void	errordisplay(t_overseer *overseer, char *str, int stop)
{
	if (str)
	{
		write(2, str, ft_strlen(str));
		ttyresetnexit(overseer);
	}
	if (stop)
	{
		write(2, "\n", 1);
		ttyresetnexit(overseer);
		_Exit(-1);
	}
}

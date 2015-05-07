/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:55:59 by mschmit           #+#    #+#             */
/*   Updated: 2015/02/12 16:30:10 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/select.h>
# include <termios.h>
# include <signal.h>
# include <term.h>
# include <time.h>
# include <sys/time.h>
# include "libft.h"

typedef struct termios	t_term;
typedef struct winsize	t_win;

typedef struct	s_overseer
{
	t_term		origin;
	t_win		winsize;
	int			aflg;
	int			qflg;
	int			fdm;
	char		ptsnamebuf[128];
	int			fds;
	int			scriptfd;
	char		*filename;
	char		*shell[2];
}				t_overseer;

void			headerdisplay(t_overseer *overseer);
void			footerdisplay(t_overseer *overseer);
void			errordisplay(t_overseer *overseer, char *str, int stop);
void			ttyresetnexit(t_overseer *overseer);
void			backupterm(t_overseer *overseer);

int				ptymasteropen(t_overseer *overseer, int bufsize);
void			ptyforkbis(t_overseer *overseer);
pid_t			ptyfork(t_overseer *overseer);
int				ft_ttysetraw(t_overseer *overseer);
char			*ft_get_env(char **env, char *var_env);
int				readfd(t_overseer *overseer);
void			checkarg(t_overseer *overseer, char **av, int ac);
void			openscriptfd(t_overseer *overseer);
#endif

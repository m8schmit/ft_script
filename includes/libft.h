/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:37:49 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/21 17:30:17 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# define INT_MIN (-INT_MAX - 1)
# define INT_MAX 2147483647
# define BUFF_SIZE 4096

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char const *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char*s1);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
char	*ft_strmap(char const *s, char (*f)(char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned in, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
void	ft_strclr(char *s);
int		ft_atoi(const char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putendl(char const *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
int		ft_putnbr_fd(int n, int fd);
void	ft_puterr(char *s);
char	*ft_strdelc(const char *s, char c);
int		ft_isaspace(int c);
void	ft_freesplit(char **s);
char	*ft_joinfree(char *s1, char *s2, int free_str);
char	**ft_splitendfree(char *s, char c);
int		get_next_line(int const fd, char **line);
int		ft_sizei(char *s);
int		ft_putnbru(unsigned int n, int b);
int		ft_putnbru_fd(unsigned int n, int b, int fd);
int		ft_putpoint_fd(long unsigned int n, int fd);
int		ft_putpoint(long unsigned int n);
int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);

#endif

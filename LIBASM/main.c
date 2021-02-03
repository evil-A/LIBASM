/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 20:51:34 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/18 21:10:31 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, const void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

static void	try_strlen(char *s)
{
	int	r;
	int	m;

	printf("Real: %s - len: %d\n", s, r = strlen(s));
	printf("Mine: %s - len: %d\n", s, m = ft_strlen(s));
	if (r == m)
		printf("\t\tIt's well done! 👍\n");
	else
		printf("\t\tYou must improve it. 👎\n");
}

static void	try_strcpy(char *dst, char *src)
{
	char	*a;
	char	*b;
	char	*c;

	b = strdup(dst);
	c = strdup(dst);
	strcpy(b, src);
	ft_strcpy(c, src);
	printf("REAL: %s - MINE: %s\n", b, c);
	if (!strcmp(b, c))
		printf("\t\tIt's well done! 👍\n");
	else
		printf("\t\tYou must improve it. 👎\n");
	free(b);
	free(c);
}

static void	try_strcmp(char *s1, char *s2)
{
	int	r;
	int	m;

	printf("Real result: %d\n", r = (int)strcmp(s1, s2));
	printf("Mine result: %d\n", m = ft_strcmp(s1, s2));
	if (r == m)
		printf("\t\tIt's well done! 👍\n");
	else
		printf("\t\tYou must improve it. 👎\n");
}

static void	try_strdup(char *src)
{
	char	*dst;

	dst = ft_strdup(src);
	printf("Real: %s - Mine: %s\n", src, dst);
	if (!ft_strcmp(dst, src))
		printf("\t\tIt's well done! 👍\n");
	else
		printf("\t\tYou must improve it. 👎\n");
}

static void	try_write(char *src)
{
	int	r;
	int	m;

	printf("Real: ");
	fflush(stdout);
	r = write(1, src, ft_strlen(src));
	printf(" - Mine: ");
	fflush(stdout);
	m = ft_write(1, src, ft_strlen(src));
	if (r == m)
		printf("\n\t\tIt's well done! 👍\n");
	else
		printf("\n\t\tYou must improve it. 👎\n");
}

static void	break_write(void)
{
	int		fd;
	int		r;
	int		m;
	char	buf[10];

	fd = open("wrong", O_WRONLY);
	r = write(fd, buf, 10);
	printf("Real: %s\n", strerror(errno));
	errno = 0;
	fd = open("wrong", O_WRONLY);
	m = ft_write(fd, buf, 10);
	printf("Mine: %s\n", strerror(errno));
	if (r == m)
		printf("\t\tIt's well done! 👍\n");
	else
		printf("\t\tYou must improve it. 👎\n");
}

static void	try_read(void)
{
	int		r;
	int		m;
	int		fd;
	char	buf[11];

	fd = open("test.txt", O_RDONLY);
	r = read(fd, buf, 10);
	buf[r] = '\0';
	close(fd);
	printf("Real: %s - ", buf);
	fd = open("test.txt", O_RDONLY);
	m = ft_read(fd, buf, 10);
	buf[m] = '\0';
	close(fd);
	printf("Mine: %s\n", buf);
	if (r == m)
		printf("\t\tIt's well done! 👍\n");
	else
		printf("\t\tYou must improve it. 👎\n");
}

static void	break_read(void)
{
	int		fd;
	int		r;
	int		m;
	char	buf[11];

	fd = open("wrong", O_WRONLY);
	r = read(fd, buf, 10);
	printf("Real: %s\n", strerror(errno));
	errno = 0;
	fd = open("wrong", O_WRONLY);
	m = ft_read(fd, buf, 10);
	printf("Mine: %s\n", strerror(errno));
	if (r == m)
		printf("\t\tIt's well done! 👍\n");
	else
		printf("\t\tYou must improve it. 👎\n");
}

int			main(void)
{
	char	*dstcopy = "HELLRAISER";

	printf(" /|\\;,;)/|\\         LIBASM Mandatory Part         /|\\;,;)/|\\ \n");
	printf("FT_STRLEN:\n");
	try_strlen("");
	try_strlen("HELL");
	try_strlen("H E L L");
	try_strlen("\t\t");
	printf("FT_STRCPY:\n");
	try_strcpy(dstcopy, "");
	try_strcpy(dstcopy, "HELL");
	try_strcpy("    ", "Hola");
	try_strcpy("H E L L     ", "R A I S E R");
	printf("FT_STRCMP:\n");
	try_strcmp("", "");
	try_strcmp("Hellraiser", "Hellraiser");
	try_strcmp("Hellraiser", "Hell");
	try_strcmp("Hell", "raiser");
	printf("FT_STRDUP:\n");
	try_strdup("Hellraiser");
	try_strdup("H\1\1R");
	try_strdup("Hell 666 \\");
	try_strdup("📌📌");
	printf("FT_WRITE:\n");
	try_write("Hellraiser");
	try_write(" \1HELL");
	try_write("");
	try_write("%2%");
	printf("Break the ft_write\n");
	break_write();
	printf("FT_READ:\n");
	try_read();
	printf("Break the ft_read\n");
	break_read();
	return (0);
}

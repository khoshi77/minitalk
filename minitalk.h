#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>

# define BUFSIZE 10000

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);

#endif
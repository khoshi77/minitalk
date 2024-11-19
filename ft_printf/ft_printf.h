#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *fmt, ...);
int		ft_judge(const char *fmt, va_list *ap);
void	ft_putchar(char c);
int		ft_putchar_c(char c);
int		ft_putstr_c(char *s);
int		ft_nbr_count(int nbr);
int		ft_putnbr_c(int nbr);
int		ft_putunbr_c(unsigned int nbr);
int		ft_puthex_c(unsigned long long nbr, char sign);
int		ft_putaddress_c(unsigned long long p);

#endif
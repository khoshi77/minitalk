#include "ft_printf.h"

int	ft_nbr_count(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_unbr_count(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_putnbr_c(int nbr)
{
	int	count;

	count = ft_nbr_count(nbr);
	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_c(nbr / 10);
	ft_putchar('0' + nbr % 10);
	return (count);
}

int	ft_putunbr_c(unsigned int nbr)
{
	int	count;

	count = ft_unbr_count(nbr);
	if (nbr >= 10)
		ft_putnbr_c(nbr / 10);
	ft_putchar('0' + nbr % 10);
	return (count);
}

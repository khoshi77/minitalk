#include "ft_printf.h"

int	ft_puthex_c(unsigned long long nbr, char sign)
{
	char	*lower_base;
	char	*upper_base;
	char	*base;
	int		count;

	lower_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	if (sign == 'x')
		base = lower_base;
	else
		base = upper_base;
	if (nbr < 16)
		count = write(1, &base[nbr], 1);
	else
	{
		count = ft_puthex_c(nbr / 16, sign);
		count += write(1, &base[nbr % 16], 1);
	}
	return (count);
}

int	ft_putaddress_c(unsigned long long p)
{
	int	count;

	if (p == 0)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count = write(1, "0x", 2);
	count += ft_puthex_c(p, 'x');
	return (count);
}

#include "ft_printf.h"

int	ft_judge(const char *fmt, va_list *ap)
{
	int	count;

	count = 0;
	if (*fmt == 'c')
		count += ft_putchar_c(va_arg(*ap, int));
	else if (*fmt == 's')
		count += ft_putstr_c(va_arg(*ap, char *));
	else if (*fmt == 'p')
		count += ft_putaddress_c(va_arg(*ap, unsigned long long));
	else if (*fmt == 'd')
		count += ft_putnbr_c(va_arg(*ap, int));
	else if (*fmt == 'i')
		count += ft_putnbr_c(va_arg(*ap, int));
	else if (*fmt == 'u')
		count += ft_putunbr_c(va_arg(*ap, unsigned int));
	else if (*fmt == 'x')
		count += ft_puthex_c(va_arg(*ap, unsigned int), 'x');
	else if (*fmt == 'X')
		count += ft_puthex_c(va_arg(*ap, unsigned int), 'X');
	else if (*fmt == '%')
		count += ft_putchar_c('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		size;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			size = ft_judge(fmt, &ap);
			if (size < 0)
				return (-1);
			else
				count += size;
		}
		else
			count += ft_putchar_c(*fmt);
		fmt++;
	}
	va_end(ap);
	return (count);
}

// int	main()
// {
// 	int count;
// 	//char c = '9';
// 	//char *s = "abcd";
// 	//int i = -2147483648;
// 	//unsigned int ui = 2147483647;
// 	//count = ft_printf(" %u ", -1);
// 	//printf("%d", a);
// 	// count = ft_printf("abc%q ", -1);
// 	// printf("\n");
// 	// printf("%d", count);
// 	ft_printf(" %p %p ", 0, 0);
// 	printf(" %p %p ", 0, 0);
// }
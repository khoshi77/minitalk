#include "minitalk.h"
#include "./ft_printf/ft_printf.h"

int	check_pid(pid_t pid)
{
	errno = 0;
	kill(pid, 0);
	if (errno != 0)
		return (1);
	return (0);
}

int	send_char(pid_t pid, char c)
{
	int	i;
	int	error_flag;

	i = 0;
	error_flag = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			error_flag = kill(pid, SIGUSR2);
		else
			error_flag = kill(pid, SIGUSR1);
		if (error_flag == -1)
			return (-1);
		i++;
		usleep(50);
	}
	return (0);
}

int	send_text(pid_t pid, char *text)
{
	int	i;
	int	error_flag;

	i = 0;
	error_flag = 0;
	while (text[i])
	{
		error_flag = send_char(pid, text[i]);
		if (error_flag < 0)
			return (-1);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		error_flag;

	error_flag = 0;
	if (ac != 3)
		return (0);
	pid = (pid_t)ft_atoi(av[1]);
	if (pid < 1 || check_pid(pid))
		return (ft_printf("pid error\n"), 0);
	error_flag = send_text(pid, av[2]);
	if (error_flag == -1)
		return (ft_printf("kill error\n"), 0);
	return (0);
}

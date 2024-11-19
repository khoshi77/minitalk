#include "minitalk.h"
#include "./ft_printf/ft_printf.h"

static int	fin_text(char *text, int j, siginfo_t *info)
{
	ft_printf("%s\n", text);
	(void) *info;
	ft_bzero(text, j);
	return (0);
}

static	void	server_handle(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static int	j;
	static char	c;
	static char	text[BUFSIZE];

	(void) ucontext;
	if (sig == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
			j = fin_text(text, j, info);
		else
			text[j++] = c;
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server pid : %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = server_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

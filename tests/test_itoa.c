#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <bsd/string.h>

void	leftcat(char *s, char c)
{
	int	len;

	len = strlen(s);
	while (len)
	{
		s[len] = s[len - 1];
		len--;
	}
	s[0] = c;
}

char	*ft_itoa(int n)
{
	char			*nbr;
	long			long_nb;

	if (!(nbr = malloc(sizeof(char) * 12)))
		return (NULL);
	memset(nbr, 0, 12);
	long_nb = n;
	if (long_nb == 0)
	{
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	if (n < 0)
		long_nb *= -1;
	while (long_nb > 0)
	{
		leftcat(nbr, (char)(long_nb % 10) + '0');
		long_nb /= 10;
	}
	if (n < 0)
		leftcat(nbr, '-');
	return (nbr);
}

int main(void)
{
	char *i1 = ft_itoa(-623);
	char *i2 = ft_itoa(156);
	char *i3 = ft_itoa(-2147483648);

	printf("INT_MIN: %d\n", INT_MIN);

	if (strcmp(i1, "-623"))
	{
		printf("Fail -623: %s\n", i1);
	}
	if (strcmp(i2, "156"))
	{
		printf("Fail 156: %s\n", i2);
	}
	if (strcmp("-2147483648", i3))
	{
		printf("Fail -2147483648: %s\n", i3);
	}
	printf("success\n");
}
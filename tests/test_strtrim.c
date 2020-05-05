#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short	is_in_set(char const c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	unsigned int	j;
	unsigned int	i;

	if (!s1 || s1[0] == '\0' || !set || set[0] == '\0')
		return (char*)(s1);
	if (!(trimmed = malloc(sizeof(char) * (strlen(s1) + 1))))
		return (NULL);
	j = 0;
	while (s1[j])
	{
		if (is_in_set(s1[j], set))
			j++;
		else
			break ;
	}
	i = 0;
	while (s1[j])
		trimmed[i++] = s1[j++];
	if (i > 0)
	{
		while (is_in_set(trimmed[i - 1], set))
		{
			trimmed[i - 1] = '\0';
			i--;
		}
	}
	trimmed[i] = '\0';
	return (trimmed);
}

int main()
{
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *s2 = "";
	char *ret = ft_strtrim(s1, " \n\t");

	if (!strcmp(ret, s2))
	{
		printf("Success\n");
	}
	else
	{
		printf("Failed\n");
		printf("Failed\ns2: %s\nret: %s\n", s2, ret);
	}
	return (0);
}
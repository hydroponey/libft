#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ft_strlen strlen

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

unsigned int	get_trimmed_len(char const *s1, char const *set)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (s1[i])
	{
		if (is_in_set(s1[i], set))
			i++;
		else
			break;
	}
	printf("start trim: %d %s\n", i, &s1[i]);
	while (s1[i])
	{
		len++;
		i++;
	}
	while (i > 0 && is_in_set(s1[i - 1], set))
	{
		len--;
		i--;
	}
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = 0;
	if (!s1 || s1[0] == '\0' || !set || set[0] == '\0')
		return (char*)(s1);
	if (!(trimmed = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[j])
	{
		if (is_in_set(s1[j], set))
			j++;
		else
			break ;
	}
	while (s1[j])
		trimmed[i++] = s1[j++];
	while (i > 0 && is_in_set(trimmed[i - 1], set))
	{
		trimmed[i-- - 1] = '\0';
	}
	trimmed[i] = '\0';
	return (trimmed);
}

int main()
{
	char *s1 = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
	char *s2 = "Hello \t  Please\n Trim me !";
	int r_size = strlen(s2);
	int size = get_trimmed_len(s1, " \n\t");

	printf("size: %d\n", size);

	if (size == r_size + 1)
	{
		printf("Success\n");
	}
	else
	{
		printf("Failed\n");
	}
	return (0);
}
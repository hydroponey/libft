#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strndup(char *str, unsigned int n)
{
    unsigned int    len;
    unsigned int    max;
    char            *copy;
    unsigned int    i;

    len = strlen(str);
    max = (len <= n) ? len : n;
    if (!(copy = malloc(sizeof(char) * (max + 1))))
        return (NULL);
    i = 0;
    while (i < max)
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

int     get_string_size(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != c)
        i++;
    return (i);
}

int		get_elem_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count++;
		i += get_string_size(&str[i], c);
	}
	return (count);
}

char    **ft_split(const char *str, char c)
{
    char    **tab;
    int     i;
    int     j;
    int     len;
    int     string_len;

	if (!str || str[0] == '\0')
		return (NULL);
    if ((tab = malloc(sizeof(char *) * (strlen(str) + 1))) == NULL)
        return (NULL);
    i = 0;
    j = 0;
    len = strlen(str) + 1;
    while (i < len)
    {
        if (str[i] != c)
        {
            string_len = get_string_size((char *)&str[i], c);
            tab[j++] = ft_strndup((char *)&str[i], string_len);
            i += string_len;
        }
        i++;
    }
    tab[j] = 0;
    return (tab);
}

int main()
{
	char *s = "      split       this for   me  !       ";
	char **result = ft_split(s, ' ');
	int i = 0;

	while (result[i])
	{
		printf("result[%d]: %s|\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
}
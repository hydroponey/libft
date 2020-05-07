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

int     get_string_size(const char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != c)
        i++;
    return (i);
}

int		get_elem_count(const char *str, char c)
{
	int	i;
	int	count;
	int	len;
	int	string_len;

	len = strlen(str);
	i = 0;
	string_len = 0;
	count = 0;
	while (str[i] && i < len)
	{
		string_len = get_string_size(&str[i], c);
		if (string_len == 0)
		{
			i += 1;
		}
		else
		{
			i += string_len;
			count++;
		}
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
    if ((tab = malloc(sizeof(char *) * (get_elem_count(str, c) + 1))) == NULL)
        return (NULL);
    i = 0;
    j = 0;
    len = strlen(str);
    while (i < len)
    {
        if (str[i] != c)
        {
            string_len = get_string_size(&str[i], c);
            tab[j++] = ft_strndup((char *)&str[i], string_len);
            i += string_len;
        }
		i++;
    }
    tab[j] = NULL;
	printf("j at end: %d\n", j);
    return (tab);
}

int main()
{
	char	**expected = (char*[6]){"split  ", "this", "for", "me", "!", NULL};
	char	*s = "split  ||this|for|me|||||!|";
	int		i = 0;
	char	**result = ft_split(s, '|');


	while (result[i]) {
		printf("result[%d]: %s |", i, result[i]);
		printf(" expected: %s\n", (*expected));
		free(result[i]);
		i++;
		expected++;
	}
	free(result);
	printf("Success\n");
}
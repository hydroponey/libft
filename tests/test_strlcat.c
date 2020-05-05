#include <stdio.h>
#include <bsd/string.h>

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	ret_len;
	size_t	i;
	size_t	j;

	dest_len = strlen(dest);
	src_len = strlen(src);
	ret_len = src_len + size;
	if (size == 0 || dest_len >= size)
		return (ret_len);
	if (src_len > size)
		ret_len = src_len;
	i = 0;
	j = dest_len;
	if (src_len < (size - dest_len - 1))
	{
		printf("src_len < (size - dest_len - 1)\n");
		while (src[i])
			dest[j++] = src[i++];
		dest[j] = '\0';
	}
	else
	{
		printf("else\n");
		while (src[i] && i < (size - dest_len - 1))
			dest[j++] = src[i++];
		if (i < (size - dest_len))
			dest[j] = '\0';
	}
	return (ret_len);
}

int main()
{
    char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + strlen("there is no stars in the sky");

	strlcat(buff1, str, max);
	ft_strlcat(buff2, str, max);
	if (!strcmp(buff1, buff2))
	{
		printf("Success\n");

	}
	else
	{
		printf("Failed\nmax: %ld\n", max);
		printf("buff1: %s\nbuff2: %s\n", buff1, buff2);
	}
    return 0;
}
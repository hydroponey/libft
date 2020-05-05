#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*data;
	size_t			i;

	if (!(data = malloc(nmemb * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		data[i] = 0;
		i++;
	}
	return (data);
}


int main()
{
	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	if (memcmp(d1, d2, size * sizeof(int)))
		printf("Fail\n");
	free(d1);
	free(d2);
	printf("OK");
	return (0);
}
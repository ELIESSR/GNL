#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int 	line;

	line = 1;
	fd = open("prueba.txt", O_RDONLY);
	while (line <= 10)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		printf("%s", str);
		line++;
		free(str);
	}
	system("leaks -q a.out");
	close(fd);
	return (0);
}
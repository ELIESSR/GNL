#include "get_next_line.h"

int	main(void)
{
	char	*file;
	int		fd;
	char	*str;

	file = "Prueba.txt";
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
		free(str);
		close(fd);
	}
	system("leaks -q a.out");
	return(0);
}
int main()
{
	int fd = open("prueba3.txt", O_RDONLY);
	char *manolo;
	manolo = get_next_line(fd);
	printf("%s", manolo);
	manolo = get_next_line(fd);
	printf("%s", manolo);
	manolo = get_next_line(fd);
	printf("%s", manolo);
	manolo = get_next_line(fd);
	printf("%s", manolo);
	manolo = get_next_line(fd);
	printf("%s", manolo);
	close(fd);
	return 0;
}
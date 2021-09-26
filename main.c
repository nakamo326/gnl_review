//gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=5

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char *line;
	int fd;

	(void)argc;
	(void)argv;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	//fd = 111;
	while ((line = get_next_line(fd)) != NULL)
	{
			printf("READ:%s", line);
			free(line);
			line = NULL;
	}
	close(fd);
	return 0;
}

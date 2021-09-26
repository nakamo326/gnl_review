
//gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=5

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int i;
	int j;
	int fd[3];
	char *line;

	fd[0] = open("bonus1.txt", O_RDONLY);
	fd[1] = open("bonus2.txt", O_RDONLY);
	fd[2] = 15;

	i = 0;
	j = 0;
	while (i < 27)
	{
		line = get_next_line(fd[j]);
		if (line)
		{
			printf("%d: %s", j, line);
			free(line);
		}
		if (line = NULL)
			printf("%d: NULL\n", j);
		i++;
		j++;
		if (j == 3)
			j = 0;
	}

	return (0);
}

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <bits/types.h> 

int main()
{
	int 	fd;
	char	ch = '\0';

	//create file.hole and error check
	if ((fd = creat("file.hole", O_RDWR)) < 0)  {
		perror("creat");
		exit(1);
	}

	//set the file offset at 1023
	if (lseek(fd, 1023, SEEK_SET) < 0)  {
		perror("lseek");
		exit(1);
	}
	//fill the empty space to ch(\0)
	write(fd, &ch, 1);

	close(fd);
}


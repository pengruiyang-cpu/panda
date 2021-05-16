/* Copyright (C) 2021 Rain */

/* This file is part of Panda. */

/* 
  Cunix is free software: you can redistribute it and/or modify 
  it under the terms of the GNU General Public License as published by 
  the Free Software Foundation, either version 3 of the License, or 
  (at your option) and later version. 
*/

/*
  Panda is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  GNU General Public License for more details. 
*/

/*
  You should have received a copy of the GNU General Public License 
   along with Panda. If not, see <https://www.gnu.org/licenses/>.  
*/




#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>



int main(int argc, const char **argv) {
	if (argc == 1) {
		printf("%s: fatal error: no input files\n", argv[0]);
		printf("compilation terminated. \n");

		return 1;
	}


	/* in_fd: file descriptor of input file */
	/* in_size: input file size */
	/* buffer: file content */


	int in_fd = open(argv[1], O_RDONLY);
	size_t in_size;
	char *buffer;


	in_size = lseek(in_fd, 0, SEEK_END);
	lseek(in_fd, 0, SEEK_SET);

	buffer = (char *) malloc(in_size);
	assert(buffer != NULL);

	/* read from input file */
	read(in_fd, buffer, in_size);

	/* compile input file */
	/* do_compile(fd) */

	printf("%s\n", buffer);


	free(buffer);
	close(in_fd);


	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:23:50 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/19 11:50:06 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// static void  check_leaks(void){
// 	system("leaks -q a.out");
// }

/**
 * A file descriptor is a number that uniquely identifies an 
 * open file in a computer's operating system. It describes 
 * a data resource, and how that resource may be accessed. 
 * 
 * When a process makes a successful request to open a file, 
 * the kernel returns a file descriptor which points to an entry 
 * in the kernel's global file table. The file table entry contains 
 * information such as the inode of the file, byte offset, and the 
 * access restrictions for that data stream (read-only, write-only, etc.).

 * 
 * 0 -> Standard input (read-only) -> keyboard
 * 1 -> Standard output	(write-only)-> screen
 * 2 -> Standard error (write-only) -> screen
 * 3 -> read-write -> devuelve la ruta del archivo que se ha abierto
 * 
 * @return int 
 */

int main(){

	int fd = open("./texts/giant_line_nl.txt", O_RDONLY);
	int fd1 = open("./texts/giant_line_nl.txt", O_RDONLY);
	int fd2 = open("./texts/giant_line_nl.txt", O_RDONLY);
	char *line;
	char *line1;
	char *line2;
	int numLines = 3;
	printf("fd: %d\n", fd);
	printf("fd1: %d\n", fd1);
	printf("fd2: %d\n", fd2);
	for (int i = 0; i < numLines; i++) {
		line = get_next_line(fd);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		printf("%s\n", line);
		printf("%s\n", line1);
		printf("%s\n", line2);
		free(line);
	}
	//close(fd);
	//system("leaks -q a.out");
	return (0);
}
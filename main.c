/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:23:50 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/21 14:53:30 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void check_leaks();
// static void  check_leaks(void){
// 	("leaks -q a.out");
// }

int main(){

	int fd = open("./text.txt", O_RDONLY);
	char *line;
	int numLines = 3;
	
	for (int i = 0; i < numLines; i++) {
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	check_leaks();
	//atexit(check_leaks);
	return (0);
}


/* int	main(void)
{
	int	file;
	file = open("test.txt", O_RDONLY);
	for (int i = 0; i < 3; i++){
		char *cozas = get_next_line(file);
		printf("%s", cozas);
		free(cozas);
	}
	return (0);
} */
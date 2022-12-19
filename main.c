/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:23:50 by adrperez          #+#    #+#             */
/*   Updated: 2022/12/19 10:11:10 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// static void  check_leaks(void){
// 	system("leaks -q a.out");
// }

int main(){

	int fd = open("./texts/mobyDick.txt", O_RDONLY);
	char *line;
	int numLines = 3;
	
	for (int i = 0; i < numLines; i++) {
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	//close(fd);
	//system("leaks -q a.out");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:23:50 by adrperez          #+#    #+#             */
/*   Updated: 2022/11/10 11:02:47 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// static void  check_leaks(void){
// 	system("leaks -q a.out");
// }

int main(){

	int fd = open("text.txt", O_RDONLY);
	char *line;
	int numLines = 1;
	
	for (int i = 0; i < numLines; i++) {
		line = get_next_line(fd);
		printf("---%s", line);
	}
	close(fd);
	// atexit(check_leaks);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:33:21 by haseo             #+#    #+#             */
/*   Updated: 2021/02/03 20:03:52 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	char* line;
	int	check;
	int	fd;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	while ((check = get_next_line(fd, &line)) > 0)
	{
		printf("%d %s\n", i++, line);
		free(line);
	}
	printf("%d %s\n", i, line);
	free(line);
	//system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leask result");
	//while(1);
	return (0);
}

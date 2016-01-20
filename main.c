/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 09:09:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/19 09:16:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		exit(-1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(-1);
	char *line;
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
	}
	return (0);
}

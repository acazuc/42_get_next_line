/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:25:17 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 16:42:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
	char	*line;
	int		fd;
	int		result;
	int		i;

	i = 1;
	fd = open("test", O_RDONLY);
	while ((result = get_next_line(fd, &line)))
	{
		ft_putstr("Line number ");
		ft_putnbr(i);
		ft_putendl(": ");
		ft_putendl(line);
		i++;
	}
	close(fd);
}

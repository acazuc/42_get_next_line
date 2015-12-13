/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:25:17 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/07 09:37:29 by acazuc           ###   ########.fr       */
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
	int		j;

	j = 0;
	while (j < 10)
	{
		i = 1;
		fd = open("test", O_RDONLY);
		while ((result = get_next_line(fd, &line)) == 1)
		{
			ft_putstr("Line number ");
			ft_putnbr(i);
			ft_putstr(": ");
			ft_putendl(line);
			i++;
		}
		if (result == -1)
			ft_putendl("ERROR");
		ft_putendl("");
		close(fd);
		j++;
	}
}

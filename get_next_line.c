/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:22:35 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/29 16:43:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>
#include <unistd.h>

static int		ft_list_add(t_list **list, char *data, size_t len)
{
	t_list		*item;

	if (*list)
	{
		item = *list;
		while (item->next)
			item = item->next;
		if (!(item->next = malloc(sizeof(t_list))))
			return (0);
		item->next->content = data;
		item->next->content_size = len;
		item->next->next = NULL;
	}
	else
	{
		if (!(item = malloc(sizeof(t_list))))
			return (0);
		item->content = data;
		item->content_size = len;
		item->next = NULL;
		*list = item;
	}
	return (1);
}

static long		get_eol(char *data)
{
	size_t		i;

	i = 0;
	while (i < BUFFER_SIZE && data[i])
	{
		if (data[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_do_final(char **line, t_list *list)
{
	t_list		*item;
	t_list		*next;
	long		eol_i;
	size_t		i;

	item = list;
	i = 1;
	while (item)
	{
		eol_i = get_eol(item->content);
		i += eol_i == -1 ? item->content_size : eol_i;
		item = item->next;
	}
	if (!(*line = malloc(sizeof(**line) * i)))
		return (0);
	(*line)[0] = '\0';
	item = list;
	i = 0;
	while (item)
	{
		eol_i = get_eol(item->content);
		i = eol_i == -1 ? item->content_size : eol_i;
		ft_strncat(*line, item->content, i);
		free(item->content);
		next = item->next;
		free(item);
		item = next;
	}
	return (1);
}

static int		get_next_line_main(int const fd, char **line, t_list *list
		, char **start)
{
	long		eol_i;
	int			readed;
	char		*buffer;

	if ((buffer = malloc(sizeof(*buffer) * BUFFER_SIZE)))
		while ((readed = read(fd, buffer, BUFFER_SIZE)) != -1)
		{
			if (!readed)
				return (0);
			if (!ft_list_add(&list, buffer, readed))
				return (-1);
			if (readed < BUFFER_SIZE || (eol_i = get_eol(buffer)) != -1)
			{
				if (readed < BUFFER_SIZE)
					buffer[readed] = '\0';
				eol_i = get_eol(buffer);
				*start = ft_strsub(buffer, eol_i + 1, readed - 1 - eol_i);
				if (!ft_do_final(line, list))
					return (-1);
				return ((*start && ft_strlen(*start) > 0) || readed);
			}
			if (!(buffer = malloc(sizeof(*buffer) * BUFFER_SIZE)))
				return (-1);
		}
	return (-1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*start;
	t_list		*list;
	long		eol_i;

	list = NULL;
	if (!line)
		return (-1);
	*line = NULL;
	if (start && ft_strlen(start) > 0)
	{
		if ((eol_i = get_eol(start)) != -1)
		{
			*line = ft_strsub(start, 0, eol_i);
			start = ft_strsub(start, eol_i + 1, ft_strlen(start) - 1);
			return (1);
		}
		else if (!ft_list_add(&list, ft_strdup(start), ft_strlen(start)))
			return (-1);
	}
	return (get_next_line_main(fd, line, list, &start));
}

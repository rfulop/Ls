/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:19:47 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/01 18:07:23 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_list	*ft_check_fd(const int fd, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static int		ft_make_line(char *str, char **line)
{
	int i;

	i = 0;
	if (ft_strchr(str, '\n'))
	{
		while (str[i] && str[i] != '\n')
			++i;
	}
	else
		i = ft_strlen(str);
	if (i)
		*line = ft_strndup(str, i);
	if (str[i] == '\n')
		return (++i);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	int				len;
	char			*str;
	char			buf[BUFF_SIZE];
	t_list			*begin_list;
	static t_list	*list;

	if (fd < 0 || read(fd, buf, 0))
		return (-1);
	begin_list = list;
	list = ft_check_fd(fd, &begin_list);
	len = 0;
	while (!ft_strchr(list->content, '\n') && (len = read(fd, buf, BUFF_SIZE)))
		list->content = ft_strnjoin(list->content, buf, len);
	len = ft_make_line((char*)list->content, line);
	if (*(char*)list->content == '\0')
	{
		ft_memdel((void**)list);
		return (0);
	}
	str = list->content;
	list->content = ft_strdup(list->content + len);
	free(str);
	list = begin_list;
	return (1);
}

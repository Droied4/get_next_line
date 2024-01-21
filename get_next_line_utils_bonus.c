/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:45:36 by deordone          #+#    #+#             */
/*   Updated: 2024/01/21 14:21:24 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_gnl_list	*ft_lastnode(t_gnl_list **lst)
{
	t_gnl_list	*temp;

	temp = *lst;
	if (temp == NULL)
		return (temp);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

int	found_newline(t_gnl_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n' || lst->content[i] == '\0')
				return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}

int	ft_contsize(t_gnl_list *temp)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
				return (++k);
			++i;
			++k;
		}
		temp = temp->next;
	}
	return (k);
}

int	ft_cpylst(t_gnl_list *temp, char *line, int displacer)
{
	int	i;

	while (temp)
	{
		i = 0;
		while (temp->content[i] != '\0')
		{
			if (temp->content[i] == '\n')
				return (line[displacer++] = temp->content[i]);
			else
				line[displacer++] = temp->content[i++];
		}
		temp = temp->next;
	}
	return (displacer);
}

void	ft_del(t_gnl_list **lst)
{
	t_gnl_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

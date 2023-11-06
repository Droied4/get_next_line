/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:36:11 by deordone          #+#    #+#             */
/*   Updated: 2023/11/06 18:22:27 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lastnode(t_list *lst, int flag)
{
	t_list	*temp;

	if (flag == 2)
	{
		temp = lst;
		if (temp == NULL)
			return (temp);
		while (temp->next != NULL)
			temp = temp->next;
		return (temp);
	}
	if (flag == 1)
	{
		while (lst)
		{
			temp = (lst)->next;
			free((lst)->content);
			free(lst);
			lst = temp;
		}
		lst = NULL;
	}
	return (NULL);
}

int	found_newline(t_list *lst)
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

int	ft_contsize(t_list *temp)
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
			{
				++k;
				return (k);
			}
			++i;
			++k;
		}
		temp = temp->next;
	}
	return (k);
}

int	ft_cpylst(t_list *temp, char *line, int displacer)
{
	int	i;

	i = 0;
	while (temp->content[i] != '\0')
	{
		if (temp->content[i] == '\n')
		{
			line[displacer] = temp->content[i];
			++displacer;
			return (displacer);
		}
		else
		{
			line[displacer] = temp->content[i];
			++i;
			++displacer;
		}
	}
	return (displacer);
}

void	ft_del(t_list **lst, t_list *cleanod, char *buf)
{
	t_list	*temp;

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
	if (cleanod->content[0])
		*lst = cleanod;
	else
	{
		free(buf);
		free(cleanod);
	}
}

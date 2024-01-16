/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_group_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:40:52 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/15 14:48:09 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_group(t_list **lst, int group)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		if (current->group == group)
			return (1);
		current = current->next;
	}
	return (0);
}

void	set_group3(t_list **lst)
{
	t_list	*current;
	int		lst_len;

	current = *lst;
	lst_len = stack_len(*lst);
	while (current)
	{
		if (current->index <= (lst_len / 3))
			current->group = 1;
		else if (current->index <= ((lst_len / 3) * 2))
			current->group = 2;
		else
			current->group = 3;
		current = current->next;
	}
}

void	set_group6(t_list **lst)
{
	t_list	*current;
	int		lst_len;

	current = *lst;
	lst_len = stack_len(*lst);
	while (current)
	{
		if (current->index <= (lst_len / 6))
			current->group = 1;
		else if (current->index <= ((lst_len / 6) * 2))
			current->group = 2;
		else if (current->index <= ((lst_len / 6) * 3))
			current->group = 3;
		else if (current->index <= ((lst_len / 6) * 4))
			current->group = 4;
		else if (current->index <= ((lst_len / 6) * 5))
			current->group = 5;
		else
			current->group = 6;
		current = current->next;
	}
}

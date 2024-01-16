/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:55:48 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/15 16:46:09 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_midpoint(t_list **lst)
{
	t_list	*current;
	int		mid_point;
	int		i;

	i = 1;
	current = *lst;
	mid_point = stack_len(*lst) / 2;
	if (stack_len(*lst) % 2 != 0)
		mid_point += 1;
	while (i < mid_point)
	{
		current = current->next;
		i++;
	}
	return (current);
}

t_list	*get_min(t_list **lst)
{
	t_list	*temp;
	t_list	*min;

	temp = *lst;
	min = temp;
	while (temp)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	sort_tree(t_list **lst)
{
	long	t;
	long	m;
	long	b;

	if (!*lst)
		return ;
	if (stack_len(*lst) < 3)
		do_sa(lst, 0);
	else
	{
		t = (*lst)->data;
		m = (*lst)->next->data;
		b = (*lst)->next->next->data;
		if (t > m && t > b)
			do_ra(lst, 0);
		else if (m > t && m > b)
			do_rra(lst, 0);
		if (!is_sorted(lst))
			do_sa(lst, 0);
	}
}

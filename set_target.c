/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:19:45 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/16 19:55:04 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_target(t_list **hold)
{
	t_list	*current_hold;

	current_hold = *hold;
	while (current_hold)
	{
		current_hold->target = NULL;
		current_hold = current_hold->next;
	}
}

/* target la valeur maximum de A la plus proche de l'element de B*/
void	set_target(t_list **lst, t_list **hold)
{
	t_list	*current_lst;
	t_list	*current_hold;

	current_hold = *hold;
	while (current_hold)
	{
		current_lst = *lst;
		while (current_lst)
		{
			if (!current_hold->target && current_lst->data > current_hold->data)
				current_hold->target = current_lst;
			else if (current_hold->target
				&& current_hold->target->data > current_lst->data
				&& current_lst->data > current_hold->data)
				current_hold->target = current_lst;
			current_lst = current_lst->next;
		}
		current_hold = current_hold->next;
	}
}

/* target la valeur minimium dans A, si aucune valeur max est trouver*/
void	get_target_min(t_list **lst, t_list **hold)
{
	t_list	*current_lst;
	t_list	*current_hold;
	t_list	*min;

	current_hold = *hold;
	min = get_min(lst);
	while (current_hold)
	{
		current_lst = *lst;
		while (current_lst)
		{
			if (!current_hold->target && current_lst->data < current_hold->data)
				current_hold->target = min;
			current_lst = current_lst->next;
		}
		current_hold = current_hold->next;
	}
}

/* compte le nombre de coup pour mettre chaque element a la tete de liste*/
void	count_cost(t_list **lst)
{
	int		median;
	int		lst_len;
	t_list	*current;

	current = *lst;
	lst_len = stack_len(*lst);
	median = lst_len / 2;
	if (lst_len % 2 != 0)
		median += 1;
	while (current)
	{
		if (current->position <= median)
			current->cheapest = current->position - 1;
		else if (current->position > median)
			current->cheapest = (lst_len - current->position) + 1;
		current = current->next;
	}
}

/* compare le cout total de chaque element avec le cout de l'element actuel*/
t_list	*get_cheapest(t_list **hold)
{
	t_list	*current_hold;
	t_list	*target_cheapest;
	int		cheapest_cost;
	int		cost;

	current_hold = *hold;
	target_cheapest = current_hold;
	while (current_hold)
	{
		cheapest_cost = target_cheapest->cheapest
			+ target_cheapest->target->cheapest;
		cost = current_hold->cheapest + current_hold->target->cheapest;
		if (cost < cheapest_cost)
			target_cheapest = current_hold;
		current_hold = current_hold->next;
	}
	return (target_cheapest);
}

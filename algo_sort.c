/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:56:00 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/15 17:02:05 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_list **lst)
{
	t_list	*min;
	t_list	*median;

	min = get_min(lst);
	median = get_midpoint(lst);
	while (min->cheapest)
	{
		if (min->position <= median->position)
			do_ra(lst, 0);
		else
			do_rra(lst, 0);
		min->cheapest--;
	}
}

void	push_until_tree(t_list **lst, t_list **hold)
{
	if (stack_len(*lst) < 100)
	{
		while (stack_len(*lst) > 3)
			do_pb(lst, hold, 0);
	}
}

void	set_groups(t_list **lst, t_list **hold)
{
	if (stack_len(*lst) >= 100 && stack_len(*lst) <= 200)
		set_group3(lst);
	else if (stack_len(*lst) > 200 && stack_len(*lst) <= 500)
		set_group6(lst);
	move_group(lst, hold);
	sort_tree(lst);
}

void	sort_algo(t_list **lst, t_list **hold)
{
	while (!is_empty(*hold))
	{
		reset_target(hold);
		set_target(lst, hold);
		get_target_min(lst, hold);
		get_position(*hold);
		get_position(*lst);
		count_cost(lst);
		count_cost(hold);
		set_top_top(lst, hold);
	}
}

void	push_swap(t_list **lst, t_list **hold)
{
	push_until_tree(lst, hold);
	set_groups(lst, hold);
	sort_algo(lst, hold);
	if (!is_sorted(lst))
	{
		get_position(*lst);
		count_cost(lst);
		final_sort(lst);
	}
}

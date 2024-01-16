/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:55:51 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/15 13:49:48 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	above_median(t_list **lst, t_list *cheapest)
{
	t_list	*median;

	median = get_midpoint(lst);
	if (cheapest->position <= median->position)
		return (1);
	return (0);
}

static void	same_half(t_list **lst, t_list **hold, t_list *cheapest)
{
	if (above_median(lst, cheapest->target) && above_median(hold, cheapest))
	{
		while (cheapest->target->cheapest && cheapest->cheapest)
		{
			do_rr(lst, hold, 0);
			cheapest->target->cheapest--;
			cheapest->cheapest--;
		}
	}
	else if (!above_median(lst, cheapest->target) && !above_median(hold,
			cheapest))
	{
		while (cheapest->target->cheapest && cheapest->cheapest)
		{
			do_rrr(lst, hold, 0);
			cheapest->target->cheapest--;
			cheapest->cheapest--;
		}
	}
}

static void	set_toplst(t_list **lst, t_list *cheapest)
{
	if (above_median(lst, cheapest->target))
	{
		while (cheapest->target->cheapest)
		{
			do_ra(lst, 0);
			cheapest->target->cheapest--;
		}
	}
	else if (!above_median(lst, cheapest->target))
	{
		while (cheapest->target->cheapest)
		{
			do_rra(lst, 0);
			cheapest->target->cheapest--;
		}
	}
}

static void	set_tophold(t_list **hold, t_list *cheapest)
{
	if (above_median(hold, cheapest))
	{
		while (cheapest->cheapest)
		{
			do_rb(hold, 0);
			cheapest->cheapest--;
		}
	}
	else if (!above_median(hold, cheapest))
	{
		while (cheapest->cheapest)
		{
			do_rrb(hold, 0);
			cheapest->cheapest--;
		}
	}
}

void	set_top_top(t_list **lst, t_list **hold)
{
	t_list	*cheapest;

	cheapest = get_cheapest(hold);
	same_half(lst, hold, cheapest);
	set_toplst(lst, cheapest);
	set_tophold(hold, cheapest);
	do_pa(hold, lst, 0);
}

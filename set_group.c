/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:41:45 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/15 14:57:55 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_rr_condition(t_list *lst, t_list *hold, int group)
{
	return (((hold->group == group + 1 && stack_len(hold) >= 2)
			&& hold->next->group == group && lst->next->group == group)
		|| (lst->next->group == group + 1 && lst->group != group
			&& lst->group != (group + 1)));
}

static int	check_rb_condition(t_list *hold, int group)
{
	return ((hold->group == group + 1 && stack_len(hold) >= 2)
		&& (hold->next->group == group));
}

void	move_group(t_list **lst, t_list **hold)
{
	int (i) = 1;
	while (stack_len(*lst) > 3 && i <= 5)
	{
		while ((check_group(lst, i) || check_group(lst, i + 1))
			&& stack_len(*lst) > 3)
		{
			if ((*lst)->group == i || (*lst)->group == i + 1)
			{
				do_pb(lst, hold, 0);
				if (check_rr_condition(*lst, *hold, i))
					do_rr(lst, hold, 0);
				else if (check_rb_condition(*hold, i))
					do_rb(hold, 0);
			}
			else
				do_ra(lst, 0);
		}
		i += 2;
	}
	while (stack_len(*lst) > 3)
		do_pb(lst, hold, 0);
}

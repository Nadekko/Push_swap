/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:09:31 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/16 18:46:21 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	lstprint(t_list *lst)
// {
// 	while (lst)
// 	{
// 		ft_printf("%d ", lst->data);
// 		lst = lst->next;
// 	}
// 	ft_printf("\n");
// }

static void	handle_free(t_list **a, t_list **b, char *str)
{
	lst_clear(a);
	lst_clear(b);
	free(str);
	print_error("Error\n");
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

void	parse_command(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		do_sa(a, 1);
	else if (!ft_strncmp(str, "sb\n", 3))
		do_sb(b, 1);
	else if (!ft_strncmp(str, "ss\n", 3))
		do_ss(a, b, 1);
	else if (!ft_strncmp(str, "pa\n", 3))
		do_pa(b, a, 1);
	else if (!ft_strncmp(str, "pb\n", 3))
		do_pb(a, b, 1);
	else if (!ft_strncmp(str, "ra\n", 3))
		do_ra(a, 1);
	else if (!ft_strncmp(str, "rb\n", 3))
		do_rb(b, 1);
	else if (!ft_strncmp(str, "rr\n", 3))
		do_rr(a, b, 1);
	else if (!ft_strncmp(str, "rra\n", 4))
		do_rra(a, 1);
	else if (!ft_strncmp(str, "rrb\n", 4))
		do_rrb(b, 1);
	else if (!ft_strncmp(str, "rrr\n", 4))
		do_rrr(a, b, 1);
	else
		handle_free(a, b, str);
}

void	check_push_swap(t_list **a, t_list **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		parse_command(a, b, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	if (!is_empty(*b))
	{
		lst_clear(a);
		lst_clear(b);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av += 1;
	stack_init(&a, av, ac);
	if (ac == 2)
		free_tab(av);
	check_push_swap(&a, &b);
	if (is_sorted(&a) && is_empty(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}

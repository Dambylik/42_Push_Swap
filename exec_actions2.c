/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:45:58 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/17 13:54:27 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_rr_output(int flag)
{
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
	if (flag == 2)
		ft_putstr_fd("rb\n", 1);
	if (flag == 3)
		ft_putstr_fd("rr\n", 1);
}

void	exec_rr(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*tmp;
	int				flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		tmp->next = NULL;
		stack_add_back(head_a, tmp);
		flag = 1;
	}
	if (*head_b && (*head_b)->next)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		tmp->next = NULL;
		stack_add_back(head_b, tmp);
		flag += 2;
	}
	if (output)
		exec_rr_output(flag);
}

void	exec_rra(t_stack_elem **head, int output)
{
	t_stack_elem	*before_last;

	if (*head && (*head)->next)
	{
		before_last = before_last_stack_elem(*head);
		stack_add_front(head, before_last->next);
		before_last->next = NULL;
		if (output)
			ft_putstr_fd("rra\n", 1);
	}
}

void	exec_rrb(t_stack_elem **head, int output)
{
	t_stack_elem	*before_last;

	if (*head && (*head)->next)
	{
		before_last = before_last_stack_elem(*head);
		stack_add_front(head, before_last->next);
		before_last->next = NULL;
		if (output)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	exec_rrr(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*before_last;
	int				flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		before_last = before_last_stack_elem(*head_a);
		stack_add_front(head_a, before_last->next);
		before_last->next = NULL;
		flag = 1;
	}
	if (*head_b && (*head_b)->next)
	{
		before_last = before_last_stack_elem(*head_b);
		stack_add_front(head_b, before_last->next);
		before_last->next = NULL;
		flag += 2;
	}
	if (flag == 1 && output)
		ft_putstr_fd("rra\n", 1);
	if (flag == 2 && output)
		ft_putstr_fd("rrb\n", 1);
	if (flag == 3 && output)
		ft_putstr_fd("rrr\n", 1);
}

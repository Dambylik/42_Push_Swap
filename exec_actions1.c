/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_actions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:45:51 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/18 12:08:11 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa(t_stack_elem **head, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*next;

	p = *head;
	if (*head && (*head)->next)
	{
		next = (*head)->next;
		(*head)->next = next->next;
		next->next = p;
		(*head) = next;
		if (output)
			ft_putstr_fd("sa\n", 1);
	}
}

void	exec_pb(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*p2;

	if (*head_a)
	{
		p = *head_b;
		p2 = *head_a;
		(*head_a) = (*head_a)->next;
		(*head_b) = p2;
		(*head_b)->next = p;
		if (output)
			ft_putstr_fd("pb\n", 1);
	}	
}

void	exec_pa(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*p2;

	if (*head_b)
	{
		p = *head_a;
		p2 = *head_b;
		(*head_b) = (*head_b)->next;
		(*head_a) = p2;
		(*head_a)->next = p;
		if (output)
			ft_putstr_fd("pa\n", 1);
	}	
}

void	exec_ra(t_stack_elem **head, int output)
{
	t_stack_elem	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		stack_add_back(head, tmp);
		if (output)
			ft_putstr_fd("ra\n", 1);
	}
}

void	exec_rb(t_stack_elem **head, int output)
{
	t_stack_elem	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		stack_add_back(head, tmp);
		if (output)
			ft_putstr_fd("rb\n", 1);
	}
}

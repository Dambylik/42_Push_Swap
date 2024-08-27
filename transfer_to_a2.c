/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_a2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:46:36 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/18 12:13:39 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_score_elem2(int result, t_stack_elem *head, int *ttype)
{
	if (head->b_score + head->a_rscore < result)
	{
		result = head->b_score + head->a_rscore;
		*ttype = 5;
	}
	if (head->b_rscore + head->a_score < result)
	{
		result = head->b_rscore + head->a_score;
		*ttype = 6;
	}
	return (result);
}

int	total_score_elem(t_stack_elem *head, int *ttype)
{
	int	result;
	int	biggest_rscore;

	result = head->b_score;
	*ttype = 1;
	if (head->a_score >= head->b_score)
	{
		result = head->a_score;
		*ttype = 2;
	}
	biggest_rscore = head->a_rscore;
	if (head->b_rscore > biggest_rscore)
		biggest_rscore = head->b_rscore;
	if (result > biggest_rscore)
	{
		result = biggest_rscore;
		if (head->b_rscore > head->a_rscore)
			*ttype = 3;
		else
			*ttype = 4;
	}
	result = total_score_elem2(result, head, ttype);
	return (result);
}

t_stack_elem	*make_decision(t_stack_elem *head, int *transfer_type)
{
	t_stack_elem	*save_point;
	int				best_total_score;
	int				best_rank;
	int				best_transfer_type;

	best_total_score = total_score_elem(head, transfer_type);
	best_rank = head->rank;
	best_transfer_type = *transfer_type;
	save_point = head;
	while (head)
	{
		if (total_score_elem(head, transfer_type) < best_total_score
			|| (total_score_elem(head, transfer_type) == best_total_score
				&& head->rank >= best_rank))
		{
			best_total_score = total_score_elem(head, transfer_type);
			best_rank = head->rank;
			best_transfer_type = *transfer_type;
		}
		head = head->next;
	}
	*transfer_type = best_transfer_type;
	while (save_point->rank != best_rank)
		save_point = save_point->next;
	return (save_point);
}

void	process_decision2(t_stack_elem **head_a, t_stack_elem **head_b,
	t_stack_elem *elem, int *ttype)
{
	if (*ttype == 4)
	{
		while (elem->b_rscore-- > 0 && elem->a_rscore--)
			exec_rrr(head_a, head_b, 1);
		while (elem->a_rscore-- > 0)
			exec_rra(head_a, 1);
	}
	if (*ttype == 5)
	{
		while (elem->b_score-- > 0)
			exec_rb(head_b, 1);
		while (elem->a_rscore-- > 0)
			exec_rra(head_a, 1);
	}
	if (*ttype == 6)
	{
		while (elem->b_rscore-- > 0)
			exec_rrb(head_b, 1);
		while (elem->a_score-- > 0)
			exec_ra(head_a, 1);
	}
}

void	process_decision(t_stack_elem **head_a, t_stack_elem **head_b,
	t_stack_elem *elem, int *ttype)
{
	if (*ttype == 1)
	{
		while (elem->a_score-- > 0 && elem->b_score--)
			exec_rr(head_a, head_b, 1);
		while (elem->b_score-- > 0)
			exec_rb(head_b, 1);
	}
	if (*ttype == 2)
	{
		while (elem->b_score-- > 0 && elem->a_score--)
			exec_rr(head_a, head_b, 1);
		while (elem->a_score-- > 0)
			exec_ra(head_a, 1);
	}
	if (*ttype == 3)
	{
		while (elem->a_rscore-- > 0 && elem->b_rscore--)
			exec_rrr(head_a, head_b, 1);
		while (elem->b_rscore-- > 0)
			exec_rrb(head_b, 1);
	}
	if (*ttype > 3)
		process_decision2(head_a, head_b, elem, ttype);
	exec_pa(head_a, head_b, 1);
}

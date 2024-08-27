/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:45:42 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/18 12:10:08 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_elem
{
	struct s_stack_elem	*next;
	int					value;
	int					a_score;
	int					a_rscore;
	int					b_score;
	int					b_rscore;
	int					rank;
}	t_stack_elem;

//error_handling.c
int				non_valid_arguments(int argc, char **argv);

//libft.c
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
void			free_after_split(char **argv);

//stack_utils.c
t_stack_elem	*stack_init(int argc, char **argv);
int				stack_size(t_stack_elem *stack);

//stack_utils2.c
void			stack_add_front(t_stack_elem **stack, t_stack_elem *new);
void			stack_add_back(t_stack_elem **stack, t_stack_elem *new);
t_stack_elem	*last_stack_elem(t_stack_elem *stack);
t_stack_elem	*before_last_stack_elem(t_stack_elem *stack);
void			free_stack(t_stack_elem **head);

//ft_atoi_ps.c
long long int	ft_atoi_ps(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);

//stack_sort.c
t_stack_elem	*stack_sort(t_stack_elem **head);

//exec_actions1.c
void			exec_sa(t_stack_elem **head, int output);
void			exec_pb(t_stack_elem **head, t_stack_elem **head_b, int output);
void			exec_pa(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);
void			exec_ra(t_stack_elem **head, int output);
void			exec_rb(t_stack_elem **head, int output);

//exec_actions2.c
void			exec_rr(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);
void			exec_rra(t_stack_elem **head, int output);
void			exec_rrb(t_stack_elem **head, int output);
void			exec_rrr(t_stack_elem **head_a, t_stack_elem **head_b,
					int output);

// stack_sort_utils.c
int				is_not_presorted(t_stack_elem *head);
void			final_sort_stack(t_stack_elem **head);
int				find_minmaxmed(t_stack_elem **head,
					int *min, int *max, int *med);
int				*sort_array(int *array, int size, t_stack_elem *head);
void			start_rotating(t_stack_elem **head, int index);

//transfer_to_a.c
void			transfer_to_a(t_stack_elem **head_a, t_stack_elem **head_b);

//transfer_to_a2.c
int				total_score_elem2(int result, t_stack_elem *head, int *ttype);
int				total_score_elem(t_stack_elem *head, int *ttype);
t_stack_elem	*make_decision(t_stack_elem *head, int *transfer_type);
void			process_decision2(t_stack_elem **head_a, t_stack_elem **head_b,
					t_stack_elem *elem, int *ttype);
void			process_decision(t_stack_elem **head_a, t_stack_elem **head_b,
					t_stack_elem *elem, int *ttype);

//ft_split_ps.c
char			**ft_split_ps(char const *s, char c);
int				splited_size(char **words);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:16:53 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *temp_list;

	if (alst && del)
	{
		if (*alst)
		{
			list = *alst;
			temp_list = *alst;
			while (list)
			{
				temp_list = temp_list->next;
				del(list->content, list->content_size);
				free(list);
				list = NULL;
				list = temp_list;
			}
			*alst = NULL;
		}
	}
}

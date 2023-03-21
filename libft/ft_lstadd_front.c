/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:09 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 14:50:02 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstadd_front() adds the node 'new' at the beginning of the list.
 * 
 * lst: the address of a pointer to the first link of the list.
 * new: the address of a pointer to the node to be added to the list.
 *
 * It is necessary to first create a new node with the given data, then make the
 * new node points to the existing head node. Finally, make the new node as the 
 * new head node.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

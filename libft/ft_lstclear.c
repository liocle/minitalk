/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:36:06 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 15:15:49 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstclear() deletes and frees the given node and every successor of that
 * node, using the function 'del' and free(3).
 * Finally, the pointer to the list must be set to NULL.
 *
 * 'lst' is the address of a pointer to a node.
 * 'del' is the address of the function used to delete the content of the node.
 * 
 * In order to clear the whole list, it is necessary to have a temporary node
 * to keep track of the next node, so that we can reach it after deleting
 * the current node:
 *
 * temp = *lst;
 *
 * Now that the head list is bookmarked with temp, it is needed to relink it
 * to point to the next node:
 *
 * *lst = temp->next;
 *
 * Finally, the node that needs to be freed can be deleted using lstdelone()
 * 
 * The process completes when 'lst' = NULL as we clear the list content but 
 * not the list head itself.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp, del);
	}
}

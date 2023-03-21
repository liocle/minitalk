/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:38:10 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 15:31:46 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_lstmap() iterates the list 'lst' and applies the function 'f' on the con-
 * -tent of each node. It creates a new list resulting of the successive
 * applications of the function 'f'. The 'del' function is used to delete the
 * content of a node if needed.
 * 
 * 'lst' is the address of a pointer to a node.
 * 'f' is the address of a function used to iterate on the list.
 * 'del' is the address of the function used to delete the content of a node
 * if needed.
 * 
 * Return value:
 * The new list.
 * NULL if the allocation fails.
 * 
 * Allowed functions malloc() and free().
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

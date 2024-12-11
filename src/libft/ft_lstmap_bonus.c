/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jean.nibaudeau2@outlook.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:24:40 by jenibaud          #+#    #+#             */
/*   Updated: 2024/10/28 11:11:37 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	void	*content;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	cpy = NULL;
	while (lst)
	{
		new = NULL;
		content = f(lst->content);
		if (content)
			new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&cpy, del);
			return (NULL);
		}
		ft_lstadd_back(&cpy, new);
		lst = lst->next;
	}
	return (cpy);
}

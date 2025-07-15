#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;
	t_list	*tmp;

	prev = NULL;
	curr = *begin_list;	 

	while(curr && cmp(curr -> data, data_ref) == 0)
	{
		tmp = curr;
		curr = curr -> next;
		free(tmp);
	}
	if (!curr)
		return;
	else
	{
		prev = curr;
		*begin_list = curr;
		curr = curr -> next;
	}
	while(curr)
	{
		if(cmp(curr -> data, data_ref) == 0)
		{
			tmp = curr;
			prev -> next = curr -> next;	
			curr = curr -> next;
       		free(tmp);
		}
		else
		{
			prev = curr;
			curr = curr -> next;	
		}		
	}	
}


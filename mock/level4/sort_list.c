#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int tmp;
    t_list *head;

    if (!lst)
        return NULL;
    head = lst;
    while (lst && lst->next)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = head;  // restart from head after a swap
        }
        else
            lst = lst->next;
    }
    return head;
}


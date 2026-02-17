#include"header.h"

/*Division of two lists*/
int division(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **res_head,Dlist **res_tail)
{
    *res_head=NULL;
    *res_tail=NULL;
    if(head2==NULL || (head2->next==NULL && head2->data==0))
    {
        printf("Error,Divisor is zero\n");
        return FAILURE;
    }
    int cmp = compare(head1,head2);
    if(cmp==-1)
    {
        insert_first(res_head,res_tail,0);
        return SUCCESS;
    }
    if(cmp==0)
    {
        insert_first(res_head,res_tail,1);
        return SUCCESS;
    }
    //if cmp == 1;
    Dlist *tmp_head=NULL,*tmp_tail=NULL;
    //num1 is copied in tmp_head
    copy_list(head1,&tmp_head,&tmp_tail);
    int count=0;
    while(compare(tmp_head,head2)>=0)
    {
        //first time 10 - 3 = 7
        //nedxt time 7 - 3 = 4
        //next time 4 - 3 = 1
        //next time 1 - 3 = -2 not possible while compring it exit the loop
        Dlist *t_head=NULL,*t_tail=NULL;

        // num1 = 10 num2 = 3   10/3
        if(subtraction(tmp_tail,tail2,&t_head,&t_tail)==FAILURE)
        {
            free_list(&tmp_head,&tmp_tail);
            return FAILURE;
        }
        //10 - 3 = 7
        // tmp_head= &7 tmp_tail = &7
        free_list(&tmp_head,&tmp_tail);
        tmp_head = t_head;
        tmp_tail = t_tail;

        remove_zeros(&tmp_head,&tmp_tail);
        count++;
        //count = 3;
    }
    free_list(&tmp_head,&tmp_tail);
    if(count==0)
    {
        insert_first(res_head,res_tail,0);
        return SUCCESS;
    }
    
    while(count>0)
    {
        int digit = count % 10;
        insert_first(res_head,res_tail,digit);
        count = count / 10;
    }
    return SUCCESS;
}
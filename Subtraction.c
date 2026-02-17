#include"header.h"

/*Subtraction of two list*/
int subtraction(Dlist *tail1,Dlist *tail2,Dlist **res_head,Dlist **res_tail)
{
    *res_head=*res_tail=NULL;
    int d1,d2,borrow=0,diff;

    while(tail1 || tail2)
    {
        if(tail1)
            d1=tail1->data;
        else
            d1=0;
        
        if(tail2)
            d2=tail2->data;
        else
            d2=0;

        if(borrow==1)
        {
            d1=d1-borrow;
            borrow=0;
        }

        if(d1 < d2)
        {
            d1=d1+10;
            borrow=1;
        }
        diff=d1-d2;
        if(insert_first(res_head,res_tail,diff)==FAILURE)
        {
            printf("Sutraction failed\n");
            return FAILURE;
        }
        if(tail1)
            tail1=tail1->prev;
        if(tail2)
            tail2=tail2->prev;
    }
    remove_zeros(res_head,res_tail);
    return SUCCESS;
}
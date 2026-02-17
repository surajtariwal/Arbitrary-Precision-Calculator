#include "header.h"

/*Addition of two lists*/
int addition(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail)
{
    *res_head=*res_tail=NULL;
    int carry = 0;
    int sum, d1, d2;

    while(tail1 || tail2 || carry)
    {
        if(tail1)
            d1=tail1->data;
        else
            d1=0;
        
        if(tail2)
            d2=tail2->data;
        else
            d2=0;

        sum=d1+d2+carry;
        carry=sum/10;
        sum=sum%10;

        if(insert_first(res_head,res_tail,sum)==FAILURE)
        {
            printf("Error occured while adding\n");
            return FAILURE; 
        }

        if(tail1)
            tail1=tail1->prev;
        if(tail2)
            tail2=tail2->prev;
    }

    return SUCCESS;
}
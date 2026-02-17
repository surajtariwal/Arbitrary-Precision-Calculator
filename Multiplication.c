#include"header.h"

/*Multiplication of two lists*/
int multiplication(Dlist *tail1,Dlist *tail2,Dlist **res_head,Dlist **res_tail)
{
    *res_head=*res_tail=NULL;
    Dlist *r1head = NULL,*r1tail = NULL;
    Dlist *t2=tail2;
    int carry,i,count=0,mul;
    while(t2)
    {
        Dlist *r2head=NULL,*r2tail=NULL;
        carry=0;
        Dlist *t1=tail1;
        while(t1)
        {
            mul=((t1->data) * (t2->data)) + carry;
            carry=mul/10;
            mul=mul%10;

            insert_first(&r2head,&r2tail,mul);
            t1=t1->prev;
        }
        if(carry)
            insert_first(&r2head,&r2tail,carry);
        
        for(i=0;i<count;i++)
        {
            insert_last(&r2head,&r2tail,0);
        }
        if(r1head==NULL && r1tail==NULL)
        {
            r1head=r2head;
            r1tail=r2tail;
        }
        else
        {
            Dlist *new_h=NULL,*new_t=NULL;
            addition(r1tail,r2tail,&new_h,&new_t);
            free_list(&r1head,&r1tail);
            free_list(&r2head,&r2tail);
            r1head=new_h;
            r1tail=new_t;
        }

        count++;

        t2=t2->prev;
    }
    *res_head=r1head;
    *res_tail=r1tail;
    return SUCCESS;
}
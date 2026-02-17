#include"header.h"

/*Insert at last operation*/
int insert_last(Dlist **head, Dlist **tail, int data) 
{
    Dlist *newnode = malloc(sizeof(Dlist));
    if (newnode==NULL) return FAILURE;
    
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;  
    
    if(*head == NULL) 
    {  
        *head = *tail = newnode;
        return SUCCESS;
    }
    
    newnode->prev = *tail;      
    (*tail)->next = newnode;     
    *tail = newnode;
    return SUCCESS;
}

/*Insert at first operation*/
int insert_first(Dlist **res_head,Dlist **res_tail,int data)
{
    Dlist *newnode=malloc(sizeof(Dlist));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }

    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=*res_head;

    if(*res_head==NULL)
    {
        *res_head=*res_tail=newnode;
        return SUCCESS;
    }

    (*res_head)->prev=newnode;
    *res_head=newnode;
    return SUCCESS;
}

/*Compare two lists*/
int compare(Dlist *head1,Dlist *head2)
{
    int len1=0,len2=0;
    Dlist *temp1=head1;
    Dlist *temp2=head2;

    while(temp1)
    {
        len1++;
        temp1=temp1->next;
    } 
    while(temp2)
    {
        len2++;
        temp2=temp2->next;
    }
    if(len1>len2)
        return 1;
    else if(len1<len2)
        return -1;
    
    temp1=head1;
    temp2=head2;

    while(temp1 && temp2)
    {
        if(temp1->data > temp2->data)
        {
            return 1;    
        }
        if(temp1->data < temp2->data)
        {
            return -1;
        }
            
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return 0;
}

/*Swap the lists*/
void swap(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2)
{
    Dlist *temp_head;
    Dlist *temp_tail;

    temp_head = *head1;
    *head1 = *head2;
    *head2 = temp_head;

    temp_tail = *tail1;
    *tail1 = *tail2;
    *tail2 = temp_tail;
}

/*Copy two lists*/
int copy_list(Dlist *head1,Dlist **tmp_head,Dlist **tmp_tail)
{
    *tmp_head=*tmp_tail=NULL;

    Dlist *temp=head1;

    while(temp)
    {
        if(insert_last(tmp_head,tmp_tail,temp->data)==FAILURE)
        {
            free_list(tmp_head,tmp_tail);
            return FAILURE;
        }
        temp=temp->next;
    }
    return SUCCESS;
}

/*Free lists*/
int free_list(Dlist **head,Dlist **tail)
{
    Dlist *temp = *head,*next=NULL;
    while(temp)
    {
        next=temp->next;
        free(temp);
        temp=next;
    }
    *head=*tail=NULL;
    return SUCCESS;
}

/*Print two lists*/
int print_list(Dlist *head,Dlist *tail)
{
    printf("Result : ");
    if(head==NULL && tail==NULL)
    {
        printf("0\n");
        return FAILURE;
    }

    Dlist *temp=head;
    // printf(" Head <->");
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    // printf(" Tail\n");
    printf("\n");
    return SUCCESS;
}

/*Remove Leading Zeros*/
void remove_zeros(Dlist **head,Dlist **tail)
{
    while(*head && (*head)->data==0 && (*head)->next)
    {
        Dlist *del = *head;
        *head = (*head)->next;
        (*head)->prev=NULL;
        free(del);
    }
    if(*head==NULL)
        *tail=NULL;
    
}

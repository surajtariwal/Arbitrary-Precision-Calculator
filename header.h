#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE 1

/*Double Linked List structure*/
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

/*LIST OPERATIONS*/
int insert_last(Dlist **head, Dlist **tail,int data);
int insert_first(Dlist **res_head,Dlist **res_tail,int data);
int print_list(Dlist *head, Dlist *tail);
int free_list(Dlist **head,Dlist **tail);

/*Arithmetic Operations*/
int addition(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail);
int subtraction(Dlist *tail1,Dlist *tail2,Dlist **res_head,Dlist **res_tail);
int multiplication(Dlist *tail1,Dlist *tail2,Dlist **res_head,Dlist **res_tail);
int division(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail);

/*Helper Functions*/
int compare(Dlist *head1,Dlist *head2);
void swap(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2);
int copy_list(Dlist *head1,Dlist **tmp_head,Dlist **tmp_tail);
void remove_zeros(Dlist **head,Dlist **tail);

#endif
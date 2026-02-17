/*

Project title : Arbitrary Precision Calculator

Registration Number : 25026C_302

Description :-

This project implements an Arbitrry Precision Calculator using a Double Linked List concept to perform addition, subtraction, multiplication, division
on very large numbers.
Each digit of number is stored in different node.Here arithmetic operations are performed digit by digit by traversing the list from tail to head.
This approach efficiently handles sign, carry and borrow.
*/

#include"header.h"

int main(int argc, char **argv)
{
    if (argc!=4)
    {
        printf("Pass correct argurements as :- ./a.out <num1> <operation> <num2>\n");
        return FAILURE;
    }
    
    /*For creating two lists take three lists, initialize them to NULL*/

    /*head1 and tail1 for list1*/
    Dlist *head1=NULL, *head2=NULL;

    /*head2 and tail1 for list2*/
    Dlist *tail1=NULL, *tail2=NULL;

    /*res_head and res_tail for resultant_list*/
    Dlist *res_head=NULL, *res_tail=NULL;

    /*Store 1st and 2nd arguement in num1 and num2, operand in operation*/
    char *num1=argv[1];
    char *operation=argv[2];
    char *num2=argv[3];

    /*Store length of list1 and list2*/
    int len1=strlen(num1);
    int len2=strlen(num2);

    /*Create sign and start variables of integer datatype to store sign of num1 and num2*/
    int sign1=1,sign2=1;
    int start1=0,start2=0;

    int i,data=0;

    //check sign for argv[1]
    if(num1[0]=='+')
    {
        sign1=1;
        start1=1;
    }
    else if(num1[0]=='-')
    {
        sign1=-1;
        start1=1;
    }
    else
    {
        sign1=1;
        start1=0;
    }

    //check sign for argv[3]
    if(num2[0]=='+')
    {
        sign2=1;
        start2=1;
    }
    else if(num2[0]=='-')
    {
        sign2=-1;
        start2=1;
    }
    else
    {
        sign2=1;
        start2=0;
    }
    //creating node for num1
    for(i=start1;i<len1;i++)
    {
        if(num1[i]<'0' || num1[i]>'9')
        {
            printf("Enter only numbers\n");
            return FAILURE;
        }
        /*Converting number present in string to integer number*/
        data = num1[i]-48;
        if(insert_last(&head1,&tail1,data)==FAILURE)
        {
            printf("Node creation failed for num1\n");
            return FAILURE;
        }
    }
    //creatng node for num2
    for(i=start2;i<len2;i++)
    {
        if(num2[i]<'0' || num2[i]>'9')
        {
            printf("Enter only numbers\n");
            return FAILURE;
        }
        /*Converting number present in string to integer number*/
        data = num2[i]-48;
        if(insert_last(&head2,&tail2,data)==FAILURE)
        {
            printf("Node creation failed for num2\n");
            return FAILURE;
        }
    }

    /*Remove leading zeros from list1 and list2*/
    remove_zeros(&head1,&tail1);
    remove_zeros(&head2,&tail2);

    /*Check if num2 is NULL and it is division operation*/
    if(head2==NULL && operation[0] == '/')
    {
        printf("Error : Division by zero\n");
        return FAILURE;
    }
    /*print number 1*/
    printf("Number 1 : ");
    print_list(head1,tail1);

    /*print number 2*/
    printf("Number 2 : ");
    print_list(head2,tail2);

    /*print operator*/
    printf("Operator : %s\n",operation);

    /*Declare result_sign variable of integer datatype*/
    int result_sign=1;

    switch(operation[0])
    {
        case '+' :
        if(sign1==sign2)
        {
            result_sign=sign1;
            addition(tail1,tail2,&res_head,&res_tail);
        }
        else
        {
            int cmp=compare(head1,head2);
            if(cmp >= 0)
            {
                subtraction(tail1,tail2,&res_head,&res_tail);
                result_sign=sign1;
            }
            else
            {
                result_sign=-sign1;
                subtraction(tail2,tail1,&res_head,&res_tail);
            }

        }
        break;

        case '-' :
        if(sign1!=sign2)
        {
            result_sign=sign1;
            addition(tail1,tail2,&res_head,&res_tail);
        }
        else
        {
            int cmp=compare(head1,head2);
            if(cmp >= 0)
            {
                subtraction(tail1,tail2,&res_head,&res_tail);
                result_sign=sign1;
            }
            else
            {
                result_sign=-sign1;
                subtraction(tail2,tail1,&res_head,&res_tail);
            }
        }
        break;

        case '*' :
        case 'x' : 
        case 'X' :
        multiplication(tail1,tail2,&res_head,&res_tail);
        break;

        case '/' :
        division(head1,tail1,head2,tail2,&res_head,&res_tail);
        break;

        default : 
        printf("Invalid Operator\n");
        return FAILURE;
    }
    
    /*If operation is multiplication and division*/
    if(operation[0]=='*' || operation[0]=='/')
        result_sign=sign1 * sign2;
    
    /*If data is zero and sign is negative then update result_sign to 1 not -1*/
    if(res_head && res_head->data == 0 && res_head->next==NULL)
        result_sign=1;
    
    /*print the result_sign if negative*/
    if(result_sign==-1)
        printf("-");
    
    /*print the resultant list*/
    print_list(res_head,res_tail);
    
    /*free all 3 lists*/
    free_list(&head1,&tail1);
    free_list(&head2,&tail2);
    free_list(&res_head,&res_tail);

    return SUCCESS;
}

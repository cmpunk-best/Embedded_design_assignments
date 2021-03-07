#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <stdbool.h>


int main(void){
    int choice,number;
    char sort;
    node* first=NULL;
    while (1)
    {
        printf("\n");
        for (int i = 0; i < 10; i++)
        {
            printf("\t*");
        }
        printf("\n");
        printf("\tMain Menu\n");
        printf("\t1.Create a  list\n");
        printf("\t2.Add a node to the list\n");
        printf("\t3.Remove element from list\n");
        printf("\t4.Sort the list (A/D)\n");
        printf("\t5.Display the list\n");
        printf("\t6.Merge two list\n");
        printf("\t7.Exit\n");
        printf("\tChoose yr choice:");
        scanf("%i",&choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            break;
        case 2:
            printf("\tGive the element to be added:");
            scanf("%i",&number);
            add_node(&first,number);
            break;
        case 3:
            printf("\tGive the number to be removed:");
            scanf("%i",&number);
            del_node(&first,number);
            break;
        case 4:
            printf("\tType 'A' for ascending and 'D' for descending:");
            scanf(" %c",&sort);
            sort_list(first,sort);
            outputformat();
            printf("\tSorted list\n");
            print_list(first);
            outputformat();
            break;
        case 5:
            outputformat();
            print_list(first);
            outputformat();
            break;
        case 7:
            exit(0);
            break;
        default:
            outputformat();
            printf("\tInvalid number\n");
            outputformat();
            break;
        }

    }
    
    
}
node* create_list(){
    node* first=NULL;
    return first;
}
void print_list(node* first){
    node* ptr=first;
    if (ptr==NULL)
    {
        printf("\tList is empty\n");
        return;
    }
    
    while(ptr!=NULL){
        printf("\t%i--->",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void add_node(node** first,int b){
    node* nextnode=malloc(sizeof(node));
    nextnode->data=b;
    nextnode->next=NULL;

    if (*first == NULL)
    {
        *first=nextnode;
    }
    else{

    node* ptr=*first;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=nextnode;

    }
    outputformat();
    printf("\tNode with size,%i added\n",b);
    outputformat();
}
void del_node(node** first,int b){
    node* ptr=*first;
    node* prev=NULL;
    if(ptr->data==b){
        *first=ptr->next;
        return;
    }
    while (ptr!=NULL)
    {
        if(ptr->data==b){
            prev->next=ptr->next;
            outputformat();
            printf("\tRemoved element,%i from node\n",b);
            outputformat();
            return;
        }
        else{
            prev=ptr;
            ptr=ptr->next;
            
        }
    }
    outputformat();
    printf("\tElement not found\n"); 
    outputformat();
}
void sort_list(node* first,char sorttype){
    node* ptr= first;
    int max;
    //bubble sort
    bool flag= true;
    while(flag){
        max=ptr->data;
        flag = false;
        while (ptr->next!=NULL)
        {
            if(sorttype=='A' || sorttype=='a'){
            if(ptr->next->data < max){
                swap(ptr,ptr->next);
                flag =true;
            }
            else{
                ptr=ptr->next;
            }}
            else if(sorttype =='D' || sorttype== 'd'){
            if(ptr->next->data > max){
                swap(ptr,ptr->next);
                flag =true;
            }
            else{
                ptr=ptr->next;
            }}
        }
        ptr=first;
    }
}
void swap(node* ptr1,node* ptr2){
    int temp=ptr1->data;
    ptr1->data=ptr2->data;
    ptr2->data=temp;
}

node* merge_list(node* first,node* first2){
    node* ptr = first;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=first2;
    return first;
}
void outputformat(){
    for (int i = 0; i < 10; i++)
    {
        printf("\t#");
    }
    printf("\n");
    
}

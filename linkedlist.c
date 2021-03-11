#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"


int main(void){
    int choice,number,counter=0,selected_list,list1,list2;
    int* list_ptr=malloc(sizeof(int));
    bool flag=false;
    char sort;
    node* first=NULL;
    node2* row_node=NULL;
    node2* merger_node=NULL;
    node2* list_node=NULL;// creating a head list
    while (1)
    {
        printf("\n");
        for (int i = 0; i < 10; i++)
        {
            printf("\t$");
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
            counter=counter+1;
            add_list(&list_node,counter);
            break;
        case 2:
            flag=print_list(list_node);
            if(!flag){
                break;
            }
            selected_list=select_list(list_ptr);
            if(selected_list<=counter && selected_list>=1){
            row_node=search_list(list_node,selected_list);
            
            printf("\tGive the element to be added:");
            scanf("%i",&number);
            add_node(&row_node->next2,number);
            }
            else{
                outputformat();
                printf("\tNot a valid list\n");
                outputformat();
            }
            break;
        case 3:
            flag=print_list(list_node);
            if(!flag){
                break;
            }
            selected_list=select_list(list_ptr);
            if(selected_list<=counter && selected_list>=1){
            row_node=search_list(list_node,selected_list);
            if(checkempty(row_node)){
                break;
            }
            printf("\tGive the number to be removed:");
            scanf("%i",&number);
            del_node(&row_node->next2,number);}
            else{
                outputformat();
                printf("\tNot a valid list\n");
                outputformat();
            }
            break;
        case 4:
            flag=print_list(list_node);
            if(!flag){
                break;
            }
            selected_list=select_list(list_ptr);
            
            if(selected_list<=counter && selected_list>=1){
            row_node=search_list(list_node,selected_list);
            if(checkempty(row_node)){
                break;
            }
            printf("\tType 'A' for ascending and 'D' for descending:");
            scanf(" %c",&sort);
            if(!isalpha(sort)){
                printf("\tPlease enter a alphabet\n");
                break;}
            sort_node(row_node->next2,sort);
            outputformat();
            printf("\tSorted list\n");
            print_node(row_node->next2);
            outputformat();}
            else{
                outputformat();
                printf("\tNot a valid list\n");
                outputformat();
            }
            break;
        case 5:
            flag=print_list(list_node);
            if(!flag){
                break;
            }
            selected_list=select_list(list_ptr);
            if(selected_list<=counter && selected_list>=1){
            row_node=search_list(list_node,selected_list);
            if(checkempty(row_node)){
                break;
            }
            outputformat();
            print_node(row_node->next2);
            outputformat();
            }
            else{
                outputformat();
                printf("\tNot a valid list\n");
                outputformat();
            }
            break;
        case 6:
            flag=print_list(list_node);
            if(!flag){
                break;
            }
                printf("\tSelect any 2 list to merge(Merger will be made in 1st list)->\n");
                printf("\tSelect list-1(Merger will happen here,HEAD_MERGER node):");
                scanf("%i",&list1);
                printf("\tSelect list-2:");
                scanf("%i",&list2);
                //error checking for out of bound inputs
                if(list1<=counter && list1>=1 && list2<=counter && list2>=1){
                    row_node=search_list(list_node,list1);
                    merger_node=search_list(list_node,list2);
                if(checkempty(row_node) && checkempty(merger_node)){
                    break;
                }
                    first=merge_list(row_node->next2,merger_node->next2);
                    del_list(&list_node,list2);
                    outputformat();
                    printf("\tLists available after merger:\n");
                    print_list(list_node);
                    printf("\tMerged list:\n");
                    print_node(first);
                    outputformat();
            }
            else{
                outputformat();
                printf("\tNot a valid lists\n");
                outputformat();
            }
            
            break;

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
bool checkempty(node2* list_ptr){
    if(list_ptr->next2==NULL){
        outputformat();
        printf("\tList is empty\n");
        outputformat();
        return true;
    }
    else
        return false;
}
int select_list(int* list_ptr){
    printf("\tPlease enter the list from above:");
    scanf("%i",list_ptr);
    return *list_ptr;
}
bool print_list(node2* list_node){
    node2* ptr=list_node;
    if (ptr==NULL)
    {
        printf("\tList is empty\n");
        return false;
    }
    printf("\tLists available:\n");
    while(ptr!=NULL){
        printf("\t%i.\n",ptr->data);
        ptr=ptr->next;
    }
    return true;
    printf("\n");
}
void print_node(node* first){
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
void add_list(node2** list_node,int counter){
    node2* nextlist = malloc(sizeof(node2));
    nextlist->data = counter;
    nextlist->next=NULL;
    nextlist->next2=NULL;
    if (*list_node==NULL)
    {
        *list_node =nextlist;
    }
    else{
        node2* ptr = *list_node;
        while (ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=nextlist;
        ptr=NULL;
        free(ptr);
    }
    nextlist=NULL;
    free(nextlist);
   printf("\tNew list has been created.\n"); 

}
node2* search_list(node2* list,int selected_list){
    node2* ptr = list;
    while(ptr!=NULL){
        if(ptr->data == selected_list){
            return (ptr);
        }
        ptr=ptr->next;
    }
    
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
void del_list(node2** list_node,int b){
    node2* ptr= *list_node;
    node2* prev=NULL;
    if(ptr->data==b){
        *list_node=ptr->next;
        return;
    }
    while(ptr!=NULL){
        if(ptr->data==b){
            prev->next=ptr->next;
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
void sort_node(node* first,char sorttype){
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
        printf("\t*");
    }
    printf("\n");
    
}

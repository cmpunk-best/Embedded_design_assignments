
#include <stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct node2{
    int data;
    struct node2* next;
    node* next2;
}node2;
node** create_list();
void print_node(node*);
void add_node(node** ,int);
void del_node(node**,int);
void sort_node(node*,char);
void swap(node*,node*);// additional function for swapping nodes
node* merge_list(node*,node*);
void outputformat();//additional function for outputformating nodes
void add_list(node2**,int);
bool print_list(node2*);
int select_list(int*);
node2* search_list(node2*,int);
bool checkempty(node2*);
void del_list(node2**,int);

typedef struct node{
    int data;
    struct node* next;
}
node;
node* create_list();
void print_list(node*);
void add_node(node** ,int);
void del_node(node**,int);
void sort_list(node*,char);
void swap(node*,node*);// additional function for swapping nodes
node* merge_list(node*,node*);
void outputformat();//additional function for outputformating nodes

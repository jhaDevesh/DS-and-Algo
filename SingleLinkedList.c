#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct listNode
{
    int data;
    struct node *next;
};

typedef struct listNode node;

node* createNode(int data){
    node *tempNode = (node *)malloc(sizeof(node));
    tempNode->data = data;
    tempNode->next = NULL;
    return tempNode;
}
void printList(node *head){
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
}
node* createRandomList(node *head,int size){
    node *it = NULL, *temp = NULL;
    srand(time(0));
    for(int i=1; i<=size; ++i)
    {
        temp = createNode(rand()%20);
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            it = head;
            while(it->next != NULL)
            {
                it = it->next;
            }
            it->next = temp;

        }

    }
    printList(head);
    return head;

}
node* deleteNodeAtPos(node *head,int x){
    int count = 1;
    node *temp = head, *temp1;
    if(x == 1)
    {
        return head->next;
    }
    else
    {
        while(1)
        {
            if(count != x-1)
            {
                temp = temp->next ;
                count++;
            }
            else
            {
                temp1 = temp->next;
                temp->next = temp1->next;
                free(temp1);
                temp1 = NULL;
                return head;
                break;
            }
        }
    }

}
int getLength(node *head){
     if(head->next == NULL) return 1;
    else{
        return 1 + getLength(head->next);
    }
}
int getNthNode(node *head , int index){
    int len = getLength(head);
    if(index > len ) {
        printf("Error-index cannot be greater than length of list");
        return -1;
    }
        if(index == 1) return head->data;
    else {
        index  = index-1;
        return getNthNode(head->next ,index);
    }

}
int compare(node *list1, node *list2){
    // Recursive
    if(list1==NULL && list2==NULL)
            return 0;
    else if(list1!=NULL && list2==NULL)
            return 1;
    else if(list1==NULL && list2!=NULL)
            return -1;
    else if(list1->data > list2->data)
            return 1;
    else if(list1->data < list2->data)
            return -1;

    else return compare(list1->next , list2->next);

   /* Iterative

   while(list1 != NULL && list2 != NULL){
         if(list1->c > list2->c)
            return 1;
        else if(list1->c < list2->c)
            return -1;
        list1 = list1->next;
        list2 = list2->next;
     }

     if(list1==NULL && list2==NULL) return 0;
     else if(list1!=NULL && list2==NULL) return 1;
     else if(list1==NULL && list2!=NULL) return -1;*/


}

int main()
{
    /*node *head = NULL;
    head = createRandomList(head,9);
    //head = deleteNodeAtPos(head,5);
    printf("\n");
    printf("%d",getNthNode(head,9));*/

    node *head1=NULL, *head2 = NULL;
    head1 = createRandomList(head1,3);
    printf("\n");
    head2 = createRandomList(head2,4);
    printf("\n");
    printf("\n%d", compare(head1,head2));
}


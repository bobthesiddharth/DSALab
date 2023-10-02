#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL, *p = NULL;

struct Node *create_3634(struct Node *head) {
    struct Node *nw = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &nw->data);
    nw->next = NULL;
    if (head == NULL) {
        head = nw;
        p = nw;
    } else {
        p->next = nw;
        p = nw;
    }
    return head;
}

void insertBegin(struct Node **head) {
    struct Node *nw = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter new Node Data: \n");
    scanf("%d", &nw->data);
    nw->next = *head; // Update the next pointer of the new node
    *head = nw; // Update the head pointer to point to the new node
}


void insertEnd(struct Node **head){
    struct Node* last;
    struct Node *nw = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter new Node Data: \n");
    scanf("%d", &nw->data);
    nw->next=NULL;
    last = *head;
    if(*head == NULL){
        *head = nw;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = nw;
}

void display(struct Node *head){
    if(head == NULL){
        printf("\n Empty List \n");
        return;
    }
    int c=1;
    struct Node *p = head; // Change 'nw' to 'head' to iterate over the linked list
    while (p != NULL) {
        printf("Node %d : %d \n",c, p->data); // Add a space after %d to separate the numbers
        c++;
        p = p->next;
    }
}

// void insertAfter(struct Node **head){
//     struct Node *prev;
//     struct Node* sw = (struct Node *)malloc(sizeof(struct Node));
//     prev = head;

// }

void deleteBegin(){
    struct Node * temp = head;
    if(temp == NULL){
        printf("\n Empty List\n");
        return;
    } else {
        printf("\n Value of the deleted node = %d ", temp->data);
        head = head->next;
        free(temp);
    }
}

void deleteEnd(){
    struct Node * temp = head;
    struct Node * prev;
    if(temp == NULL){
        printf("\n Empty List...\n");
        return;
    }
    if(temp->next==NULL){
        printf("List Contains only One Node its value= %d \n",temp->data);
        head = NULL;
        free(temp);
        return;
    } else {
        while(temp -> next != NULL){
            prev = temp;
            temp = temp->next;
        }
        printf("\n Value of the DEleted Node is = %d \n",temp->data);
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    int n = 0;
    int op=1;
    int ch=0;
    while(op){
            printf("Enter your choice:  \n 1.create Nodes \n 2.display Nodes(traverse) \n 3.Insert begining\n 4.Insert at END \n 5.DeleteFirstNode \n 6.DeleteLastNode \n");
            scanf("%d", &ch);
            switch(ch){
                case 1:
                        //creating nodes
                        
                        printf("\n Enter number of nodes:");
                        scanf("%d", &n);

                        while (n != 0) {
                            head = create_3634(head);
                            n--;
                        }
                    break;
                case 2:
                        display(head);
                    break;
                case 3:
                        insertBegin(&head);
                    break;
                case 4:
                        insertEnd(&head);
                    break;
                case 5:
                        deleteBegin();
                    break;
                case 6:
                        deleteEnd();
                    break;
            }

            printf("\n Press 1 to continue or 0 to exit.\n");
            scanf("%d", &op);
    }
    return 0;
}

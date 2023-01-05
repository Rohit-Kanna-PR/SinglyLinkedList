#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int no;
    struct list * next;
}LIST;
LIST *p,*t,*h,*y,*ptr,*pt;
void create();
void insert();
void delete();
void display();
int j,pos,k=1,count;
char g = 'y';
int main(){
    int n,i=1,opt = 0;
    p = NULL;
    printf("%ld\n",sizeof(LIST));
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    count = n;
    while(i <= n){
        create();
        i++;
    }
    do{
    printf("\nEnter your option:\n");
    printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                insert();
                count++;
                break;
            case 2:
                if (count == 0){
                    printf("\nList is empty\n");
                }
                delete();
                count--;
                break;
            case 3:
                printf("\nList elements are : ");
                display();
                break;
        }
            printf("do you wnt to continue: ");
            scanf("%c",&g);
        printf("\nEnter your option\n");
        scanf("%c",&g);
    }while(g == 'y' || g == 'Y');
}
void create(){
    if (p ==NULL){
        p = (LIST*) malloc (sizeof(LIST));
        printf("Enter the element:\n");
        scanf("%d",&p->no);
        p -> next = NULL;
        h = p;
    }
    else{
        t = (LIST*) malloc(sizeof(LIST));
        printf("\nEnter the element: ");
        scanf("%d",&t->no);
        t->next = t;
        p = t;
    }
}
void insert(){
    t = h;
    p = (LIST*) malloc (sizeof(LIST));
    printf("Enter the element to be inserted : \n");
    scanf("%d",&p->no);
    printf("Enter the position to insert: \n");
    scanf("%d",&pos);
    if (pos == 1){
        h = p;
        h->next = t;
    }
    else{
        for (j = 1;j<(pos-1);j++){
            t = t->next;
            p->next = t->next;
            t -> next = p;
            t = p;
        }
    }
}
void delete(){
    printf("Enter the position to delete\n");
    scanf("%d",&pos);
    if (pos == 1){
        h = h ->next;
    }
    else{
        t = h;
        for (j=1;j<(pos-1);j++){
            t = t-> next;
            pt = t -> next->next;
            free(t->next);
            t -> next = pt;
        }
    }
    printf("Deleted successfully");
}
void display(){
    t = h;
    while(t-> next != NULL){
        printf("\t%d",t -> no);
    }
    printf("\t%d\t",t->no);
}
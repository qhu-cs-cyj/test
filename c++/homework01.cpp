#include<stdio.h>
#include<stdlib.h>

struct list{
    int data;
    struct list * pre;
    struct list * next;
};

struct list l1,l2;
int SUM=1;

//初始化list
void initList()
{
    l1.pre=NULL;
    l1.next=&l2;
    l2.pre=&l1;
    l2.next=NULL;
}

//在第N个位置插入m
void insertList(int n,int m)
{
    struct list temp = (struct list)malloc(sizeof(struct list));
    struct list tp = l1;
    
    if(n>SUM) return;
    for(int i=0;i<n;temp=*(temp.next),i++);
    temp.next=&l1;
    temp.next=&l2;
    temp.data=m;
    l1.next = &temp;
    l2.pre = &temp;
    return;
}

void printList()
{
    struct list temp = l1;
    for(;temp.next!=NULL;temp=*(temp.next))
    {
        printf("%d",temp.data);
    }
}

int main()
{
    initList();
    insertList(1,5);
    insertList(2,3);
    insertList(3,2);
    insertList(4,1);
    insertList(2,4);

    printList();
}
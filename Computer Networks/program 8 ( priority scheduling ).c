/*
Program 8: Packets from different flows arrive at a switch or router for
processing. A good scheduling technique treats the different flows in a fair and
appropriate manner. Implement priority queuing as a technique to improve
Quality of Service.

*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int front;
int rear;
int priq[MAX];

void create()
{
    front = -1;
    rear = -1;
    return;
}

void insert(int data)
{
    if(rear >= MAX-1){
        printf("overflow\n");
        return;
    }
    if(front == -1 && rear == -1){
        front++;
        rear++;
        priq[rear] = data;
        return;
    }else{
        int i,j;
        for(i=0;i<=rear;i++){
            if(data >= priq[i]){
                for(j = rear+1;j>i;j--){ //right shifting all the elements
                    priq[j] = priq[j-1];
                }
                priq[i] = data; //assigning to position of i
                rear++;
                return;
            }
        }
        priq[i] = data; //if no element is lesser than gicen data
        rear++;
        return;
    }
}

void delete(int data)
{
    if(front == -1 && rear == -1)
    {
        printf("no elements to delete\n");
        return;
    }

    for(int i=0;i<=rear;i++)
    {
        if(priq[i] == data){
            for(int j=i;j<rear;j++){ //left shiftng all the elements from position of i
                priq[j] = priq[j+1];
            }
            rear--;
        }
    }

    if(rear == -1){ //all the elements in priq area deleted but front is still 0
        front = -1;
        return;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("no elements to display\n");
        return;
    }
    for(;front<=rear;front++){
        printf("%d \t",priq[front]);
    }
    printf("\n");
    front = 0; //after each display front reaches rear (reset back to 0)
    return;
}

int main()
{
    int ch,data;
    printf("1 : insert\n");
    printf("2 : delete\n");
    printf("3 : display\n");
    printf("4 : exit\n");
    create();
    while(1)
    {
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : printf("enter element to insert\n");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2 : printf("enter the element ot delete\n");
                        scanf("%d",&data);
                        delete(data);
                        break;
            case 3 : display();
                     break;
            case 4 : exit(0);
            break;

        }
    }
    return 0;
}

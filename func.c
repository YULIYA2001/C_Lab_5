#include "func.h"

Queue *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
List *head = NULL, *tail = NULL;

/* ���������� ������� (�������� ����� �� �������)*/
void Enqueue(int queue_num, int amount, int *arr)
{
    Queue *head, *tail;     /* ����� ���������� ��� ���������� ���� �������� */
    int i;
    Queue* p;

    /* ����� ������� ��� ���������� */
    if (queue_num == 1)
    {
        head = head1;
        tail = tail1;
    }
    if (queue_num == 2)
    {
        head = head2;
        tail = tail2;
    }
    for (i = 0; i < amount; i++)
    {
        p = (Queue *)malloc(sizeof(Queue));
        p->data = arr[i];
        p->next = NULL;     /* ���������� ������� ����� ������� */
        if (head == NULL)   /* ���� ������� �����... */
            head = p;       /*head ��������� �� ��������� �������*/
        else
            tail->next = p; /* ��������� ����� ��. � ����� �������*/
        tail = p;           /* tail ��������� �� ����� ������� */
    }
    /*����������� ������ �� ���. ���������� ���������� �� 1 ���  2 ������� */
    if (queue_num == 1)
    {
        head1 = head;
        tail1 = tail;
    }
    if (queue_num == 2)
    {
        head2 = head;
        tail2 = tail;
    }
}

/* ���������� ���������� ������� */
void Display_Queue(int queue_num)
{
    Queue* p;

    /* ����� ������� ��� ������ �� ����� */
    if (queue_num == 1)
        p = head1;
    if (queue_num == 2)
        p = head2;
    if (p == NULL)
        printf("Queue is empty");
    else
        printf("Queue %d:", queue_num);
    while (p != NULL)
    {
        printf("\n%d", p->data);
        p = p->next;
    }
}

/* ������ ����������� ���� �������� � ������ */
void List_of_2_queues(int amount1, int amount2)
{
    List_of_queue(amount1, 1);
    List_of_queue(amount2, 2);
}

/* ������ ����������� 1 ������� � ������ */
void List_of_queue(int amount, int queue_num)
{
    List *p, *cur = head;
    Queue *p1;
    int i;

    /* ����� �� ����� ������� ��������� */
    if (queue_num == 1)
        p1 = head1;
    if (queue_num == 2)
        p1 = head2;
    for (i = 0; i < amount; i++)
    {
        p = (List *)malloc(sizeof(List));
        p->data = p1->data;
        p->next = p->prev = NULL;
        if (head == NULL)       /* ���� ������ ����*/
        {
            head = tail = p;        /* head � tail ��������� �� ��������� ������� */
        }
        else
        {
            /* ����� ����� ��� ������� */
            while (cur != NULL && p1->data > cur->data)
                cur = cur->next;
            if (cur == head)    /* ���� ������� ����� �������� � ������*/
            {
                p->next = head;
                head->prev = p;
                head = p;
            }
            else if (cur == NULL)   /* ���� ������� ����� �������� � �����*/
            {
                tail->next = p;
                p->prev = tail;
                tail = p;
            }
            else    /* ���� ������� ����� �������� � ��������*/
            {
                cur->prev->next = p;
                p->prev = cur->prev;
                cur->prev = p;
                p->next = cur;
            }
        }
        p1 = p1->next;
    }
}

/* ����������� ������ */
void Display_List(void)
{
    List *p = head;

    if (p == NULL)
        puts("List is empty");
    else
    {
        printf("List:\n");
        printf("NULL <-> ");
        while (p != NULL)
        {
            printf("%d <-> ", p->data);
            p = p->next;
        }
        printf("NULL");
    }
}

//������ visual studio���� ���۵�.

#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    char value;
    struct node* ptr;
} NODE;

void StringReverse(void);

int main(void)
{
    StringReverse();

    return 0;
}

void StringReverse(void)
{
    //���� ����
    int tmp; //�Է¹��� ���ڸ� �ӽ÷� ������ ����
    int char_len = 0; //���ڿ��� ���̸� ������ ����
    NODE* ptr_head = NULL; //linked list�� head ������
    NODE* ptr_tail = NULL; //linked list�� tail ������


    //������ ���ڿ� �Է¹ޱ�
    while (1)
    {
        tmp = getch();

        if ((tmp == '\r') || (tmp == '\n'))
        {
            if (ptr_head == NULL)
            {
                printf("\n�ƹ� ���ڵ� �Էµ��� �ʾҽ��ϴ�.\n");
                return;
            }

            break;
        }
        else
        {
            printf("%c", tmp);

            char_len++;
            
            if (ptr_head == NULL)
            {
                ptr_head = (NODE*)malloc(sizeof(NODE));
                if (ptr_head == NULL)
                {
                    printf("\n�޸� �Ҵ� ����\n");
                    return;
                }

                ptr_tail = ptr_head;
                ptr_tail->ptr = NULL;

                ptr_tail->value = tmp;
            }
            else
            {
                ptr_tail->ptr = (NODE*)malloc(sizeof(NODE));
                if (ptr_tail->ptr == NULL)
                {
                    printf("\n�޸� �Ҵ� ����\n");
                    return;
                }

                ptr_tail = ptr_tail->ptr;
                ptr_tail->ptr = NULL;

                ptr_tail->value = tmp;
            }
        }
    }


    //���ڿ� �ݴ�� ����ϱ�
    printf("\n");

    NODE* ptr_tmp = NULL; //����� NODE�� �ּҸ� �ӽ÷� ������ ����

    for (int i = (char_len - 1); i > 0; i--)
    {
        ptr_tmp = ptr_head;

        for (int j = 0; j < i; j++)
        {
            ptr_tmp = ptr_tmp->ptr;
        }

        printf("%c", ptr_tmp->value);
    }
    
    printf("%c", ptr_head->value);


    //�Ҵ��� �޸� �ݳ��ϱ�
    NODE* ptr_free_alive = ptr_head;
    NODE* ptr_free_dead = NULL;

    while (1)
    {
        ptr_free_dead = ptr_free_alive;
        ptr_free_alive = ptr_free_alive->ptr;
        free(ptr_free_dead);

        if (ptr_free_alive == ptr_tail)
        {
            free(ptr_tail);

            break;
        }
    }

    return;
}
//������ visual studio���� ���۵�.

#pragma warning(disable : 4996)

#include <stdio.h>

#define ARRAY_LENGTH 20

void StringSelect(char *ptr1, char *ptr2);

int main(void)
{
	char a[ARRAY_LENGTH], b[ARRAY_LENGTH];
	printf("a: ");
	if (scanf("%s", a) != 1)
	{
		printf("\n�Է� ���� �߻�\n");
		return 0;
	}

	printf("b: ");
	if (scanf("%s", b) != 1)
	{
		printf("\n�Է� ���� �߻�\n");
		return 0;
	}

	printf("\n");

	StringSelect(a, b);

	return 0;
}

void StringSelect(char* ptr1, char* ptr2)
{
	for (int i = 0; i < 20; i++)
	{
		if ((ptr1[i] == 0) || (ptr2[i] == 0)) //�� �̻� ���� ���ڰ� ���� ���.
		{
			break;
		}

		if (ptr1[i] == ptr2[i])
		{
			printf("���� ���� : %c, ��ġ : %d\n", ptr1[i], i);
		}
	}

	return;
}
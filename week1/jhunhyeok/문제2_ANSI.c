//������ visual studio���� ���۵�.

#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>

#define	ARRAY_LENGTH 20

void StringExchg(char* ptr1, char* ptr2);

int main(void)
{
	//���ڿ� �Է¹ޱ�
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

	StringExchg(a, b);

	//�ٲ� ���ڿ� ����ϱ�
	printf("\na: %s\nb: %s\n", a, b);

	return 0;
}

void StringExchg(char* ptr1, char* ptr2)
{
	char tmp;
	
	for (int i = 0; i < (int)strlen(ptr1); i++)
	{
		tmp = ptr1[i];
		ptr1[i] = ptr2[i];
		ptr2[i] = tmp;
	}

	return;
}
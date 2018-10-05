#include<stdio.h>
#define MAX_ROW 30
#define MAX_COL 400
void delete(int n, char arr[MAX_ROW][MAX_COL]);
int str_com(char* first, char* second);                    //�ַ����Ƚϣ���ͬ�򷵻�1
int str_len(char* arr);                                    //�õ��ַ������ȣ���������ֹ���ţ�
void str_cpy(char* first, char* second);                   //�ַ�������
void input(char*);
void output(char*);

int main(){
	int n, count = 0;
	char arr[MAX_ROW][MAX_COL];

	scanf("%d", &n);
	getchar();
	while (count < n){
		gets(arr[count]);                          //�ַ�����ֵ
		count++;
	}
	delete(n, arr);
	//system("pause");
	return 0;
}
void delete(int n, char(*arr)[MAX_COL]){
	char tmp[MAX_ROW][MAX_COL];
	int k = 0;

	str_cpy(tmp[k], arr[0]);
	k++;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= k; j++){
			if (str_com(arr[i], tmp[j]))
				break;
			if (j == k){
				str_cpy(tmp[k], arr[i]);
				k++;
				break;
			}
		}
	}

	for (int i = 0; i < k; i++){
		output(tmp[i]);
		if (i < k - 1)
			putchar('\n');
	}
}

int str_com(char* first, char* second){
	int len_first = str_len(first);
	int len_second = str_len(second);
	int count = 0;

	if (len_first != len_second)
		return 0;
	while (first[count] == second[count]){
		if (count == len_second - 1)
			return 1;
		count++;
	}
	return 0;
}

int str_len(char* arr){
	char* base = arr;

	while (*arr){
		arr++;
	}

	return arr - base;
}
//��������ֹ�����ַ�������

void str_cpy(char* first, char* second){
	while (*first++ = *second++);
	*first = '\0';
}

void output(char* ptr){
	while (*ptr != '\n'&&*ptr != '\0')
		putchar(*ptr++);
}

void input(char* ptr){
	char c;

	c = getchar();
	while (c != '\n'&&c != '\r'&&c != '\0'&&c != '\t'&&c != '\f'){          //****
		*ptr = c;
		ptr++;
		c = getchar();
	}
	*ptr = '\0';
}
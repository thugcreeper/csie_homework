#include<stdio.h>

int main(){
	int  beginningDay[12]={20,20,21,21,21,22,23,23,23,23,22,22};
	char * zodiacName[12] = {"�d�Ϯy", "�����y","���l�y","���ɮy","��l�y","�B�k�y","�ѯ��y","���Ȯy","�g��y","���~�y","���~�y","�����y"};
	int mon,date,zodiacCode;
	printf("�п�J��� (�H ��/�� ���榡)�G");	scanf("%d/%d",&mon,&date);
	zodiacCode = (mon + 9) % 12;
	if (date < beginningDay[ mon-1 ] ){
		zodiacCode = (zodiacCode -1 + 12) % 12;
	}
	printf("�A�O%s���A�P�y�N�X�O %d�C", zodiacName[ zodiacCode ],zodiacCode);
	return 0;
}

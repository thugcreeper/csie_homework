#include<stdio.h>

int main(){
	int days,first_day,i,j = 0;
	printf("�аݳo�Ӥ릳�h�֤ѡH");
	scanf("%d",&days);
	printf("�аݳo�Ӥ�Ĥ@�ѬO�P���X�H(0=�P����, 1=�P���@, ...)");
	scanf("%d",&first_day);
	printf(" S  M  T  W  T  F  S\n");
	for( i =1;i<=days;i++){
		while(j < first_day){
			printf("   ");
			j++; 
		}
		printf("%2d ",i);
		if((first_day + i)%7 == 0)
		printf("\n");
	}
	return 0;
}


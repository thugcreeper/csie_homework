#include<stdio.h>

int main(){
	int firstprize,inputnum;
	printf("�п�J�Y�����X�G");
	scanf("%d",&firstprize);
	
	if(firstprize > 99999999)
	printf("error");
	printf("�п�J�A���o�����X�G");
	scanf("%d",&inputnum);
	if(inputnum == firstprize){
		printf("���ߡI�A���F�Y���I");
	}
	else if (inputnum % 10000000 == firstprize % 10000000){
		printf("���ߡI�A���F�G���I");
	}
	else if (inputnum % 1000000 == firstprize % 1000000){
		printf("���ߡI�A���F�T���I");
	}
	else if (inputnum % 100000 == firstprize % 100000){
		printf("���ߡI�A���F�|���I");
	}
	else if (inputnum % 10000 == firstprize % 10000){
		printf("���ߡI�A���F�����I");
	}
	else if (inputnum % 1000 == firstprize % 1000){
		printf("���ߡI�A���F�����I"); 
	} 
	else{
		printf("��p�S�������C");
	}
	return 0;
}


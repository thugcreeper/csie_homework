#include<stdio.h>

int main(){
	int num,base,maxbase = 1,i=1;
	printf("�п�J�@�ӫD�t��ơG");		scanf("%d",&num);
	printf("�п�J�i���G");			scanf("%d",&base);
	
	while(i<=num){//num 10 base 2 1010 
		maxbase = i;
		i *= base;
	}
	printf("%d�i���ܪk�G",base);
	while(maxbase>0){
		printf("%d",(num/maxbase)%base);
		maxbase /= base;
	}
	return 0;
}

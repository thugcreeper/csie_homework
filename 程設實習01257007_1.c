#include<stdio.h>

int main(){
	int amounta,amountb,total = 0;
	printf("Product A �ʶR�ƶq�G");
	scanf("%d",&amounta);
	printf("Product B �ʶR�ƶq�G");
	scanf("%d",&amountb);
	if(amounta <= amountb){
		total = amounta * 39 + 	((amountb - amounta)/2) * 32 + (amountb%2)*20 ;
		
	}
	if(amountb <= amounta){
		total = amountb * 39 + 	((amounta - amountb)/2) * 40 + (amounta%2)*25;
	}
	printf("�`�@�O %d ���C",total);
}

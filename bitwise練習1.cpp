#include<stdio.h>
int main() {
    int rptime, inputnum;
    printf("How many sets of test data: ");
    scanf("%d", &rptime);
    int size=sizeof(inputnum)*8;
    for (int i = 0; i < rptime; i++) {
        printf("\nInput: ");
        scanf("%d", &inputnum);
        printf("The 1 bits are at: ");
        for(int i=0;i<size;i++){
        	if(inputnum&(1<<i)!=0)//����1 i�� ,�Y����0�N���� =if(inputnum&(1<<i)!) 
        		printf("%d ",i);
		}
        printf("\n");
    }
    return 0;
}


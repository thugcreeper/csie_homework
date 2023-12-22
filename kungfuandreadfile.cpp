#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30]; // name of the player
    int level; // level of the player
    char skill; // kongfu records which the player has learned
} PlayerData;
int main(){
	PlayerData player[6]={};
	char *kungfuName[] = {"�K�Y�\\", "�ۭ��a��L","�����n�K���m","���v�ள��","���\\���W��","�j�O����L","��l�q","�p�ӯ��x"};//�\�᭱�n�["\"�~�ॿ�`�L�X 
	FILE *fptr = fopen("playerData_BIG5.data", "rb");//file and program should put in the same directory
	if (fptr == NULL){
	printf("�}�ɥ���\n");
	return 1;
	}
	fread(player,sizeof(PlayerData),6,fptr);
	fclose(fptr);
	for(int i=0;i<6;i++){
		printf("Name: %s\n",player[i].name);
		printf("Level: %d\n",player[i].level);
		printf("Skills:\n");
		for (int kf = 0; kf < 8; kf++) {
    		if(player[i].skill&(1<<kf))//checking the k-th bit is to do bitwise AND with 2k, i.e. (1 << k)
    			printf("\t%s\n",kungfuName[kf]);
		}
		printf("\n");		
	}
	return 0;
}

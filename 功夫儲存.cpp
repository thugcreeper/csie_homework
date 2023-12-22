#include <stdio.h>
#include <string.h>
char *kungfuName[] = {"�K�Y�\\", "�ۭ��a��L","�����n�K���m","���v�ள��","���\\���W��","�j�O����L","��l�q","�p�ӯ��x"};
typedef struct {
    char name[30]; // name of the player
    int level; // level of the player
    char skill; // kongfu records which the player has learned
} PlayerData;

int indexOfList_icmp(char *str, char *list[], int size) {
	for(int i=0;i<size;i++){
		if(stricmp(str,list[i])==0)
			return i;
	}
	return -1;
}
void printplayer(PlayerData player[],char playername[]){//function to print player's data
	for(int i=0;i<6;i++){
		if (strcmp(player[i].name, playername) == 0){
			printf("\nName: %s\n",player[i].name);
			printf("Level: %d\n",player[i].level);
			printf("Skills:\n");
			for (int kf = 0; kf < 8; kf++) {
	    		if(player[i].skill&(1<<kf))//checking the k-th bit is to do bitwise AND with 2k, i.e. (1 << k)
	    			printf("\t%s\n",kungfuName[kf]);
			}
			printf("\n");		
		}		
	}
}
void readplayer(char playername[]){
	printf("\n�п�J���a�G");
	fgets(playername, sizeof(playername), stdin);
	strtok(playername, "\r\n");	
}
void choose(){
	printf("1. �x�s�s�Ƿ|�\\��\n");
	printf("2. �d�ߪ��a�Ƿ|���\\��\n");
	printf("3. �d�߾Ƿ|�\\�Ҥ����a\n");
	printf("4. ���}\n");	
}

int main(){
	int action,person;
	char playername[20],searchkf[20];//input player name and kungfu name
	PlayerData player[6]={};
	FILE *fptr = fopen("playerData_BIG5.data", "rb");
	if (fptr == NULL){
		printf("�}�ɥ���\n");
		return 1;
	}
	fread(player,sizeof(PlayerData),6,fptr);
	fclose(fptr);//close file after read it
	while(1){
		choose();
		printf("�п�J�ʧ@�G");
		scanf("%d",&action);
		if (getchar() == '\r') getchar();
		
	if(action == 1){
		char kf1[100];
		readplayer(playername);
	    for(int i=0;i<6;i++){
	    	if (strcmp(player[i].name, playername) == 0){
	    		printf("�п�J�\\�ҡG");
				fgets(kf1, sizeof(kf1), stdin);
			    strtok(kf1, "\r\n");
				int sid=indexOfList_icmp(kf1,kungfuName,7);
				if(sid>=0){
			    	player[i].skill |= 1<<sid;
			    	printf("�x�s%s�Ƿ|%s���\\\n\n",player[i].name,kungfuName[sid]);
				}
				break;
			}  	
		}	    
	}
	else if (action == 2) {
	    readplayer(playername);
	    printplayer(player,playername);
	}
	else if(action==3){
			printf("�п�J�d�ߪ��\\�ҡG");
			fgets(searchkf, sizeof(searchkf), stdin);
	    	strtok(searchkf, "\r\n");
			printf("�Ƿ|�o�ǥ\\�Ҫ����a���G");
			int sid=indexOfList_icmp(searchkf,kungfuName,7);
			for(int i=0;i<6;i++){
				if(player[i].skill&(1<<sid)){//���_����1���ˬd�\�ҬO�_�Ƿ| 
					printf("%s  ",player[i].name);			
				}
			}
			printf("\n");
		}
	else if(action==4){
			printf("goodbye\n");
			break;
		}
	}
	return 0;
}

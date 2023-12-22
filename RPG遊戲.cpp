#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define monstertotal 3

typedef struct {
    char name[100];
    int level, hp, speed, atk, exp;
} PlayerData;//�ۭq���a��Ƶ��c 

typedef struct {
    char name[20];  
    int hp, speed, atk, giveexp;
} MonsterData;

void initplayer(PlayerData *p) {//�n�ק�ȬOcall by reference �G�n�Ϋ��б����a�} 
	printf("�п�J���a���W�r�G");
    fgets(p->name, sizeof(p->name), stdin);
    strtok(p->name, "\r\n");
    p->level = 1;//p�O���СA�Y�n�קﵲ�c�����Y�Ӹ�ƭn��-> 
    p->hp = rand() % 251 + 350;//%251����0-250���ü� 
    p->speed = rand() % 16 + 35;
    p->atk = rand() % 21 + 40;
    p->exp = 0;
}

void initmonster(MonsterData *p) {
    strcpy(p->name, "�b�~�H"); //�ƻs"�b�~�H"��name 
    p->hp = rand() % 21 + 150;
    p->speed = rand() % 16 + 35;
    p->atk = rand() % 11 + 20;
    p->giveexp = 15;
}
void printplayerdata(PlayerData p){
	printf("%s\n",p.name);
	printf("���� %d, ��O %d, �t�� %d, �����O %d, �g��� %d\n",p.level,p.hp,p.speed,p.atk,p.exp);
	
}
void printmonsterdata(MonsterData p){
	printf("( ��O %d, �t�� %d, �����O %d, ���Ѹg��� %d )\n",p.hp,p.speed,p.atk,p.giveexp);
	
}

void atk_p2m(PlayerData player,MonsterData monster){
	printf("%s�����A�y���b�~�H���� %d �I�C\n",player.name,player.atk); 
}

void atk_m2p(PlayerData player,MonsterData monster){
	printf("�b�~�H�����A�y��%s���� %d �I�C\n",player.name,monster.atk); 
}
int main() {
    char input[100];  
    srand((unsigned)time(NULL));  

    PlayerData player;
    MonsterData monster[monstertotal];
	int i;
	initplayer(&player);
	for(i=0;i<monstertotal;i++)
		initmonster(&monster[i]);
	for(i=0;i<monstertotal;i++){
		printplayerdata(player);
		printf("\n");
		printf("\n�I��@���b�~�H�I ");
		printmonsterdata(monster[i]);
		if(monster[i].speed>player.speed){
			atk_m2p(player,monster[i]);
			player.hp -= monster[i].atk;
		}
		while(player.hp>0 && monster[i].hp>0){
			atk_p2m(player,monster[i]);
			monster[i].hp -= player.atk;
			if(monster[i].hp>0){
				atk_m2p(player,monster[i]);
				player.hp -= monster[i].atk;
			}
			else
				printf("%s���F�C\n",monster[i].name);	
		}
		if(player.hp<=0){
			printf("%s���F�C\n",player.name);
			break;
		}
		else{
			printf("%s��o�g��� %d�C\n",player.name,monster[i].giveexp);
			player.exp+=monster[i].giveexp;
			printf("\n");
		}
	}
	printplayerdata(player);
	
    return 0;
}

#include<stdio.h>

int main(){
	int sum=0,subjectall=0;
	char* subject[3] ={"���","�^��","�ƾ�"};
	int i,j,k,l;
	int score[2][3][5][3] =  // score[year][class][seatNo][subject = {Chinese, English, Math}]
	
	{ { {{98, 95, 92}, {89, 78, 82}, {88, 64, 64}, {61, 43, 44}, {48, 57, 58}},
	    {{86, 78, 44}, {65, 65, 63}, {56, 67, 77}, {47, 78, 43}, {54, 56, 58}},
	    {{46, 50, 76}, {65, 87, 66}, {64, 56, 66}, {92, 49, 86}, {45, 73, 83}} },
	    
	  { {{77, 52, 91}, {40, 45, 69}, {89, 70, 82}, {75, 94, 60}, {78, 86, 63}},
	    {{85, 50, 91}, {92, 70, 82}, {72, 64, 93}, {86, 75, 52}, {43, 40, 83}},
	    {{89, 92, 67}, {55, 61, 91}, {40, 54, 48}, {75, 79, 47}, {47, 44, 97}} } };
	    for(k=0;k<3;k++){//subject
	    	for(i=0;i<2;i++){//year
				for(subjectall=0,j=0;j<3;j++){//class
					for(sum=0,l=0;l<5;l++){//seat
						sum+=score[i][j][l][k];									
					}
					subjectall +=sum;
					printf("%d�~%d�Z�ǥ�%s���Z�`�M��%d ������%.2f\n",i+1,j+1,subject[k],sum,(sum*1.0/5));						
				}
				printf("\n");
				printf("%d�~�žǥ�%s���Z�`�M�� %d ������%.2f\n",i+1,subject[k],subjectall,subjectall*1.0/15);
				printf("\n");		
			}
		}
	
	return 0;
}

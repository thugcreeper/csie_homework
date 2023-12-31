#include<stdio.h>
#include<stdlib.h>  
#include<time.h>    

void shuffling(int a[], int n) {
    for (int i = 0; i < n; i++) {//fill the array with 1-49
        a[i] = i ;
    }
    int t;
    for (int k = 0; k < n; k++) {
        int c = rand() % n;//0-48
        int d = rand() % n;
        t = a[c];
        a[c] = a[d];
        a[d] = t;
    }
}

int checkPrize(int ticket[], int first[], int special) {
    int match = 0, isSpecial = 0;  
    for (int i = 0; i < 6; i++) {  // first
        for (int j = 0; j < 6; j++) {  // ticket
            if (first[i] == ticket[j])
                match++;
			
        }
		if (special == ticket[i])
        	isSpecial++;
    }
    	
	
    if (match == 6)
        return 8;

    if (match == 5 && isSpecial == 1)
        return 7;
    if (match == 5)
        return 6;
    if (match == 4 && isSpecial == 1)
        return 5; 
    if (match == 4)
        return 4;
    if (match == 3 && isSpecial == 1)
        return 3;
    if (match == 2 && isSpecial == 1)
        return 2;
    if (match == 3)
        return 1;
    else
        return 0;
}

int main() {
    int a[49] = {};
    srand((unsigned)time(NULL));
    char *prizeName[9] = {"", "General", "Seventh", "Sixth", "Fifth", "Fourth", "Third", "Second", "First"};
    int prize[9] = {0, 400, 400, 1000, 1286, 9781, 32705, 1569878, 19100192};
    int first[6], ticket[6], i,sum_of_money=0,ticket_amount,flag=0,special;
	while(flag == 0){
		printf("how many tickets u want to buy($50 per ticket): ");
   		scanf("%d",&ticket_amount);
   		if(ticket_amount<=0)
   			break;
	for(int i=0;i<ticket_amount;i++){			//�üƶ]n�� 
		shuffling(a, 49);
		special = a[6];	
		//printf("The first-prize numbers are ");
		for(int i=0;i<6;i++){
			first[i] = a[i]+1;
			//printf(" %d ",a[i]);
		}
		/*printf("\n");
		printf("The special number is");
		printf(" %d\n",special);
		printf("Your ticket numbers are ");*/
		
		for(int i=0;i<6;i++){
			shuffling(a, 49);
			ticket[i] =	a[i]+1;
			//printf("%d ",a[i]);
		}
		//printf("\n");
		int prizeCode = checkPrize(ticket,first,special);
		if (prizeCode > 0){
			//printf("You have won the %s Prize which is NT$%d!!\n", prizeName[prizeCode], prize[prizeCode]);
	        sum_of_money += prize[prizeCode];
		}	        
	    else{
			//printf("You did not win any prize.\n");
		}    
	        //printf("\n");
	}
		printf("\n***************************************************\n");
		printf("You spent $%d and won $%d.\n",ticket_amount*50,sum_of_money);
		printf("ROI is %lf\n",(sum_of_money)*1.0/(ticket_amount*50));
	}
   	
    return 0;
}


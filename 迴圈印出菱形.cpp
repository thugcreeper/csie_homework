#include <stdio.h>
#include <stdlib.h>

int main(){
    int size,i,j,sets,times=0;
    printf("How many sets of test data: ");			scanf("%d",&sets);
    printf("\n");
    while(times < sets){
    	printf("Size: ");							scanf("%d", &size);
	    if(size%2==1){ 
	      for(i=1; i<=size; i++){  // 遍歷所有行
	        if(i<(size+1)/2+1){  // 上半部分（包括中間一行）
	            for(j=1; j<=size; j++){  // 遍歷上半部分的所有列
	                if( (size+1)/2-(i-1)<=j && j<=(size+1)/2+(i-1) ){
	                    printf("$");
	                }else{
	                    printf("+");
	                }
	            }
	        }else{  // 下半部分
	            for(j=1; j<=size; j++){  // 遍歷下半部分的所有列
	                if( (size+1)/2-(size-i)<=j && j<=(size+1)/2+(size-i) ){
	                    printf("$");
	                }else{
	                    printf("+");
	                }
	            }
	        }
	        printf("\n");
	    }  
	    }
    printf("\n");

    
    times ++;
}
    return 0;
}

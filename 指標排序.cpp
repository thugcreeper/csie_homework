#include<stdio.h>
#include<stdlib.h>
void sort3(int *x, int *y, int *z){
	if(*x>*y){
		int t = *x;
		*x = *y;
		*y = t;
	}
	if(*x>*z){
		int t = *x;
		*x = *z;
		*z = t;
	}
	if(*y>*z){
		int t = *y;
		*y = *z;
		*z = t;
	}
}
int main() {
    int x, y, z, ti, repeatTimes;
    printf("How many sets of test data: ");
    scanf("%d",&repeatTimes);
    	for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nPlease input three numbers: ");
        scanf("%d%d%d", &x, &y, &z);
        sort3(&x, &y, &z);
        printf("Results after sorting: %d, %d, %d\n", x, y, z);
	}
    return 0;
}

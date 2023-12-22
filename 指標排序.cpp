#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int*b){
	int t = *a;
		*a = *b;
		*b = t;
}
void sort3(int *x, int *y, int *z){
	if(*x>*y)
		swap(x,y);
	if(*x>*z)
		swap(x,z);
	if(*y>*z)
	swap(y,z);
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

#include<stdio.h>
void printGameField(int puzzle[9][9]){
int i,j;

    printf("��������������������������������������������������������\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if(j%3==0)
                printf("�� %d", puzzle[i][j]);
            else
                printf("�x %d", puzzle[i][j]);
        }
        printf("��\n");
        if(i<8&&i%3==2)
        printf("�������q�����q�����������q�����q�����������q�����q������\n");
        else if(i<8)
        printf("��w�w�q�w�w�q�w�w��w�w�q�w�w�q�w�w��w�w�q�w�w�q�w�w��\n");
    }
    printf("��������������������������������������������������������");
}
void inputQuiz(int puzzle[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%1d",&puzzle[i][j]);
        }
    }
}
int main(){
    int puzzle[9][9]={};
    inputQuiz(puzzle);
    printGameField(puzzle);
    return 0;
}

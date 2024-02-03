#include<stdio.h>
int puzzle[9][9]={};
int candidate[9][9][10]={};
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
    printf("��������������������������������������������������������\n");
}
void inputQuiz(int puzzle[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            puzzle[i][j]=0;
            scanf("%1d",&puzzle[i][j]);// �N�Ҧ���l���]�� 0, �A����LŪ�J�D��
        }
    }
}
void removeCandidate(int i, int j, int value) { // �� puzzle[i][j] �T�w��J value, ��L��N�����
    for(int row=0;row<9;row++){//�P�@�C�� candidate[??][??][value] �אּ 0 or false
        candidate[i][row][value]=0;
    }
    for(int col=0;col<9;col++){//�P�@�椧 candidate[??][??][value] �אּ 0 or false
        candidate[col][j][value]=0;
    }
    for(int a=i/3*3;a<i/3*3+3;a++){
        for(int b=j/3*3;b<j/3*3+3;b++){//�P�@�c�� candidate[a][b][value] �אּ 0 or false // a, b ���_�׽d��i�� i, j ��X
            candidate[a][b][value]=0;
        }
    }
    for(int a=1;a<=9;a++){
        candidate[i][j][a]=0;//puzzle[i][j] �� candidate[i][j][???] ���אּ 0 or false
    }
}
void startFindSolution() {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<10;k++){
                candidate[i][j][k]=1;
            }
        }
    }
    for(int i=0;i<9;i++){//�ˬd�C�@�� puzzle[i][j],puzzle[i][j] ���Ȫ��ɭԩI�s removeCandidate(...)
        for(int j=0;j<9;j++){
            if(puzzle[i][j]>0)
                removeCandidate(i,j,puzzle[i][j]);
        }
    }
}
int solveBySingleSol() {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){//�ˬd�C�@�� puzzle[i][j]
            if(puzzle[i][j]==0){//�� puzzle[i][j] �S���ȦӥB�u���@�ض�k,puzzle[i][j] ��J��,�I�s removeCandidate(...)
                int count =0,ans;
                for(int k=1;k<=9;k++){
                    if(candidate[i][j][k]>0){
                        count++;
                        ans=k;
                    }
                }
                if(count==1){
                    puzzle[i][j]=ans;
                    removeCandidate(i, j, ans);
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    inputQuiz(puzzle);
    printGameField(puzzle);
    startFindSolution();
    int yes = 1;
    while (yes > 0) {
        yes = 0;
        yes += solveBySingleSol();
        // yes += otherSolution(); // add other solutions in the future
    }
    printGameField(puzzle);
    return 0;
}

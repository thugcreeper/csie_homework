#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int year;
    int month;
    int day;
} DateData;
typedef struct {
    char ID[13], nickname[31];
    int loginTimes, articles, money;
    DateData lastLogin;
    char gender, flags;
} BloggerData;

int main(){
	BloggerData person[100]={};
	FILE *fptr = fopen("bloggerData_BIG5.data", "rb");
	if (fptr == NULL){   
		printf("�}�ɥ���\n");   
		return 1;
	}
	fseek(fptr,0,SEEK_END);//Ū���Y���ʨ���K
	int fsize = ftell(fptr);//���o�ɮפj�p 
	rewind(fptr); //Ū���Y���ʨ�}�Y
	int totalnum=fsize/sizeof(BloggerData);
	fread(person,sizeof(BloggerData),totalnum,fptr);//fread() to read data from the file into the array.
	fclose(fptr);
	FILE *fp;
	fp =fopen("blogger's_data.txt","w");
	printf("�`�@Ū�i %d �쳡���ȸ�ơC\n",totalnum);
	for(int i=0;i<totalnum;i++){
		fprintf(fp,"\nBlogger#%d:\n",i);
		fprintf(fp,"ID = %s\n",person[i].ID);
		fprintf(fp,"nickname = %s\n",person[i].nickname);
		fprintf(fp,"loginTimes = %d\n",person[i].loginTimes);
		fprintf(fp,"articles = %d\n",person[i].articles);
		fprintf(fp,"money = %d\n",person[i].money);
		fprintf(fp,"lastLogin = %d/%d/%d\n",person[i].lastLogin.year,person[i].lastLogin.month,person[i].lastLogin.day);
		fprintf(fp,"gender = %c\n",person[i].gender);
		fprintf(fp,"flags = %d\n",person[i].flags);
		fprintf(fp,"\n");
	}
	return 0;
}

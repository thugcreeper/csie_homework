#include <stdio.h>

void getdate(int *year,int *month,int *day);

int getzodiaccode(int year,int month,int day)
{
	int beginningDay[12]={20,20,21,21,21,22,23,23,23,23,22,22};
	int zodiacCode=(month+9)%12;
	if (day < beginningDay[month-1])
	{
		 zodiacCode = (zodiacCode + 11) % 12;
	}
	return zodiacCode;
}

int main()
{
	int matchScore[12][12]=
	{ // matchScore[�k�Ī��ͨv][�k�Ī��ͨv]
		90, 75, 82, 47, 94, 65, 85, 70, 99, 58, 88, 79,
		68, 88, 72, 75, 45, 97, 57, 78, 61, 93, 66, 81,
		79, 76, 89, 71, 81, 57, 93, 69, 86, 64, 99, 48,
		52, 82, 78, 89, 61, 84, 66, 92, 70, 87, 74, 97,
		97, 56, 79, 69, 87, 72, 81, 45, 92, 77, 84, 62,
		61, 91, 76, 88, 66, 89, 49, 81, 72, 95, 55, 84,
		85, 74, 98, 58, 88, 77, 90, 71, 80, 47, 95, 64,
		60, 80, 68, 97, 65, 84, 73, 87, 47, 76, 57, 92,
		92, 70, 81, 65, 98, 58, 86, 68, 89, 75, 78, 44,
		43, 97, 70, 80, 59, 92, 51, 85, 64, 88, 74, 77,
		72, 41, 91, 58, 78, 64, 96, 51, 82, 69, 87, 60,
		71, 78, 46, 93, 61, 65, 74, 99, 54, 82, 69, 88
	};
	char * zodiacName[12] = {"�d�Ϯy", "�����y", "���l�y","���ɮy","��l�y","�B�k�y","�ѯ��y","���Ȯy","�g��y","���~�y","���~�y","�����y"};
	int boyyear,boymonth,boyday;
	int girlyear,girlmonth,girlday;
	
	printf("�п�J�k�ͪ��ͤ�C\n");
	getdate(&boyyear,&boymonth,&boyday);
	printf("�п�J�k�ͪ��ͤ�C\n");
	getdate(&girlyear,&girlmonth,&girlday);
	
	int boycode=getzodiaccode(boyyear,boymonth,boyday);
	int girlcode=getzodiaccode(girlyear,girlmonth,girlday);
	
	printf("�k�ͬO%s�A�k�ͬO%s�C\n",zodiacName[boycode],zodiacName[girlcode]);
	printf("��H���t�t���ƬO %d!!!",matchScore[girlcode][boycode]);

return 0;
} 

bool isleapyear(int *year)
{
	 if(*year%4 == 0)
    {
        if( *year%100 == 0)
        {
            if ( *year%400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
       return 0;
}

bool notlegaldate(int *year,int *month,int *day)
{
	int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(isleapyear(year))
	{
		monthday[1]=29;
		if(*month>12||*month<1||*day<1||*day>monthday[*month-1])
		{
			printf("�o���O�X�k������C\n");
			return 1;
		}
		else
		return 0;
	}
	
	else
	{
		if(*month>12||*month<1||*day<1||*day>monthday[*month-1])
		{
			printf("�o���O�X�k������C\n");
			return 1;
		}
		else
		return 0;
	}
	
	
}

void getdate(int *year,int *month,int *day)
{
	do
	{
		scanf("%d/%d/%d",year,month,day);
	}
	while(notlegaldate(year,month,day));
}

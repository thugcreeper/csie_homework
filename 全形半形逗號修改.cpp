#include<stdio.h> 
#include<string.h>

int main() {
    char test[200] = "amsd�Aams�Aowjej�Aelp[";
    char fuck[69] = "asd�Aa378q�Aoapokej�A+as1z";
    char *p = strstr(test, "�A");
    char *p2 = strstr(fuck, "�A");
    printf("%s\n", test);
    printf("%s\n", fuck);
	printf("\n");
    while (p != NULL) {
        *p = ',';
        *(p + 1) = ' ';
        p = strstr(p + 1, "�A");
    }

    while (p2 != NULL) {
        *p2=',';
        printf("%s\n",p2);//��Xp2���V���r��
        strncpy(p2 + 1, p2 + 2, strlen(p2 + 1));//strlen�p��q p2 + 1 �}�l���r�ꪺ����
        p2 = strstr(p2 + 1, "�A");
    }

    printf("\n%s\n", test);
    printf("%s", fuck);

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    int repeatTimes, ti;
    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes);
    if (getchar() == '\r') getchar();//to skip '\r' and '\n' so that fgets(...) will not mistakenly get an empty line.

    char sent[300];
    for (ti = 0; ti < repeatTimes; ti++) {
        const char *p = sent;
        printf("\n");
        printf("Input a line:\n");
        fgets(sent, sizeof(sent), stdin);//�ϥ� fgets(...) Ū�i�@���A���� strtok(...) �ӧR�����������Ÿ�
        strtok(sent, "\r\n");

        printf("Modified line:\n");
        while (*p != '\0') {
            if (*p == '.' || *p == '%' || (*p >= '0' && *p <= '9')) {
                printf("%c", *p);
            } else {
                printf("_");
            }
            p++;
        }
        printf("\n");
    }
    return 0;
}




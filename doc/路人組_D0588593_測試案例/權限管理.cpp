#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <io.h>
#define MAX_Str 20
#define UserNum 3 //�b��ƶq(�]�}�C�}�l�Ȭ�0,�GUserNum���]�w����ڱb��ƶq-1)
typedef struct
{
    char account[MAX_Str];  //�b��
    char password[MAX_Str]; //�K�X
    int permission;         //�v��
    char name[MAX_Str];     //�m�W
} USER;

int main()
{
    USER DataUser;
    USER user[3];
    FILE *fptr;
    fptr = fopen("data.txt", "r"); //Ū��data.txt�����
    if (fptr == NULL)
    {
        printf("\n�ɮ�Ū������\n");
        exit(0);
    }
    int i = 0, ID; //ID���n�J�b�����\user[i]��i��

    //�N��ƶפJ�{����
    char DataUserAcc[MAX_Str], DataUserPW[MAX_Str], DataUserName[MAX_Str];
    int DataUserPerm;
    while (fscanf(fptr, "%s\t%s\t%d\t%s", DataUserAcc, DataUserPW, &DataUserPerm, DataUserName) != EOF)
    {
        strcpy(user[i].account, DataUserAcc);
        strcpy(user[i].password, DataUserPW);
        user[i].permission = DataUserPerm;
        strcpy(user[i].name, DataUserName);
    //test
    /*	printf("%5s\n",user[i].account);
	printf("%5s\n",user[i].password);
	printf("%5d\n",user[i].permission);
	printf("%5s\n",user[i].name);*/
        i++;
    }
    //�פJ����

    char InputAcc[MAX_Str], InputPW[MAX_Str];
    printf("\n�п�J�b��:");
    scanf("%s", &InputAcc);
    for (int i = 0; i < UserNum;)
    {
        if (strcmp(InputAcc, user[i].account) != 0)
        {
            i++;
        } //������異��,����Ʈw�U�@�ӱb��
        if (strcmp(InputAcc, user[i].account) == 0)
        {
            ID = i;
            break;
        } //��令�\,�T�wID�öi�J��J�K�X���q
        if (i == UserNum)
        {
            printf("\n�L���b��");
            exit(0);
        } //��粒��,�d�L��J���b��
    }

    printf("\n�п�J�K�X:");
    scanf("%s", &InputPW);
    if (strcmp(InputPW, user[ID].password) == 0)
    { //���K�X
        printf("\n�n�J���\\!");
    }
    else
    { //��J�K�X���~,��異��
        printf("\n�K�X���~");
        exit(0);
    }

    printf("\n�ϥΪ̬�:%7s", user[ID].name);
    printf("\n�v�����Ŭ�:%2d", user[ID].permission);
    printf("\n\n�w��ϥγ{�ҤH�����t��!\n\n");

    system("pause");
    return 0; //����
}

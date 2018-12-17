#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <io.h>
#define MAX_Str 20
#define UserNum 3 //帳戶數量(因陣列開始值為0,故UserNum須設定為實際帳戶數量-1)
typedef struct
{
    char account[MAX_Str];  //帳號
    char password[MAX_Str]; //密碼
    int permission;         //權限
    char name[MAX_Str];     //姓名
} USER;

int main()
{
    USER DataUser;
    USER user[3];
    FILE *fptr;
    fptr = fopen("data.txt", "r"); //讀取data.txt的資料
    if (fptr == NULL)
    {
        printf("\n檔案讀取失敗\n");
        exit(0);
    }
    int i = 0, ID; //ID為登入帳號成功user[i]的i值

    //將資料匯入程式中
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
    //匯入完畢

    char InputAcc[MAX_Str], InputPW[MAX_Str];
    printf("\n請輸入帳號:");
    scanf("%s", &InputAcc);
    for (int i = 0; i < UserNum;)
    {
        if (strcmp(InputAcc, user[i].account) != 0)
        {
            i++;
        } //本次比對失敗,比對資料庫下一個帳號
        if (strcmp(InputAcc, user[i].account) == 0)
        {
            ID = i;
            break;
        } //比對成功,確定ID並進入輸入密碼階段
        if (i == UserNum)
        {
            printf("\n無此帳號");
            exit(0);
        } //比對完畢,查無輸入之帳號
    }

    printf("\n請輸入密碼:");
    scanf("%s", &InputPW);
    if (strcmp(InputPW, user[ID].password) == 0)
    { //比對密碼
        printf("\n登入成功\!");
    }
    else
    { //輸入密碼錯誤,比對失敗
        printf("\n密碼錯誤");
        exit(0);
    }

    printf("\n使用者為:%7s", user[ID].name);
    printf("\n權限等級為:%2d", user[ID].permission);
    printf("\n\n歡迎使用逢甲人評分系統!\n\n");

    system("pause");
    return 0; //結束
}

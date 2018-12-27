#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_Str 20
#define UserNum 3 //帳戶數量(因陣列開始值為0,故UserNum須設定為實際帳戶數量-1)
#define MAX_Team 5
#define MAX_Member 10
typedef struct
{
    char account[MAX_Str];  //帳號
    char password[MAX_Str]; //密碼
    int permission;         //權限
    char name[MAX_Str];     //姓名
} USER;

typedef struct
{
    int LeadershipP;    //領導能力評分
    int ParticipationP; //參與程度評分
    int SkillP;         //專業技術評分
    int DocumentP;      //文書處理評分
    int SpeechP;        //演講能力評分
    int count;      //被修改過的次數
} Grade;

typedef struct
{
    char StudentName[MAX_Str]; //名字
    char PhoneNum[MAX_Str];    //電話
    char Email[50];            //信箱
    char CustomContent[100];   //自訂內容
    Grade grade;
} ContactData;

//權限控管系統
int AuthorizeLevel;
USER AuthorizeControl()
{
    USER DataUser;
    USER user[UserNum];
    USER LoginAcc;
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
CheckAcc:
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
            printf("\n提示:無此帳號\n");
            goto CheckAcc;
        } //比對完畢,查無輸入之帳號
    }

CheckPW:
    printf("\n請輸入密碼:");
    scanf("%s", &InputPW);
    if (strcmp(InputPW, user[ID].password) == 0)
    { //比對密碼
        printf("\n登入成功\!");
    }
    else
    { //輸入密碼錯誤,比對失敗
        printf("\n提示:密碼錯誤\n");
        goto CheckPW;
    }

    printf("\n使用者為:%7s", user[ID].name);
    printf("\n權限等級為:%2d", user[ID].permission);
    printf("\n\n歡迎使用逢甲人評分系統!\n\n");
    LoginAcc = user[ID];
    return LoginAcc;
}
//權限控管結束 
//---------------------------------------------------------------------------------
//聯絡方式系統
char UserPhoneNum[MAX_Str], UserEmail[50], UserCustomContent[100]; //個人聯絡資料
void modify()
{
    printf("\n請輸入電話號碼:");
    scanf("%s", &UserPhoneNum);
    printf("請輸入信箱:");
    scanf("%s", &UserEmail);
    printf("請輸入自訂內容:");
    scanf("%s", &UserCustomContent);
}
void display()
{
    printf("\n電話 : %s\n信箱 : %s\n其他資訊 : %s\n", UserPhoneNum, UserEmail, UserCustomContent);
}
void ContactInformation() //聯絡方式設定
{
    int selection;
    printf("\n請輸入代號:");
    printf("\n1:修改個人聯絡資料\n2:顯示個人聯絡資料\n3:離開\n");
    scanf("%d", &selection);

    switch (selection)
    {

    case 1:
        modify(); //修改個人聯絡資料
        printf("\n提示:修改完成\n");
        ContactInformation();
        break;

    case 2:
        display(); //顯示個人聯絡資料
        ContactInformation();
        break;
    case 3:
        break; //離開此功能

    default:
        printf("提示:輸入錯誤\n");
        ContactInformation();
        break;
    }
}
//聯絡方式系統結束 
//---------------------------------------------------------------------------------
//分組系統
int TeamCheck = 0;
void CreateTeam() //創建組別
{
    if (TeamCheck == 0)
    {
        TeamCheck = 4;
        printf("提示:創建完成，組別為第4組\n");
    }
    else
    {
        printf("提示:已有組別\n");
    }
}

void ApplyForAdd() //申請入組
{
    if (TeamCheck != 0)
    {
        printf("提示:已有組別!\n");
    }
    else
    {
        int selection;
        printf("\n請輸入要加入的組別: 1/2/3\n若輸入0則離開 :");
        scanf("%d", &selection); 
        switch (selection)
        {
        case 0:
            break;
        case 1:
            TeamCheck = 1;
            printf("提示:加入組別1成功\!\n");
            break;
        case 2:
            TeamCheck = 2;
            printf("提示:加入組別2成功\!\n");
            break;
        case 3:
            TeamCheck = 3;
            printf("提示:加入組別3成功\!\n");
            break;
        default:
            printf("\n提示:輸入錯誤\n");
            ApplyForAdd();
            break;
        }
    }
}

void ApplyForLeave() //申請退組
{
    if (TeamCheck == 0)
    {
        printf("提示:未有組別\n");
    }
    else
    {
        printf("提示:已退出組別%d\n", TeamCheck);
        TeamCheck = 0;
    }
}
void SearchMember() //查詢組別成員
{
    if (TeamCheck == 0)
    {
        printf("提示:未有組別\n");
    }
    else if (TeamCheck == 4)
    {
        printf("提示:未有組員\n");
    }
    else
    {
        ContactData DataUser;
        ContactData classmate[MAX_Team][MAX_Member];
        FILE *fptr2;
        if (TeamCheck == 1)
        {
            fptr2 = fopen("ContactDetail1.txt", "r");
        }
        if (TeamCheck == 2)
        {
            fptr2 = fopen("ContactDetail2.txt", "r");
        }
        if (TeamCheck == 3)
        {
            fptr2 = fopen("ContactDetail3.txt", "r");
        }
        if (fptr2 == NULL)
        {
            printf("\n檔案讀取失敗\n");
            exit(0);
        }
        int i = 0;
        //將資料匯入程式中
        char TempStudentName[MAX_Str], TempPhoneNum[MAX_Str], TempEmail[50], TempCustomContent[100];
        while (fscanf(fptr2, "%s\t%s\t%s\t%s", TempStudentName, TempPhoneNum, TempEmail, TempCustomContent) != EOF)
        {
            strcpy(classmate[TeamCheck][i].StudentName, TempStudentName);
            strcpy(classmate[TeamCheck][i].PhoneNum, TempPhoneNum);
            strcpy(classmate[TeamCheck][i].Email, TempEmail);
            strcpy(classmate[TeamCheck][i].CustomContent, TempCustomContent);
            i++;
        }
    //匯入完畢
    ChooseMember:
        int selection;
        printf("\n請選擇要查詢的組員:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d:%s\n", j + 1, classmate[TeamCheck][j].StudentName);
        }
        scanf("%d", &selection);
        if (selection > i)
        {
            printf("\n提示:輸入錯誤\n");
            goto ChooseMember;
        }
        printf("\n姓名 : %s\n電話 : %s\n信箱 : %s\n其他資訊 : %s\n",
		 classmate[TeamCheck][selection - 1].StudentName, 
		 classmate[TeamCheck][selection - 1].PhoneNum, 
		 classmate[TeamCheck][selection - 1].Email, 
		 classmate[TeamCheck][selection - 1].CustomContent);
    }
}
 
void GroupingFunction()
{
    int selection;
    printf("\n請輸入代號:");
    printf("\n1:創建組別\n2:申請入組\n3:申請退組\n4:查詢組別成員\n5:離開\n");
    scanf("%d", &selection);

    switch (selection)
    {

    case 1:
        CreateTeam(); //創建組別
        GroupingFunction();
        break;

    case 2:
        ApplyForAdd(); //申請入組
        GroupingFunction();
        break;
    case 3:
        ApplyForLeave(); //申請退組
        GroupingFunction();
        break;
    case 4:
        SearchMember(); //查詢組別成員
        GroupingFunction();
        break;
    case 5:
        break;
    default:
        printf("提示:輸入錯誤\n");
        GroupingFunction();
        break;
    }
}
//分組系統結束 
//---------------------------------------------------------------------------------
//評分系統
/*void ImportRatingSystemData ()
{
if (TeamCheck==0){printf("提示:未有組別\n");
	}else if(TeamCheck==4){printf("提示:未有組員\n");
	}else{ 
	  ContactData DataUser;
      ContactData classmate[MAX_Team][MAX_Member];
      FILE *fptr2;
      if (TeamCheck==1){fptr2 = fopen("ContactDetail1.txt", "r");}
      if (TeamCheck==2){fptr2 = fopen("ContactDetail2.txt", "r");}
      if (TeamCheck==3){fptr2 = fopen("ContactDetail3.txt", "r");}
      if (fptr2 == NULL)
      {
        printf("\n檔案讀取失敗\n");
        exit(0);
      }
      int i = 0;
      //將資料匯入程式中
      char TempStudentName[MAX_Str], TempPhoneNum[MAX_Str], TempEmail[50], TempCustomContent[100];
      while (fscanf(fptr2, "%s\t%s\t%s\t%s", TempStudentName, TempPhoneNum, TempEmail, TempCustomContent) != EOF)
      {
        strcpy(classmate[TeamCheck][i].StudentName, TempStudentName);
        strcpy(classmate[TeamCheck][i].PhoneNum, TempPhoneNum);
        strcpy(classmate[TeamCheck][i].Email, TempEmail);
        strcpy(classmate[TeamCheck][i].CustomContent, TempCustomContent);
        i++;
      }
    //匯入完畢
}
*/
ContactData classmate[MAX_Team][MAX_Member];
void RateTeammate()
{
    if (TeamCheck == 0)
    {
        printf("提示:未有組別\n");
    }
    else if (TeamCheck == 4)
    {
        printf("提示:未有組員\n");
    }
    else
    {
        ContactData DataUser;
        FILE *fptr2;
        if (TeamCheck == 1)
        {
            fptr2 = fopen("ContactDetail1.txt", "r");
        }
        if (TeamCheck == 2)
        {
            fptr2 = fopen("ContactDetail2.txt", "r");
        }
        if (TeamCheck == 3)
        {
            fptr2 = fopen("ContactDetail3.txt", "r");
        }
        if (fptr2 == NULL)
        {
            printf("\n檔案讀取失敗\n");
            exit(0);
        }
        int i = 0;
        //將資料匯入程式中
        char TempStudentName[MAX_Str], TempPhoneNum[MAX_Str], TempEmail[50], TempCustomContent[100];
        while (fscanf(fptr2, "%s\t%s\t%s\t%s", TempStudentName, TempPhoneNum, TempEmail, TempCustomContent) != EOF)
        {
            strcpy(classmate[TeamCheck][i].StudentName, TempStudentName);
            strcpy(classmate[TeamCheck][i].PhoneNum, TempPhoneNum);
            strcpy(classmate[TeamCheck][i].Email, TempEmail);
            strcpy(classmate[TeamCheck][i].CustomContent, TempCustomContent);
            i++;
        }
    //匯入完畢
    ChooseMember:
        int selection;
        printf("\n請選擇要評分的組員:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d:%s\n", j + 1, classmate[TeamCheck][j].StudentName);
        }
        scanf("%d", &selection);
        if (selection > i)
        {
            printf("\n提示:輸入錯誤\n");
            goto ChooseMember;
        }

        if (classmate[TeamCheck][selection - 1].grade.count < 3)
        {
            printf("\n開始評分");
            printf("\n請輸入對%s的評分: [0~100]", &classmate[TeamCheck][selection - 1].StudentName);
            printf("\n領導能力 : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.LeadershipP);
            printf("參與程度 : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.ParticipationP);
            printf("專業技術 : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.SkillP);
            printf("文書處理 : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.DocumentP);
            printf("演講能力 : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.SpeechP);
            classmate[TeamCheck][selection - 1].grade.count++;
            printf("\n提示:評分完成   (修改次數剩餘:%2d)", 3 - classmate[TeamCheck][selection - 1].grade.count);
        }
        else
        {
            printf("\n提示:已對該成員修改超過2次評分，禁止再進行修改");
        }
    }
}

void SearchTeammateRating()
{
    if (TeamCheck == 0)
    {
        printf("提示:未有組別\n");
    }
    else if (TeamCheck == 4)
    {
        printf("提示:未有組員\n");
    }
    else
    {
        ContactData DataUser;
        FILE *fptr2;
        if (TeamCheck == 1)
        {
            fptr2 = fopen("ContactDetail1.txt", "r");
        }
        if (TeamCheck == 2)
        {
            fptr2 = fopen("ContactDetail2.txt", "r");
        }
        if (TeamCheck == 3)
        {
            fptr2 = fopen("ContactDetail3.txt", "r");
        }
        if (fptr2 == NULL)
        {
            printf("\n檔案讀取失敗\n");
            exit(0);
        }
        int i = 0;
        //將資料匯入程式中
        char TempStudentName[MAX_Str], TempPhoneNum[MAX_Str], TempEmail[50], TempCustomContent[100];
        while (fscanf(fptr2, "%s\t%s\t%s\t%s", TempStudentName, TempPhoneNum, TempEmail, TempCustomContent) != EOF)
        {
            strcpy(classmate[TeamCheck][i].StudentName, TempStudentName);
            strcpy(classmate[TeamCheck][i].PhoneNum, TempPhoneNum);
            strcpy(classmate[TeamCheck][i].Email, TempEmail);
            strcpy(classmate[TeamCheck][i].CustomContent, TempCustomContent);
            i++;
        }
    //匯入完畢
    ChooseMember:
        int selection;
        printf("\n請選擇要查詢的組員:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d:%s\n", j + 1, classmate[TeamCheck][j].StudentName);
        }
        scanf("%d", &selection);
        if (selection > i)
        {
            printf("\n提示:輸入錯誤\n");
            goto ChooseMember;
        }

        if (classmate[TeamCheck][selection - 1].grade.count != 0)
        {
        	printf("\n%s的評分 : ",classmate[TeamCheck][selection - 1].StudentName);
        	printf("\n領導能力 : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.LeadershipP;k>0;k=k-5)printf("▇");
            printf("\n參與程度 : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.ParticipationP;k>0;k=k-5)printf("▇");
            printf("\n專業技術 : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.SkillP;k>0;k=k-5)printf("▇");
            printf("\n文書處理 : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.DocumentP;k>0;k=k-5)printf("▇");
            printf("\n演講能力 : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.SpeechP;k>0;k=k-5)printf("▇");
            int AvgGrade = 
			(classmate[TeamCheck][selection - 1].grade.LeadershipP+
            classmate[TeamCheck][selection - 1].grade.ParticipationP+
            classmate[TeamCheck][selection - 1].grade.SkillP+
            classmate[TeamCheck][selection - 1].grade.DocumentP+
            classmate[TeamCheck][selection - 1].grade.SpeechP)/5;
            printf("\n綜合評價 : ");
            for(int k=AvgGrade;k>0;k=k-5)printf("▇");
            printf("\n");
        }
        else
        {
            printf("\n提示:尚未對該成員進行評分");
        }
    }
}

void RatingSystem()
{
    int selection;
    printf("\n請輸入代號:");
    printf("\n1:對組員評分\n2:查詢組別成員評分\n3:離開\n");
    scanf("%d", &selection);

    switch (selection)
    {

    case 1:
        RateTeammate(); //對組員評分
        RatingSystem();
        break;
    case 2:
        SearchTeammateRating(); //查詢組別成員評分
        RatingSystem();
        break;
    case 3:
        break;
    default:
        printf("提示:輸入錯誤\n");
        RatingSystem();
        break;
    } 
}
//評分系統結束
 //---------------------------------------------------------------------------------
void ChooseFunction()
{ //功能選擇
    int selection;
    printf("\n請輸入代號:");
    printf("\n1:聯絡方式設定\n2:分組系統\n3:評分系統\n4:離開程式\n");
    scanf("%d", &selection);

    switch (selection)
    {

    case 1:
        ContactInformation(); //聯絡方式設定
        break;

    case 2:
        GroupingFunction(); //分組系統
        break;

    case 3:
        RatingSystem(); //評分系統
        break;

    case 4:
        exit(0); //離開程式
        break;

    default:
        printf("提示:輸入錯誤\n");
        ChooseFunction();
        break;
    }
}
//---------------------------------------------------------------------------------
//main
int main()
{
    USER LoginAcc;
    LoginAcc = AuthorizeControl();
    AuthorizeLevel = LoginAcc.permission;
    //test
    /*printf("\n使用者為:%7s", LoginAcc.name);
    printf("\n權限等級為:%2d", LoginAcc.permission);
    printf("\n\n歡迎使用逢甲人評分系統!\n\n");*/
    while (1)
    {
        ChooseFunction();
    }
    system("pause");
    return 0;
}

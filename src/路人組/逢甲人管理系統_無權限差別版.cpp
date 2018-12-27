#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_Str 20
#define UserNum 3 //�b��ƶq(�]�}�C�}�l�Ȭ�0,�GUserNum���]�w����ڱb��ƶq-1)
#define MAX_Team 5
#define MAX_Member 10
typedef struct
{
    char account[MAX_Str];  //�b��
    char password[MAX_Str]; //�K�X
    int permission;         //�v��
    char name[MAX_Str];     //�m�W
} USER;

typedef struct
{
    int LeadershipP;    //��ɯ�O����
    int ParticipationP; //�ѻP�{�׵���
    int SkillP;         //�M�~�޳N����
    int DocumentP;      //��ѳB�z����
    int SpeechP;        //�t����O����
    int count;      //�Q�ק�L������
} Grade;

typedef struct
{
    char StudentName[MAX_Str]; //�W�r
    char PhoneNum[MAX_Str];    //�q��
    char Email[50];            //�H�c
    char CustomContent[100];   //�ۭq���e
    Grade grade;
} ContactData;

//�v�����ިt��
int AuthorizeLevel;
USER AuthorizeControl()
{
    USER DataUser;
    USER user[UserNum];
    USER LoginAcc;
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
CheckAcc:
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
            printf("\n����:�L���b��\n");
            goto CheckAcc;
        } //��粒��,�d�L��J���b��
    }

CheckPW:
    printf("\n�п�J�K�X:");
    scanf("%s", &InputPW);
    if (strcmp(InputPW, user[ID].password) == 0)
    { //���K�X
        printf("\n�n�J���\\!");
    }
    else
    { //��J�K�X���~,��異��
        printf("\n����:�K�X���~\n");
        goto CheckPW;
    }

    printf("\n�ϥΪ̬�:%7s", user[ID].name);
    printf("\n�v�����Ŭ�:%2d", user[ID].permission);
    printf("\n\n�w��ϥγ{�ҤH�����t��!\n\n");
    LoginAcc = user[ID];
    return LoginAcc;
}
//�v�����޵��� 
//---------------------------------------------------------------------------------
//�p���覡�t��
char UserPhoneNum[MAX_Str], UserEmail[50], UserCustomContent[100]; //�ӤH�p�����
void modify()
{
    printf("\n�п�J�q�ܸ��X:");
    scanf("%s", &UserPhoneNum);
    printf("�п�J�H�c:");
    scanf("%s", &UserEmail);
    printf("�п�J�ۭq���e:");
    scanf("%s", &UserCustomContent);
}
void display()
{
    printf("\n�q�� : %s\n�H�c : %s\n��L��T : %s\n", UserPhoneNum, UserEmail, UserCustomContent);
}
void ContactInformation() //�p���覡�]�w
{
    int selection;
    printf("\n�п�J�N��:");
    printf("\n1:�ק�ӤH�p�����\n2:��ܭӤH�p�����\n3:���}\n");
    scanf("%d", &selection);

    switch (selection)
    {

    case 1:
        modify(); //�ק�ӤH�p�����
        printf("\n����:�ק粒��\n");
        ContactInformation();
        break;

    case 2:
        display(); //��ܭӤH�p�����
        ContactInformation();
        break;
    case 3:
        break; //���}���\��

    default:
        printf("����:��J���~\n");
        ContactInformation();
        break;
    }
}
//�p���覡�t�ε��� 
//---------------------------------------------------------------------------------
//���ըt��
int TeamCheck = 0;
void CreateTeam() //�ЫزէO
{
    if (TeamCheck == 0)
    {
        TeamCheck = 4;
        printf("����:�Ыا����A�էO����4��\n");
    }
    else
    {
        printf("����:�w���էO\n");
    }
}

void ApplyForAdd() //�ӽФJ��
{
    if (TeamCheck != 0)
    {
        printf("����:�w���էO!\n");
    }
    else
    {
        int selection;
        printf("\n�п�J�n�[�J���էO: 1/2/3\n�Y��J0�h���} :");
        scanf("%d", &selection); 
        switch (selection)
        {
        case 0:
            break;
        case 1:
            TeamCheck = 1;
            printf("����:�[�J�էO1���\\!\n");
            break;
        case 2:
            TeamCheck = 2;
            printf("����:�[�J�էO2���\\!\n");
            break;
        case 3:
            TeamCheck = 3;
            printf("����:�[�J�էO3���\\!\n");
            break;
        default:
            printf("\n����:��J���~\n");
            ApplyForAdd();
            break;
        }
    }
}

void ApplyForLeave() //�ӽаh��
{
    if (TeamCheck == 0)
    {
        printf("����:�����էO\n");
    }
    else
    {
        printf("����:�w�h�X�էO%d\n", TeamCheck);
        TeamCheck = 0;
    }
}
void SearchMember() //�d�߲էO����
{
    if (TeamCheck == 0)
    {
        printf("����:�����էO\n");
    }
    else if (TeamCheck == 4)
    {
        printf("����:�����խ�\n");
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
            printf("\n�ɮ�Ū������\n");
            exit(0);
        }
        int i = 0;
        //�N��ƶפJ�{����
        char TempStudentName[MAX_Str], TempPhoneNum[MAX_Str], TempEmail[50], TempCustomContent[100];
        while (fscanf(fptr2, "%s\t%s\t%s\t%s", TempStudentName, TempPhoneNum, TempEmail, TempCustomContent) != EOF)
        {
            strcpy(classmate[TeamCheck][i].StudentName, TempStudentName);
            strcpy(classmate[TeamCheck][i].PhoneNum, TempPhoneNum);
            strcpy(classmate[TeamCheck][i].Email, TempEmail);
            strcpy(classmate[TeamCheck][i].CustomContent, TempCustomContent);
            i++;
        }
    //�פJ����
    ChooseMember:
        int selection;
        printf("\n�п�ܭn�d�ߪ��խ�:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d:%s\n", j + 1, classmate[TeamCheck][j].StudentName);
        }
        scanf("%d", &selection);
        if (selection > i)
        {
            printf("\n����:��J���~\n");
            goto ChooseMember;
        }
        printf("\n�m�W : %s\n�q�� : %s\n�H�c : %s\n��L��T : %s\n",
		 classmate[TeamCheck][selection - 1].StudentName, 
		 classmate[TeamCheck][selection - 1].PhoneNum, 
		 classmate[TeamCheck][selection - 1].Email, 
		 classmate[TeamCheck][selection - 1].CustomContent);
    }
}
 
void GroupingFunction()
{
    int selection;
    printf("\n�п�J�N��:");
    printf("\n1:�ЫزէO\n2:�ӽФJ��\n3:�ӽаh��\n4:�d�߲էO����\n5:���}\n");
    scanf("%d", &selection);

    switch (selection)
    {

    case 1:
        CreateTeam(); //�ЫزէO
        GroupingFunction();
        break;

    case 2:
        ApplyForAdd(); //�ӽФJ��
        GroupingFunction();
        break;
    case 3:
        ApplyForLeave(); //�ӽаh��
        GroupingFunction();
        break;
    case 4:
        SearchMember(); //�d�߲էO����
        GroupingFunction();
        break;
    case 5:
        break;
    default:
        printf("����:��J���~\n");
        GroupingFunction();
        break;
    }
}
//���ըt�ε��� 
//---------------------------------------------------------------------------------
//�����t��
/*void ImportRatingSystemData ()
{
if (TeamCheck==0){printf("����:�����էO\n");
	}else if(TeamCheck==4){printf("����:�����խ�\n");
	}else{ 
	  ContactData DataUser;
      ContactData classmate[MAX_Team][MAX_Member];
      FILE *fptr2;
      if (TeamCheck==1){fptr2 = fopen("ContactDetail1.txt", "r");}
      if (TeamCheck==2){fptr2 = fopen("ContactDetail2.txt", "r");}
      if (TeamCheck==3){fptr2 = fopen("ContactDetail3.txt", "r");}
      if (fptr2 == NULL)
      {
        printf("\n�ɮ�Ū������\n");
        exit(0);
      }
      int i = 0;
      //�N��ƶפJ�{����
      char TempStudentName[MAX_Str], TempPhoneNum[MAX_Str], TempEmail[50], TempCustomContent[100];
      while (fscanf(fptr2, "%s\t%s\t%s\t%s", TempStudentName, TempPhoneNum, TempEmail, TempCustomContent) != EOF)
      {
        strcpy(classmate[TeamCheck][i].StudentName, TempStudentName);
        strcpy(classmate[TeamCheck][i].PhoneNum, TempPhoneNum);
        strcpy(classmate[TeamCheck][i].Email, TempEmail);
        strcpy(classmate[TeamCheck][i].CustomContent, TempCustomContent);
        i++;
      }
    //�פJ����
}
*/
ContactData classmate[MAX_Team][MAX_Member];
void RateTeammate()
{
    if (TeamCheck == 0)
    {
        printf("����:�����էO\n");
    }
    else if (TeamCheck == 4)
    {
        printf("����:�����խ�\n");
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
            printf("\n�ɮ�Ū������\n");
            exit(0);
        }
        int i = 0;
        //�N��ƶפJ�{����
        char TempStudentName[MAX_Str], TempPhoneNum[MAX_Str], TempEmail[50], TempCustomContent[100];
        while (fscanf(fptr2, "%s\t%s\t%s\t%s", TempStudentName, TempPhoneNum, TempEmail, TempCustomContent) != EOF)
        {
            strcpy(classmate[TeamCheck][i].StudentName, TempStudentName);
            strcpy(classmate[TeamCheck][i].PhoneNum, TempPhoneNum);
            strcpy(classmate[TeamCheck][i].Email, TempEmail);
            strcpy(classmate[TeamCheck][i].CustomContent, TempCustomContent);
            i++;
        }
    //�פJ����
    ChooseMember:
        int selection;
        printf("\n�п�ܭn�������խ�:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d:%s\n", j + 1, classmate[TeamCheck][j].StudentName);
        }
        scanf("%d", &selection);
        if (selection > i)
        {
            printf("\n����:��J���~\n");
            goto ChooseMember;
        }

        if (classmate[TeamCheck][selection - 1].grade.count < 3)
        {
            printf("\n�}�l����");
            printf("\n�п�J��%s������: [0~100]", &classmate[TeamCheck][selection - 1].StudentName);
            printf("\n��ɯ�O : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.LeadershipP);
            printf("�ѻP�{�� : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.ParticipationP);
            printf("�M�~�޳N : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.SkillP);
            printf("��ѳB�z : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.DocumentP);
            printf("�t����O : ");
            scanf("%d", &classmate[TeamCheck][selection - 1].grade.SpeechP);
            classmate[TeamCheck][selection - 1].grade.count++;
            printf("\n����:��������   (�ק隸�ƳѾl:%2d)", 3 - classmate[TeamCheck][selection - 1].grade.count);
        }
        else
        {
            printf("\n����:�w��Ӧ����ק�W�L2�������A�T��A�i��ק�");
        }
    }
}

void SearchTeammateRating()
{
    if (TeamCheck == 0)
    {
        printf("����:�����էO\n");
    }
    else if (TeamCheck == 4)
    {
        printf("����:�����խ�\n");
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
            printf("\n�ɮ�Ū������\n");
            exit(0);
        }
        int i = 0;
        //�N��ƶפJ�{����
        char TempStudentName[MAX_Str], TempPhoneNum[MAX_Str], TempEmail[50], TempCustomContent[100];
        while (fscanf(fptr2, "%s\t%s\t%s\t%s", TempStudentName, TempPhoneNum, TempEmail, TempCustomContent) != EOF)
        {
            strcpy(classmate[TeamCheck][i].StudentName, TempStudentName);
            strcpy(classmate[TeamCheck][i].PhoneNum, TempPhoneNum);
            strcpy(classmate[TeamCheck][i].Email, TempEmail);
            strcpy(classmate[TeamCheck][i].CustomContent, TempCustomContent);
            i++;
        }
    //�פJ����
    ChooseMember:
        int selection;
        printf("\n�п�ܭn�d�ߪ��խ�:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d:%s\n", j + 1, classmate[TeamCheck][j].StudentName);
        }
        scanf("%d", &selection);
        if (selection > i)
        {
            printf("\n����:��J���~\n");
            goto ChooseMember;
        }

        if (classmate[TeamCheck][selection - 1].grade.count != 0)
        {
        	printf("\n%s������ : ",classmate[TeamCheck][selection - 1].StudentName);
        	printf("\n��ɯ�O : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.LeadershipP;k>0;k=k-5)printf("�h");
            printf("\n�ѻP�{�� : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.ParticipationP;k>0;k=k-5)printf("�h");
            printf("\n�M�~�޳N : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.SkillP;k>0;k=k-5)printf("�h");
            printf("\n��ѳB�z : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.DocumentP;k>0;k=k-5)printf("�h");
            printf("\n�t����O : ");
            for(int k=classmate[TeamCheck][selection - 1].grade.SpeechP;k>0;k=k-5)printf("�h");
            int AvgGrade = 
			(classmate[TeamCheck][selection - 1].grade.LeadershipP+
            classmate[TeamCheck][selection - 1].grade.ParticipationP+
            classmate[TeamCheck][selection - 1].grade.SkillP+
            classmate[TeamCheck][selection - 1].grade.DocumentP+
            classmate[TeamCheck][selection - 1].grade.SpeechP)/5;
            printf("\n��X���� : ");
            for(int k=AvgGrade;k>0;k=k-5)printf("�h");
            printf("\n");
        }
        else
        {
            printf("\n����:�|����Ӧ����i�����");
        }
    }
}

void RatingSystem()
{
    int selection;
    printf("\n�п�J�N��:");
    printf("\n1:��խ�����\n2:�d�߲էO��������\n3:���}\n");
    scanf("%d", &selection);

    switch (selection)
    {

    case 1:
        RateTeammate(); //��խ�����
        RatingSystem();
        break;
    case 2:
        SearchTeammateRating(); //�d�߲էO��������
        RatingSystem();
        break;
    case 3:
        break;
    default:
        printf("����:��J���~\n");
        RatingSystem();
        break;
    } 
}
//�����t�ε���
 //---------------------------------------------------------------------------------
void ChooseFunction()
{ //�\����
    int selection;
    printf("\n�п�J�N��:");
    printf("\n1:�p���覡�]�w\n2:���ըt��\n3:�����t��\n4:���}�{��\n");
    scanf("%d", &selection);

    switch (selection)
    {

    case 1:
        ContactInformation(); //�p���覡�]�w
        break;

    case 2:
        GroupingFunction(); //���ըt��
        break;

    case 3:
        RatingSystem(); //�����t��
        break;

    case 4:
        exit(0); //���}�{��
        break;

    default:
        printf("����:��J���~\n");
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
    /*printf("\n�ϥΪ̬�:%7s", LoginAcc.name);
    printf("\n�v�����Ŭ�:%2d", LoginAcc.permission);
    printf("\n\n�w��ϥγ{�ҤH�����t��!\n\n");*/
    while (1)
    {
        ChooseFunction();
    }
    system("pause");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int day ;
    int month;
    int year;
} date;
typedef struct contact
{
    char lastname[100];
    char firstname[100];
    date birth ;
    char address[100];
    char email [100];
    char Number[100];
} contacts;
int count = 0;
contacts s[256];
FILE *pR;
FILE *pW;
void readStudents(contacts *s)
{

    pR=fopen("inf.txt","r");
    while(!feof(pR))
    {

        fscanf(pR,"%[^,],",s[count].lastname);
        fscanf(pR,"%[^,],",s[count].firstname);
        fscanf(pR,"%d-",&s[count].birth.day);
        fscanf(pR,"%d-",&s[count].birth.month);
        fscanf(pR,"%d,",&s[count].birth.year);
        fscanf(pR,"%[^,],",s[count].address);
        fscanf(pR,"%[^,],",s[count].email);
        fscanf(pR,"%[^\n]\n",s[count].Number);
        count++;
    }
    fclose(pR);
}
void printStudents(contacts *s)
{
    Sort(s);

    int i;
    for(i=0; i<count; i++)
    {
        printf("%d) \n",i+1);
        printf("Name: %s %s\n",s[i].firstname,s[i].lastname);
        printf("birth day: %d/",s[i].birth.day);
        printf("%d/",s[i].birth.month);
        printf("%d\n",s[i].birth.year);
        printf("address: %s\n",s[i].address);
        printf("email: %s\n",s[i].email);
        printf("number: %s\n\n\n",s[i].Number);

    }
}
void AddEntry(contacts *s)
{
    int flag;
    int i=0;
    int j=0;
    int flag2=0;
    int k=0;
    int flag3;
    printf("\nFirst Name: ");
    scanf("%s", (s[count].firstname));
    printf("Last Name: ");
    scanf("%s", (s[count].lastname));
    printf("Birthdate:\nday : ");
    do
    {
        scanf("%d",&s[count].birth.day);
        break;

    }
    while (s[count].birth.day<1||s[count].birth.day>31);
    printf("Month: ");
    do
    {
        scanf("%d",(&s[count].birth.month));
    }
    while (s[count].birth.month<1||s[count].birth.month>12);
    printf("Year: ");
    do
    {
        scanf("%d",(&s[count].birth.year));
    }
    while(s[count].birth.year<1||s[count].birth.year>2018);
    printf("Adress: ");
    scanf("%s,",(s[count].address));
    printf("Email: ");
    do
    {
        flag=0;
        flag3=0;
        scanf("%s",(s[count].email));
        for (i=0; i<strlen(s[count].email); i++)
        {
            if ((s[count].email[i])=='@')
            {
                flag=1;
                break;
            }
        }
        for (k=0; k<strlen(s[count].email); k++)
        {
            if ((s[count].email[k])=='.')
            {
                flag3=1;
                break;
            }
        }
    }
    while (flag!=1||flag3!=1);
    printf("Phone Number (XXX-XXXX-XXXX): ");
    do
    {
        scanf("%s", (s[count].Number));
        for (j=0; j<strlen(s[count].Number); j++)
        {
            if ((s[count].Number[j])=='0'||(s[count].Number[j])=='1'||(s[count].Number[j])=='2'||(s[count].Number[j])=='3'||(s[count].Number[j])=='4'||(s[count].Number[j])=='5'||(s[count].Number[j])=='6'||(s[count].Number[j])=='7'||(s[count].Number[j])=='8'||(s[count].Number[j])=='9')
            {
                flag2=1;
            }
            else
            {
                flag2=0;
                break;
            }
        }
    }
    while(flag2!=1);
    printf("\n\tFriend successfully added to Phonebook\n\n");
    count++;
}
void DeleteEntry (contacts *s)
{
    int flag=0;
    int x = 0;
    int i = 0;
    char deletefirstname[20];
    char deletelastname[20];

    printf("\nFirst name: ");
    scanf("%s", deletefirstname);
    printf("Last name: ");
    scanf("%s", deletelastname);

    for (x=0; x<count; x++)
    {

        if (strcasecmp(deletelastname,s[x].lastname)==0 && strcasecmp(deletefirstname,s[x].firstname)==0)
        {
            for ( i = x; i < count ; i++ )
            {
                s[i]=s[i+1];
            }
            flag=1;
            count--;
            break;
        }
        else
        {
            flag=0;
        }

    }
    if (flag==1)
    {
        printf("Contact deleted successfuly\n\n");
    }
    else
    {
        printf("Contact was not found\n\n");
    }


}
void SearchForNumber (contacts *s)
{
    int x = 0;
    char TempFirstName[20];
    char TempLastName[20];
    int flag=0;
    printf("\nPlease type the name of the friend you wish to find a number for.");
    printf("\n\nFirst Name: ");
    scanf("%s", TempFirstName);
    printf("Last Name: ");
    scanf("%s", TempLastName);
    for (x = 0; x < count; x++)
    {
        if (strcasecmp(TempFirstName, s[x].firstname) == 0)
        {
            if (strcasecmp(TempLastName, s[x].lastname) == 0)
            {
                printf("\n%s %s's phone number is %s\n", s[x].firstname, s[x].lastname, s[x].Number);
                printf("Birthdate: %d-%d-%d\n",s[x].birth.day,s[x].birth.month,s[x].birth.year);
                printf("Email: %s\n",s[x].email);
                printf("Address: %s\n\n",s[x].address);
                flag=1;
            }
        }
    }
    if (flag==0)
    {
        printf("Contact was not found\n\n");
    }
}

void Sort (contacts*s)
{
    int i = 0;
    int x = 0;
    int swap;
    int TempCounter = count;
    contacts Temp;

    do
    {
        swap = 0;
        for(i = 1; i < TempCounter; i++)
        {

            if(strcmp(s[i-1].firstname, s[i].firstname) > 0)
            {
                Temp = s[i];
                s[i] = s[i-1];
                s[i-1] = Temp;
                swap = 1;
            }
            else if (strcmp(s[i-1].firstname,s[i].firstname)==0&&(strcmp(s[i-1].lastname,s[i].lastname)>0))
            {
                Temp = s[i];
                s[i] = s[i-1];
                s[i-1] = Temp;
                swap = 1;
            }
            else if (strcmp(s[i-1].firstname,s[i].firstname)==0&&(strcmp(s[i-1].lastname,s[i].lastname)==0)&&(strcmp(s[i-1].Number,s[i].Number)>0))
            {
                Temp = s[i];
                s[i] = s[i-1];
                s[i-1] = Temp;
                swap = 1;
            }
        }
        TempCounter--;
    }
    while (swap);


}
void save(contacts *s)
{
    int i=0;
    pW = fopen("inf.txt", "w");
    if ( pW == NULL )
    {

        perror(" error occurred ");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i=0; i<count; i++)
        {
            fprintf(pW, "%s,%s,%d-%d-%d,%s,%s,%s\n",s[i].lastname,s[i].firstname,s[i].birth.day,s[i].birth.month,s[i].birth.year,s[i].address,s[i].email,s[i].Number);
        }
        printf("Phonebook is saved successfuly\n\n");
    }
    fclose(pW);
}
void modify (contacts *s)
{
    int select=0;
    int flag=0;
    int x = 0;
    int j=0;
    int i=0;
    int k=0;
    char searchfirstname[20];
    char searchlastname[20];
    int flag3,flag2,flag1;
    printf("\nFirst name: ");
    scanf("%s", searchfirstname);
    printf("Last name: ");
    scanf("%s", searchlastname);
    for (x=0; x<count; x++)
    {

        if (strcasecmp(searchlastname,s[x].lastname)==0 && strcasecmp(searchfirstname,s[x].firstname)==0)
        {
            printf("select field to modify: \n1)Name\n2)Number\n3)birthdate\n4)Address\n5)Email\n");
            scanf("%d",&select);
            switch (select)
            {
            case 1:
            {
                flag=1;
                printf("First Name: ");
                scanf("%s",s[x].firstname);
                printf("Last Name: ");
                scanf("%s",s[x].lastname);
                break;
            }
            case 2:
            {
                flag=1;
                printf("Number: ");
                do
                {
                     flag3=0;

                    scanf("%s", (s[x].Number));
                    for (j=0; j<strlen(s[x].Number); j++)
                    {
                        if ((s[x].Number[j])=='0'||(s[x].Number[j])=='1'||(s[x].Number[j])=='2'||(s[x].Number[j])=='3'||(s[x].Number[j])=='4'||(s[x].Number[j])=='5'||(s[x].Number[j])=='6'||(s[x].Number[j])=='7'||(s[x].Number[j])=='8'||(s[x].Number[j])=='9')
                        {
                            flag3=1;
                        }
                        else
                        {
                            flag3=0;
                            break;
                        }
                    }
                }
                while(flag3!=1);
                break;
            }
            case 3:
            {
                flag=1;
                printf("day: ");
                do
                {
                    scanf("%d",&s[x].birth.day);

                }
                while (s[x].birth.day<1||s[x].birth.day>31);
                printf("Month: ");
                do
                {
                    scanf("%d",(&s[x].birth.month));
                }
                while (s[x].birth.month<1||s[x].birth.month>12);
                printf("Year: ");
                do
                {
                    scanf("%d",(&s[x].birth.year));
                }
                while(s[x].birth.year<1||s[x].birth.year>2018);
                break;
            }
            case 4:
            {
                flag=1;
                printf("Address: ");
                scanf("%s",s[x].address);
                break;
            }
            case 5:
            {
                flag=1;
                printf("Email: ");
                do
                {
                     flag1=0;
                     flag2=0;
                    scanf("%s",(s[x].email));
                    for (i=0; i<strlen(s[x].email); i++)
                    {
                        if ((s[x].email[i])=='@')
                        {
                            flag1=1;
                            break;
                        }
                    }
                    for (k=0; k<strlen(s[x].email); k++)
                    {
                        if ((s[x].email[k])=='.')
                        {
                            flag2=1;
                            break;
                        }
                    }
                }
                while (flag1!=1||flag2!=1);
                break;
            }
            default:
            {
                printf("Error");
                break;
            }
            }
            break;
        }
        else
        {
            flag=0;
        }

    }
    if (flag==1)
    {
        printf("Contact modified successfuly\n\n");
    }
    else
    {
        printf("Contact was not found\n\n");
    }

}
void exitt ()
{
    char x;
    printf("Are you sure?\n(y)\t(N)\n\n");
    scanf("%c",&x);
    if (x=='y')
    {
        exit(0);
    }
}
void sortbybirthdate(contacts *s)
{
    int i = 0;
    int x = 0;
    int swap;
    int TempCounter=count;
    contacts Temp;

    do
    {
        swap = 0;
        for(i=1; i<TempCounter; i++)
        {

            if((s[i-1].birth.year)>(s[i].birth.year))
            {
                Temp = s[i];
                s[i] = s[i-1];
                s[i-1] = Temp;
                swap = 1;
            }
            else if ((s[i-1].birth.year)==(s[i].birth.year)&&(s[i-1].birth.month)>(s[i].birth.month))
            {
                Temp = s[i];
                s[i] = s[i-1];
                s[i-1] = Temp;
                swap=1;
            }
            else if ((s[i-1].birth.year)==(s[i].birth.year)&&(s[i-1].birth.month)==(s[i].birth.month)&&(s[i-1].birth.day)>(s[i].birth.day))
            {
                Temp = s[i];
                s[i] = s[i-1];
                s[i-1] = Temp;
                swap=1;
            }
        }
        TempCounter--;
    }
    while (swap);
    i=0;
    for(i=0; i<count; i++)
    {
        printf("%d) \n",i+1);
        printf("Name: %s %s\n",s[i].firstname,s[i].lastname);
        printf("birth day: %d/",s[i].birth.day);
        printf("%d/",s[i].birth.month);
        printf("%d\n",s[i].birth.year);
        printf("address: %s\n",s[i].address);
        printf("email: %s\n",s[i].email);
        printf("number: %s\n\n\n",s[i].Number);

    }

}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"
   int main()
{
    readStudents(s);
    int x;
    do
    {
        printf("1) Search for a contact\n2) Add new contact\n3) Display all contacts\n4) Delete contact\n5) Modify contact\n6) Sort by birthdates\n7) SAVE\n8) EXIT\n\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
        {
            SearchForNumber(s);
            break;
        }
        case 2:
        {
            AddEntry(s);
            break;
        }
        case 3:
        {
            printStudents(s);
            break;
        }
        case 4:
        {
            DeleteEntry(s);
            break;
        }

        case 5:
        {
            modify(s);
            break;
        }
        case 6:
        {
            sortbybirthdate(s);
            break;
        }
        case 7:
        {
            save(s);
            break;
        }

        case 8:
        {
            exitt();
            break;
        }
        default :
        {
            printf("Error");
            break;
        }
        }
    }
    while (x<=8);
}

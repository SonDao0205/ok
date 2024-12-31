#include "include/studentsManagement.h"
#include "include/datatype.h"
#include "include/adminAccounts.h"
#include "include/secondaryFeatures.h"
#include "include/teacherManagement.h"
#include "src/studentsManagement.c"
#include "src/secondaryFeatures.c"
#include "src/adminAccounts.c"
#include "src/teacherManagement.c"

int main()
{
    Account accounts[100];
    FILE *file;
    int accountSize = 0;
    int choice;
    loadAccounts(accounts, &accountSize);
    Student students[100];
    int size = 0;
    do
    {
        printf("\n======== CHOOSE YOUR ROLE ========\n");
        printf("           [1]. Admin.\n");
        printf("           [2]. Student.\n");
        printf("           [3]. Teacher.\n");
        printf("           [4]. Exit\n");
        printf("==================================\n");
        printf("          Enter The Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if (accountSize == 0)
            {
                printf("\n======== SIGN UP ========\n");
                registerAccount(accounts, &accountSize);
                accountSize = 1;
                saveAccounts(accounts, accountSize);
            }
            int loginSuccess = 0;
            do
            {
                printf("\n======== MENU ========\n");
                printf("    [1]. Log In\n");
                printf("    [2]. Exit\n");
                printf("========================\n");
                printf("   Enter The Choice : ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    getchar();
                    if (login(accounts, accountSize))
                    {
                        loginSuccess = 1;
                        printf("Log in successful!\n");
                    }
                    else
                    {
                        printf("Wrong username or password!\n");
                    }
                    break;
                case 2:
                    goodBye();
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
                }
            } while (loginSuccess == 0 && choice != 3);
            if (loginSuccess)
            {
                do
                {
                    printf("\n============= MENU =============\n");
                    printf("      [1]. Student Management\n");
                    printf("      [2]. Teacher Management\n");
                    printf("      [3]. Exit\n");
                    printf("==================================\n");
                    printf("       Enter The Choice : ");
                    scanf("%d",&choice);
                    switch (choice)
                    {
                    case 1:
                        loadStudents(students, &size, file);
                        do
                        {
                            printf("\n========== Student Management ==========\n");
                            printf("       [1]. Show All Students.\n");
                            printf("       [2]. Add A New Students.\n");
                            printf("       [3]. Edit A Students.\n");
                            printf("       [4]. Delete A Students.\n");
                            printf("       [5]. Search A Students.\n");
                            printf("       [6]. Sort Students.\n");
                            printf("       [7]. Exit.\n");
                            printf("=========================================\n");
                            printf("       Enter The Choice : ");
                            scanf("%d", &choice);
                            switch (choice)
                            {
                            case 1:
                                displayStudents(students, size);
                                break;
                            case 2:
                                printf("===== Add A New Students =====\n");
                                addStudent(students, &size, file);
                                break;
                            case 3:
                                printf("===== Edit A Students =====\n");
                                editStudent(students, size, file);
                                break;
                            case 4:
                                printf("===== Delete A Students =====\n");
                                deleteStudent(students, &size, file);
                                break;
                            case 5:
                                printf("===== Search A Students =====\n");
                                searchStudent(students, size);
                                break;
                            case 6:
                                printf("===== Sort Students =====\n");
                                sortStudents(students, size);
                                saveStudents(students, size, file);
                                break;
                            case 7:
                                goodBye();
                                break;
                            default:
                                printf("Invalid choice!\n");
                            }
                    } while (choice != 7);
                        break;
                    case 2:
                        do
                        {
                            printf("\n========== Student Management ==========\n");
                            printf("       [1]. Show All Students.\n");
                            printf("       [2]. Add A New Students.\n");
                            printf("       [3]. Edit A Students.\n");
                            printf("       [4]. Delete A Students.\n");
                            printf("       [5]. Search A Students.\n");
                            printf("       [6]. Exit.\n");
                            printf("=========================================\n");
                            printf("       Enter The Choice : ");
                            scanf("%d", &choice);
                        } while (choice != 6);
                        
                        break;
                    case 3:
                        goodBye();
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                    }
                } while (choice != 3);
            }
                    break;
        case 2:
            loadStudents(students, &size, file);
            do
            {
                printf("============== Menu ==============\n");
                printf("      [1]. Show All Students.\n");
                printf("      [2]. Exit.\n");
                printf("==================================\n");
                printf("      Enter The Choice : ");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    displayStudents(students, size);
                    break;
                case 2:
                    goodBye();
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
                }
            } while (choice !=2);
            break;
        case 3:
            loadStudents(students, &size, file);
            do
            {
                printf("\n========== Student Management ==========\n");
                printf("       [1]. Show All Students.\n");
                printf("       [2]. Add A New Students.\n");
                printf("       [3]. Edit A Students.\n");
                printf("       [4]. Delete A Students.\n");
                printf("       [5]. Search A Students.\n");
                printf("       [6]. Sort Students.\n");
                printf("       [7]. Exit.\n");
                printf("=========================================\n");
                printf("       Enter The Choice : ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    displayStudents(students, size);
                    break;
                case 2:
                    printf("===== Add A New Students =====\n");
                    addStudent(students, &size, file);
                    break;
                case 3:
                    printf("===== Edit A Students =====\n");
                    editStudent(students, size, file);
                    break;
                case 4:
                    printf("===== Delete A Students =====\n");
                    deleteStudent(students, &size, file);
                    break;
                case 5:
                    printf("===== Search A Students =====\n");
                    searchStudent(students, size);
                    break;
                case 6:
                    printf("===== Sort Students =====\n");
                    sortStudents(students, size);
                    saveStudents(students, size, file);
                    break;
                case 7:
                    goodBye();
                    break;
                default:
                    printf("Invalid choice!\n");
                }
        } while (choice != 7);
            break;
        case 4:
            goodBye();
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 4);
}
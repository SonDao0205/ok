#include "../include/classroomManagement.h"

void loadClassroom(Classroom classrooms[], int *size, FILE *file)
{
    file = fopen("data/classroom.bin", "rb");
    if (file == NULL)
    {
        *size = 0;
        return;
    }
    fread(size, sizeof(int), 1, file);
    fread(classrooms, sizeof(Classroom), *size, file);
    fclose(file);
}

void saveClassroom(Classroom classrooms[], int size, FILE *file)
{
    file = fopen("data/classroom.bin", "wb");
    if (file == NULL)
    {
        printf("Cannot open file to write!\n");
        return;
    }
    fwrite(&size, sizeof(int), 1, file);
    fwrite(classrooms, sizeof(Classroom), size, file);
    fclose(file);
}

// void displayClassroom(Classroom classrooms[],Teacher teachers[], int size)
// {
//     if (size == 0)
//     {
//         printf("Empty Student list!\n");
//         return;
//     }
//     printf("======== Classroom Management =======\n\n");
//     printf("|===========|=====================|===================================|=================|\n");
//     printf("|    ID     |        Name         |            Teacher                |    Phone        |\n");
//     printf("|===========|=====================|===================================|=================|\n");
//     for (int i = 0; i < size; i++)
//     {
//         printf("|%-11s|%-21s|%-35s|%-17s|\n",classrooms[i].id, classrooms[i].name, teachers[i].name, teachers[i].phone);
//         printf("|-----------|---------------------|-----------------------------------|-----------------|\n");
//     }
//     backMenu();
// }

void addClassroom(Classroom classrooms[], int *size, FILE *file)
{
    if (*size >= 100)
    {
        printf("The classroom list is full!\n");
        return;
    }
    Classroom newClassroom;
    while (1)
    {
        printf("Enter ID: ");
        getchar();
        fgets(newClassroom.id,sizeof(newClassroom.id),stdin);
        newClassroom.id[strcspn(newClassroom.id, "\n")] = '\0';
        int flag = 0;
        for (int i = 0; i < *size; i++)
        {
            if (strcmp(newClassroom.id,classrooms[i].id)==0)
            {
                flag = 1;
                printf("Error : ID already exists!\n");
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    strcpy(classrooms[*size].id,newClassroom.id);
    printf("Enter name: ");
    fgets(newClassroom.name, sizeof(newClassroom.name), stdin);
    newClassroom.name[strcspn(newClassroom.name, "\n")] = '\0';
    strcpy(classrooms[*size].name,newClassroom.name);
    (*size)++;
    saveClassroom(classrooms, *size, file);
    printf("Add classroom success!\n");
    backMenu();
}

void editClassroom(Classroom classrooms[], int size, FILE *file)
{
    Classroom updateClassroom;
    char searchID[100];
    printf("Enter ID: ");
    getchar();
    fgets(searchID,100,stdin);
    searchID[strcspn(searchID, "\n")] = '\0';
    for (int i = 0; i < strlen(searchID); i++)
    {
        searchID[i] = toupper(searchID[i]);
    }
    for (int i = 0; i < size; i++)
    {
        char temp[100];
        strcpy(temp,classrooms[i].id);
        for (int i = 0; i < strlen(temp); i++)
        {
            temp[i] = toupper(temp[i]);
        }
        if (strcmp(temp,searchID)==0)
        {
            printf("===== Edit A Classroom =====\n");
            printf("Enter new name: ");
            fgets(classrooms[i].name, sizeof(classrooms[i].name), stdin);
            classrooms[i].name[strcspn(classrooms[i].name, "\n")] = '\0';
            saveClassroom(classrooms, size, file);
            printf("Edit classroom success!\n");
            backMenu();
            return;
        }
    }
    printf("No classroom found!\n");
    backMenu();
}

void deleteClassroom(Classroom classrooms[], int *size, FILE *file)
{
    char searchID[100];
    printf("Enter ID: ");
    getchar();
    fgets(searchID,100,stdin);
    searchID[strcspn(searchID, "\n")] = '\0';
    for (int i = 0; i < strlen(searchID); i++)
    {
        searchID[i] = toupper(searchID[i]);
    }
    for (int i = 0; i < *size; i++)
    {
        char temp[100];
        strcpy(temp,classrooms[i].id);
        for (int i = 0; i < strlen(temp); i++)
        {
            temp[i] = toupper(temp[i]);
        }
        if (strcmp(temp,searchID)==0)
        {
            char x;
            printf("===== Delete A Classroom =====\n");
            printf("Are you sure want to delete this classroom?(Y/N) : ");
            scanf("%c",&x);
            x = toupper(x);
            switch (x)
            {
            case 'Y':
                for (int j = i; j < *size - 1; j++)
                {
                    classrooms[j] = classrooms[j + 1];
                }
                (*size)--;
                saveClassroom(classrooms, *size, file);
                printf("Classroom delete success!\n");
                backMenu();
                break;
            case 'N':
                printf("Classroom delete failed !\n");
                backMenu();
                break;
            default:
                printf("Invalid choice!\n");
                backMenu();
                break;
            }
        }
    }
    printf("No classroom found!\n");
}

void classroomDetail(Classroom classrooms[], int size)
{
    char searchID[100];
    int flag = 0;
    printf("Enter ID: ");
    getchar();
    fgets(searchID,100,stdin);
    searchID[strcspn(searchID, "\n")] = '\0';
    for (int i = 0; i < strlen(searchID); i++)
    {
        searchID[i] = toupper(searchID[i]);
    }
    for (int i = 0; i < size; i++)
    {
        char temp[100];
        strcpy(temp,classrooms[i].id);
        for (int i = 0; i < strlen(temp); i++)
        {
            temp[i] = toupper(temp[i]);
        }
        if (strcmp(temp,searchID) == 0)
        {
            flag = 1;
            int choice;
            printf("\nClassroom Information : \n");
            printf("ID : %s\n",classrooms[i].id);
            printf("Name : %s\n",classrooms[i].name);
            printf("===== Menu =====\n");
            printf("[1]. Add A Student.\n");
            printf("[2]. Delete A Student.\n");
            printf("[3]. Exit.\n");
            printf("Enter the choice : ");
            switch (choice)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("No classroom found!\n");
    }
    backMenu();
}
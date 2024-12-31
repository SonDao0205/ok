#pragma once
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct
{
    char id[100];
    char name[100];
    int age;
    char email[200];
    char phone[15];
    char password[100];

} Student;

typedef struct
{
    char username[100];
    char password[100];
}Account;
typedef struct{
    char id[100];
    char name[100];
    int age;
    char email[200];
    char phone[15];
    char password[100];
}Teacher;
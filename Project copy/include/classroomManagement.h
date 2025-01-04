#include"datatype.h"
#include "secondaryFeatures.h"

void loadClassroom(Classroom classrooms[], int *size, FILE *file);
void saveClassroom(Classroom classrooms[], int size, FILE *file);
void displayClassroom(Classroom classrooms[], int size);
void displayInformationClassroom(Classroom classrooms[],int size,char searchID[100]);
void addClassroom(Classroom classrooms[], int *size, FILE *file);
void editClassroom(Classroom classrooms[], int size, FILE *file);
void deleteClassroom(Classroom classrooms[], int *size, FILE *file);
void classroomDetail(Classroom classrooms[], int size);
void sortClassroom(Classroom classrooms[], int size);
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX 50

struct Course
{
    int id;
    char name[50];
};

struct Student
{
    int id;
    char name[50];
};

struct Enrollment
{
    int student_id;
    int course_id;
};


struct Course courses[MAX];
struct Student students[MAX];
struct Enrollment enrolls[MAX];

int courseCount = 0;
int studentCount = 0;
int enrollCount = 0;


void Welcome_Message();
void Head_Message(char title[]);
void Menu();

int isCourseExists(int id);
int isStudentExists(int id);

void Add_Course();
void Add_Student();
void Enroll_Student();
void Display_All_Courses();
void Display_All_Students();
void Display_All_Enrollments();
void Exit_Program();


int main()
{
    int choice;

    Welcome_Message();

    while (1)
    {
        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            Add_Course();
        else if (choice == 2)
            Display_All_Courses();
        else if (choice == 3)
            Add_Student();
        else if (choice == 4)
            Display_All_Students();
        else if (choice == 5)
            Enroll_Student();
        else if (choice == 6)
            Display_All_Enrollments();
        else if (choice == 0)
        {
            Exit_Program();
            break;
        }
        else
            printf("\nInvalid Choice! Try again.\n");

    }
    return 0;
}



void Welcome_Message()
{
    printf("\n");
    printf("============================================================\n");
    printf("||                                                        ||\n");
    printf("||        E-LEARNING COURSE MANAGEMENT SYSTEM             ||\n");
    printf("||                                                        ||\n");
    printf("============================================================\n");
    printf("||                                                        ||\n");
    printf("||  Welcome to the E-Learning Management System project!  ||\n");
    printf("||                                                        ||\n");
    printf("||  -> Developed by: Department of CSE                    ||\n");
    printf("||  -> Semester   : Fall 2025                             ||\n");
    printf("||                                                        ||\n");
    printf("||  This system allows you to:                            ||\n");
    printf("||   - Add and manage courses                             ||\n");
    printf("||   - Add and manage students                            ||\n");
    printf("||   - Enroll students into courses                       ||\n");
    printf("||   - View enrollment information                        ||\n");
    printf("||                                                        ||\n");
    printf("============================================================\n");
    printf("\n        Press any key to start the system...");
    getch();
}


void Head_Message(char title[])
{
    printf("\n\n------------------------------------\n");
    printf("            %s\n", title);
    printf("------------------------------------\n");
}

void Menu()
{
    Head_Message("Main Menu");
    printf("1. Add Course\n");
    printf("2. List Courses\n");
    printf("3. Add Student\n");
    printf("4. List Students\n");
    printf("5. Enroll Student\n");
    printf("6. View Enrollments\n");
    printf("0. Exit\n");
}


int isCourseExists(int id)
{
    for (int i = 0; i < courseCount; i++)
        if (courses[i].id == id)
            return i;

    return -1;
}

int isStudentExists(int id)
{
    for (int i = 0; i < studentCount; i++)
        if (students[i].id == id)
            return i;

    return -1;
}


void Add_Course()
{
    Head_Message("Add Course");
    printf("Enter Course ID: ");
    scanf("%d", &courses[courseCount].id);

    getchar();
    printf("Enter Course Name: ");
    fgets(courses[courseCount].name, 50, stdin);
    courses[courseCount].name[strcspn(courses[courseCount].name, "\n")] = 0;

    courseCount++;
    printf("Course Added Successfully!\n");
}

void Display_All_Courses()
{
    Head_Message("Course List");

    for (int i = 0; i < courseCount; i++)
        printf("ID: %d | Name: %s\n", courses[i].id, courses[i].name);
}

void Add_Student()
{
    Head_Message("Add Student");
    printf("Enter Student ID: ");
    scanf("%d", &students[studentCount].id);

    getchar();
    printf("Enter Student Name: ");
    fgets(students[studentCount].name, 50, stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0;

    studentCount++;
    printf("Student Added Successfully!\n");
}

void Display_All_Students()
{
    Head_Message("Student List");

    for (int i = 0; i < studentCount; i++)
        printf("ID: %d | Name: %s\n", students[i].id, students[i].name);
}

void Enroll_Student()
{
    int sid, cid;

    Head_Message("Enroll Student");

    printf("Enter Student ID: ");
    scanf("%d", &sid);
    printf("Enter Course ID: ");
    scanf("%d", &cid);

    if (isStudentExists(sid) == -1 || isCourseExists(cid) == -1)
    {
        printf("Student or Course Not Found!\n");
        return;
    }

    enrolls[enrollCount].student_id = sid;
    enrolls[enrollCount].course_id = cid;
    enrollCount++;

    printf("Enrollment Successful!\n");
}

void Display_All_Enrollments()
{
    Head_Message("Enrollment List");

    for (int i = 0; i < enrollCount; i++)
        printf("Student ID: %d  -->  Course ID: %d\n",
               enrolls[i].student_id, enrolls[i].course_id);
}

void Exit_Program()
{
    Head_Message("Exit");
    printf("\n===============================================\n");
    printf("    Thank you for using E-Learning System!\n");
    printf("===============================================\n");
}


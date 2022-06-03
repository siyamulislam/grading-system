#include<stdio.h>
#include<string.h>

struct student_grade
{
    char id[15];
    char name[50];
}   stu[10];
struct student_record
{
    char id[15];
    char name[50];
} stud[50];

struct student_search
{
    char id[15];
    char name[50];
    char grade[4];
} record[20];

struct student_information
{
    char id[15];
    char name[50];
    char grade[5];
} file[20];

int main()
{
    printf("\n\n\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n \n");
    printf("\t\t\t    ***GRADING_SYSTEM***\n \n");
    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n \n");
    printf("\t\t\t       MAIN SCREEN\n\n\n\n\n\n");

    printf("Enter your choice:\n\n");

    printf("1.Calculate Grade\n");
    printf("2.Create a new record\n");
    printf("3.Search individual student information\n");
    printf("4.View all students information\n");
    printf("5.Exit program\n\n");

    int key;
    scanf("%d", &key);
    switch(key)
    {
    case 1:
    {
        int i, n;
        float average[10];
        FILE *fptr;
        fptr =fopen("Student_Grade.txt", "w");

        printf("Enter a number of how many student result you calculate: \n");
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            printf("\nEnter ID for student no %d : \n", i+1);
            scanf("%s",stu[i].id);
            printf("Enter Name for student no %d : \n", i+1);
            scanf("%s", stu[i].name);
            printf("Enter Average  marks for Student no %d : \n",i+1);
            scanf("%f", &average[i]);
        }

        for (i=0;  i<n; i++)
        {
            printf("\n%d.\n\tStudent ID\t: %s\n", i+1, stu[i].id);
            printf("\tStudent name\t: %s\n",stu[i].name);
            printf("\tDepartment of\t: CSE\n\tSection \t: 'O'\n\tAverage marks\t: %.2f\n",average[i]);
            fprintf(fptr,"\n%d.\n\tStudent ID\t: %s\n", i+1, stu[i].id);
            fprintf(fptr,"\tStudent name\t: %s\n",stu[i].name);
            fprintf(fptr,"\tDepartment of\t: CSE\n\tSection \t: 'O'\n\tAverage marks\t: %.2f\n",average[i]);


            if(average[i]>= 80)
            {
                printf("\tGrade\t\t: A+ \n");
                fprintf(fptr,"\tGrade\t\t: A+ \n");
            }
            else if((average[i]>=70) && (average[i]<80))
            {
                printf("\tGrade\t\t: A \n");
                fprintf(fptr,"\tGrade\t\t: A \n");
            }
            else if((average[i]>=60)&&(average[i]<70))
            {
                printf("\tGrade\t\t: A- \n");
                fprintf(fptr,"\tGrade\t\t: A- \n");
            }
            else if((average[i]>=50)&&(average[i]<60))
            {
                printf("\tGrade\t\t: B+ \n");
                fprintf(fptr,"\tGrade\t\t: B+ \n");
            }
            else if((average[i]>=40)&&(average[i]<50))
            {
                printf("\tGrade\t\t: B \n");
                fprintf(fptr,"\tGrade\t\t: B \n");
            }

            else if(average[i]<40)
            {
                printf("\tGrade\t\t: Fail \n");
                fprintf(fptr,"\tGrade\t\t: Fail \n");
            }
        }
        printf("\n");
        fclose(fptr);
    }
    break;

    case 2:
    {
        int i,n;
        FILE *fptr;
        fptr =fopen("Student_Record.txt", "w");

        printf("\nEnter a digit of your desire students\n");
        scanf("%d",&n);
        for (i=0; i<=n-1; i++)
        {
            printf("\nEnter %d Student ID:\n",i+1);
            scanf("%s", &stud[i].id);
            printf("Enter %d Student Name:\n", i+1);
            scanf("%s", stud[i].name);
        }
        for (i=0; i<n; i++)
        {
            printf("\n\n%d. \tStudent ID   : %s.\n",i+1,stud[i].id);
            printf("\tStudent Name : %s.\n",stud[i].name);
            printf("\tDept    : CSE\n");
            printf("\tSection : 'O'\n\n");
            fprintf(fptr,"\n\n%d. \tStudent ID   : %s.\n",i+1,stud[i].id);
            fprintf(fptr,"\tStudent Name : %s.\n",stud[i].name);
            fprintf(fptr,"\tDept    : CSE\n");
            fprintf(fptr,"\tSection : 'O'\n\n");
        }
        fclose(fptr);
    }
    break;

    case 3:
    {
        int i,value;
        char searchkey[50];
        FILE *fptr;
        fptr =fopen("Student_Search_Result.txt", "w");

        strcpy(record[0].id,"171-15-8865");
        strcpy(record[0].name,"siyamul");
        strcpy(record[0].grade,"A-");
        strcpy(record[1].id,"171-15-8841");
        strcpy(record[1].name,"kamrul");
        strcpy(record[1].grade,"A");
        strcpy(record[2].id,"171-15-9219");
        strcpy(record[2].name,"imrul");
        strcpy(record[2].grade,"A");
        strcpy(record[3].id,"171-15-8926");
        strcpy(record[3].name,"eusuf");
        strcpy(record[3].grade,"A-");
        strcpy(record[4].id,"171-15-8622");
        strcpy(record[4].name,"sunny");
        strcpy(record[4].grade,"A-");

        while(1)
        {
            printf("Enter a name for searching:\n");
            scanf("%s",&searchkey);

            for(i=0; i<5; i++)
            {
                value = strcmp(searchkey, record[i].name);
                if(value==0)
                {
                    printf("\n** Search Result **\n\n");
                    printf("\tName\t: %s\t\n",record[i].name);
                    printf("\tID\t: %s\t\n",record[i].id);
                    printf("\tDept\t: CSE\n");
                    printf("\tSection\t: 'O'\n");
                    printf("\tGrade\t: %s\n\n\n",record[i].grade);
                    fprintf(fptr,"\n**Search result**\n\n");
                    fprintf(fptr,"\tName\t: %s\t\n",record[i].name);
                    fprintf(fptr,"\tID\t: %s\t\n",record[i].id);
                    fprintf(fptr,"\tDept\t: CSE\n");
                    fprintf(fptr,"\tSection\t: 'O'\n");
                    fprintf(fptr,"\tGrade\t: %s\n\n\n",record[i].grade);
                }
            }
            fclose(fptr);
        }
    }
    break;

    case 4:
    {
        int i;
        FILE *fptr;
        fptr =fopen("Student_Information.txt", "w");

        strcpy(file[0].id,"171-15-8865");
        strcpy(file[0].name,"Siyamul_Islam");
        strcpy(file[0].grade,"A-");
        strcpy(file[1].id,"171-15-9219");
        strcpy(file[1].name,"Imrul_Hassan");
        strcpy(file[1].grade,"A");
        strcpy(file[2].id,"171-15-8841");
        strcpy(file[2].name,"Kamrul_Islam");
        strcpy(file[2].grade,"A");
        strcpy(file[3].id,"171-15-8926");
        strcpy(file[3].name,"Eusuf_Uddin");
        strcpy(file[3].grade,"A-");
        strcpy(file[4].id,"171-15-8622");
        strcpy(file[4].name,"Shubel_Islam");
        strcpy(file[4].grade,"A-");

        for(i=0; i<5; i++)
        {
            printf("\n%d.\tName\t: %s\t\n",i+1,file[i].name);
            printf("\tID\t: %s\t\n",file[i].id);
            printf("\tDept\t: CSE\n");
            printf("\tSection\t: 'O'\n");
            printf("\tGrade\t: %s\n\n\n",file[i].grade);
            fprintf(fptr,"%d.\tName\t: %s\t\n\tID\t: %s\t\n\tDept\t: CSE\n\tSection\t: 'O'\n\tGrade\t: %s\n\n\n",i+1,file[i].name,file[i].id,file[i].grade);
        }
        fclose(fptr);
    }
    break;

    case 5:
    {
        printf("\nThank you!\nProgram closing....\n");
        return 0;
    }
    break;

    default:
    {
        printf("\nWrong Choice!!!\n \n ");
    }
    break;

    }

    printf("\nThank you!...\n");
    return 0;
}


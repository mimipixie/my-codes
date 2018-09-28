#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int id;
    char name[40];
    int courses;
    char course_id[4][10];
    double credit_hours[4];
    double marks[4];
    double grade_point[4];
    char letter_grade[4][5];
    double GPA;

    };

double calculate_grade_point(double);
char * calculate_letter_grade(double);
double GPA(struct student * );
void sort(struct student * , int  );


int main()
{   int c,i,j,m,n,s_id,a;
    struct student s[100] , *p=s;
    char  *r , r_gpa[5] , r_gpa1[5] ;
    double b;

    printf("---------------------------------------------------------\n");
    printf("Press 1 to add a new student\n");
    printf("Press 2 to display information of a particular student\n");
    printf("Press 3 to display information of students based on GPA\n");
    printf("Press 4 to display information of all student\n");
    printf("Press 5 to exit\n");
    printf("---------------------------------------------------------\n");

    i=0;

    for(;;)
    {
        printf("\n---------------------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        fflush(stdin);
        printf("\n---------------------------------------------------------\n");
        switch(c)
        {  case 1:

            printf("\n\nEnter student id: ");
            scanf("%d",&s[i].id);
            fflush(stdin);
            printf("Enter student name: ");
            scanf("%[^\n]s",s[i].name);
            fflush(stdin);
            printf("Enter courses taken: ");
            scanf("%d",&s[i].courses);
            fflush(stdin);

            for(j=0;j<s[i].courses;j++)
           {
            printf("Enter course(%d) id: ",j+1);
            scanf("%[^\n]s",s[i].course_id[j]);
            fflush(stdin);
            printf("Enter credit hours: ");
            scanf("%lf",&s[i].credit_hours[j]);
            fflush(stdin);
            printf("Enter marks: ");
            scanf("%lf",&s[i].marks[j]);
            fflush(stdin);

            s[i].grade_point[j]=calculate_grade_point(s[i].marks[j]);
            printf("Grade point : %.2lf\n",s[i].grade_point[j]);

            r=calculate_letter_grade(s[i].marks[j]);
            strcpy(s[i].letter_grade[j],r);
            printf("Letter grade :  %s \n",s[i].letter_grade[j]);

           }

            s[i].GPA=GPA(&s[i]);

            printf("\nGPA = %.2lf\n",s[i].GPA);

            i++;


            break;

           case 2:

            printf("\n\nEnter a particular student id : ");
            scanf("%d",&s_id);
            fflush(stdin);

            for(m=0;;m++)
          { if(s[m].id==s_id)

           {printf("\n-------------------------------------------- \n");
            printf("\nInformation of student id %d\n",s[m].id);
            printf("\n-------------------------------------------- \n");
            printf("Student name: %s\n",s[m].name);
            printf("Courses taken: %d\n",s[m].courses);
            for(j=0;j<s[m].courses;j++)
            {
            printf("Course(%d) id: %s\n",j+1,s[m].course_id[j]);
            printf("Credit hours: %.2lf\n",s[m].credit_hours[j]);
            printf("Marks: %.2lf\n",s[m].marks[j]);
            printf("Grade point : %.2lf\n",s[m].grade_point[j]);
            printf("Letter grade : %s\n",s[m].letter_grade[j]);
            }
            printf("\nGPA = %.2lf\n",s[m].GPA);
            break;
           }
          }

            break;

           case 3:

            printf("Enter a string : ");
            scanf("%s",r_gpa);

            for(a=0;r_gpa[a+1]!='\0';a++)
            r_gpa1[a] = r_gpa[a+1] ;

            r_gpa1[a] = '\0' ;

            sort(p,i);

            if(r_gpa[0] == '>')
        {

            for(m=0;m<i;m++)
           {
            if(s[m].GPA > atof(r_gpa1))

           {printf("\n-------------------------------------------- \n");
            printf("\nInformation of student id %d   \n",s[m].id);
            printf("\n-------------------------------------------- \n");
            printf("Student name: %s\n",s[m].name);
            printf("Courses taken: %d\n",s[m].courses);
            for(j=0;j<s[m].courses;j++)
            {
            printf("Course(%d) id: %s\n",j+1,s[m].course_id[j]);
            printf("Credit hours: %.2lf\n",s[m].credit_hours[j]);
            printf("Marks: %.2lf\n",s[m].marks[j]);
            printf("Grade point : %.2lf\n",s[m].grade_point[j]);
            printf("Letter grade : %s\n",s[m].letter_grade[j]);
            }
            printf("\nGPA = %.2lf\n",s[m].GPA);
           }
           }


        }

            else if(r_gpa[0] == '<')
        {

            for(m=0;m<i;m++)
           {
            if(s[m].GPA < atof(r_gpa1))

           {printf("\n-------------------------------------------- \n");
            printf("\nInformation of student id %d   \n",s[m].id);
            printf("\n-------------------------------------------- \n");
            printf("Student name: %s\n",s[m].name);
            printf("Courses taken: %d\n",s[m].courses);
            for(j=0;j<s[m].courses;j++)
            {
            printf("Course(%d) id: %s\n",j+1,s[m].course_id[j]);
            printf("Credit hours: %.2lf\n",s[m].credit_hours[j]);
            printf("Marks: %.2lf\n",s[m].marks[j]);
            printf("Grade point : %.2lf\n",s[m].grade_point[j]);
            printf("Letter grade : %s\n",s[m].letter_grade[j]);
            }
            printf("\nGPA = %.2lf\n",s[m].GPA);
           }
           }


        }

            else
        {

            for(m=0;m<i;m++)
           {
            if(s[m].GPA == atof(r_gpa1))

           {printf("\n-------------------------------------------- \n");
            printf("\nInformation of student id %d   \n",s[m].id);
            printf("\n-------------------------------------------- \n");
            printf("Student name: %s\n",s[m].name);
            printf("Courses taken: %d\n",s[m].courses);
            for(j=0;j<s[m].courses;j++)
            {
            printf("Course(%d) id: %s\n",j+1,s[m].course_id[j]);
            printf("Credit hours: %.2lf\n",s[m].credit_hours[j]);
            printf("Marks: %.2lf\n",s[m].marks[j]);
            printf("Grade point : %.2lf\n",s[m].grade_point[j]);
            printf("Letter grade : %s\n",s[m].letter_grade[j]);
            }
            printf("\nGPA = %.2lf\n",s[m].GPA);
           }
           }


        }


            break;

           case 4:

            sort(p,i);

            for(m=0;m<i;m++)
           {
            printf("\n-------------------------------------------- \n");
            printf("\nInformation of student id %d   \n",s[m].id);
            printf("\n-------------------------------------------- \n");
            printf("Student name: %s\n",s[m].name);
            printf("Courses taken: %d\n",s[m].courses);
            for(j=0;j<s[m].courses;j++)
            {
            printf("Course(%d) id: %s\n",j+1,s[m].course_id[j]);
            printf("Credit hours: %.2lf\n",s[m].credit_hours[j]);
            printf("Marks: %.2lf\n",s[m].marks[j]);
            printf("Grade point : %.2lf\n",s[m].grade_point[j]);
            printf("Letter grade : %s\n",s[m].letter_grade[j]);
            }
            printf("\nGPA = %.2lf\n",s[m].GPA);
           }

            break;

           case 5: exit(0);

           default: printf("\nNothing to display this time\n\n");
        }
    }





    return 0;

}

double calculate_grade_point(double m){

    double r;

    if(m>=97 && m<=100)
    r=4.0;
    else if(m>=90 && m<=96)
    r=4.0;
    else if(m>=87 && m<=89)
    r=3.7;
    else if(m>=83 && m<=86)
    r=3.3;
    else if(m>=80 && m<=82)
    r=3.0;
    else if(m>=77 && m<=79)
    r=2.7;
    else if(m>=73 && m<=76)
    r=2.3;
    else if(m>=70 && m<=72)
    r=2.0;
    else if(m>=67 && m<=69)
    r=1.7;
    else if(m>=63 && m<=66)
    r=1.3;
    else if(m>=60 && m<=62)
    r=1.0;
    else
    r=0.0;

    return r;
}


char * calculate_letter_grade(double m){
    static char r[5] ;

    if(m>=97 && m<=100)
    strcpy(r,"A+");
    else if(m>=90 && m<=96)
    strcpy(r,"A");
    else if(m>=87 && m<=89)
    strcpy(r,"A-");
    else if(m>=83 && m<=86)
    strcpy(r,"B+");
    else if(m>=80 && m<=82)
    strcpy(r,"B");
    else if(m>=77 && m<=79)
    strcpy(r,"B-");
    else if(m>=73 && m<=76)
    strcpy(r,"C+");
    else if(m>=70 && m<=72)
    strcpy(r,"C");
    else if(m>=67 && m<=69)
    strcpy(r,"C-");
    else if(m>=63 && m<=66)
    strcpy(r,"D+");
    else if(m>=60 && m<=62)
    strcpy(r,"D");
    else
    strcpy(r,"F");

    return r;
}

double GPA(struct student * s){

    double tch=0,s_ch_gp=0,ch_gp;
    double GPA;
    int j;

    for(j=0;j<s->courses;j++)
    {
        tch+=s->credit_hours[j];
        ch_gp=(s->credit_hours[j]) * (s->grade_point[j]) ;
        s_ch_gp+=ch_gp;

    }

    GPA=s_ch_gp/tch;

    return GPA;
}

void sort(struct student *s , int i ){
    struct student temp;
    int m,n,j;

            for(m=0;m<i-1;m++)
            for(n=0;n<i-1-m;n++)
            if( (s+n)->GPA > (s+n+1)->GPA )
            {

                temp.id = (s+n)->id ;
                (s+n)->id = (s+n+1)->id ;
                (s+n+1)->id = temp.id ;

                strcpy( temp.name , (s+n)->name );
                strcpy( (s+n)->name , (s+n+1)->name );
                strcpy( (s+n+1)->name , temp.name );

                temp.courses = (s+n)->courses ;
                (s+n)->courses = (s+n+1)->courses ;
                (s+n+1)->courses = temp.courses ;


                for(j=0; j< (s+n)->courses || j<(s+n+1)->courses ;j++)
               {strcpy( temp.course_id[j] , (s+n)->course_id[j] );
                strcpy( (s+n)->course_id[j] , (s+n+1)->course_id[j] );
                strcpy( (s+n+1)->course_id[j] , temp.course_id[j] );

                temp.credit_hours[j] = (s+n)->credit_hours[j] ;
                (s+n)->credit_hours[j] = (s+n+1)->credit_hours[j] ;
                (s+n+1)->credit_hours[j] = temp.credit_hours[j] ;

                temp.marks[j] = (s+n)->marks[j] ;
                (s+n)->marks[j] = (s+n+1)->marks[j] ;
                (s+n+1)->marks[j] = temp.marks[j] ;

                temp.grade_point[j] = (s+n)->grade_point[j] ;
                (s+n)->grade_point[j] = (s+n+1)->grade_point[j] ;
                (s+n+1)->grade_point[j] = temp.grade_point[j] ;

                strcpy( temp.letter_grade[j] , (s+n)->letter_grade[j] );
                strcpy( (s+n)->letter_grade[j] , (s+n+1)->letter_grade[j] );
                strcpy( (s+n+1)->letter_grade[j] , temp.letter_grade[j] );
               }

                temp.GPA = (s+n)->GPA ;
                (s+n)->GPA = (s+n+1)->GPA ;
                (s+n+1)->GPA = temp.GPA ;
            }

    return;
}



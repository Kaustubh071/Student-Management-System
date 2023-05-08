#include <stdio.h>
#include <stdlib.h>

struct student{
     int roll,p1,p2,p3;
    char name[20];
};
int main()
{
    int i=0,n=0,ch=0,m=0,l=1,temp,j=1,c,rollno,d=0,x=0,e=0;
    char temp1[20],NAME[25];
    struct student st[20];
    FILE *fp;
    fp=fopen("student.txt","r");

    //Checking file empty or not
    fseek(fp,0,SEEK_END);
    if(ftell(fp)==0)
    {
        printf("No record\n");
    }
    else{
        printf("data found\n");
        //end
        fseek(fp, 0L, SEEK_SET);

    while(!feof(fp))
    {
       fscanf(fp,"%d %s %d %d %d\n",&st[i].roll,&st[i].name,&st[i].p1,&st[i].p2,&st[i].p3);
       i++;
    }

    }
    m=i;
    printf("Welcome to Student Management System\n");
       while(l){
    printf("1. Add Student\n");
    printf("2. Show Student\n");
    printf("3. Delete Student\n");
    printf("4. Update Student\n");
    printf("5. Search Student\n");
    printf("0. Exit\n");
        printf("Choice : ");
        scanf("%d",&ch);
        switch(ch){

          case 1:

            printf("Number of student : ");
            scanf("%d",&n);

          for(i=m;i<m+n;i++)//2
          {

              printf("Student %d\n",i+1);
              printf("\nRoll number: ");
              scanf("%d",&rollno);
              for(x=0;x<i;x++)
              {
                  if(rollno!=st[x].roll)
                  {
                    e++;
                  }

              }
              if(e==i)
              {
              st[i].roll=rollno;
              printf("\nName: ");
              scanf("%s",&st[i].name);
              fflush(stdin);
              printf("\nMarks");
              printf("\nPaper1: ");
              scanf("%d",&st[i].p1);
              printf("\nPaper2: ");
              scanf("%d",&st[i].p2);
              printf("\nPaper3: ");
              scanf("%d",&st[i].p3);
              fp=fopen("student.txt","w");
                for(i=0;i<m;i++)
                {
                    fprintf(fp,"%d %s %d %d %d\n",&st[i].roll,&st[i].name,&st[i].p1,&st[i].p2,&st[i].p3);
                }
                fclose(fp);
                printf("Record Save..!\n");
                m+=n;
              }
              else{
               printf("\nRoll number is already used\n");
              }

          }





            break;
            case 2:
            printf("Roll number\t|\tName\t|\tPaper1\t|\tPaper2\t|\tPaper3\t|\tResult\t|\tRemark\n");
            for(i=0;i<m;i++)
            {
                if(st[i].roll!=0)
                {
                 printf("\n%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\t",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);
                if((st[i].p1+st[i].p2+st[i].p3)>100)
                printf("Pass\n");
                else
                printf("Fail\n");
                }
            }
            break;
            case 3:
                printf("Delete Record :\n");
                printf("Enter Student Roll: ");
                scanf("%d",&temp);
                for(i=0;i<m;i++)
              {
                  if(temp==st[i].roll)
                  {
              printf("\nRoll number: %d",st[i].roll);
              printf("\nName: %s",st[i].name);

              while(j)
              {
                printf("Do you really want to delete this record? (y/n) \n");
                printf("Choice:");
                scanf("%d",&c);
                 if(c==1)
                 {
                     strcpy(st[i].name," ");
                  st[i].roll = 0;
                  st[i].p1 = 0;
                  st[i].p2 = 0;
                  st[i].p3 = 0;
                  printf("...OK RECORD DELETED\n");
                  j=0;
                   fp=fopen("student.txt","w");
                 for(i=0;i<m;i++)
                 {
                     if(st[i].roll!=0)
                    fprintf(fp,"%d %s %d %d %d\n",&st[i].roll,&st[i].name,&st[i].p1,&st[i].p2,&st[i].p3);
                   }
                fclose(fp);
                        for(i=0;i<m;i++)
          {

              if(st[i].roll!=0)
                {
                 printf("\n%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\t",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);
                if((st[i].p1+st[i].p2+st[i].p3)>100)
                printf("Pass\n");
                else
                printf("Fail\n");
                }
          }

                 }
                 else if(c==2)
                 {
                     printf("....OK NO RECORD DELETED\n");
                     j=0;
                 }
                 else

                     printf("Enter right choice please!!\n");
                 }
              }
              else{
                d++;
              }
                  }
                  if(m==d)
                  {
                      printf("No record found !!\n");
                  }
                  d=0;
                  j=1;
                  break;



            case 4:
                for(i=0;i<m;i++)
                {
                   printf("Update Record\n");
                printf("Enter student roll : ");
                scanf("%d",&temp);


                for(i=0;i<m;i++)
                {
                    if(temp==st[i].roll)
                    {

                        printf("Update\n");
                        printf("1. Name\n2. Paper1\n3. Paper2\n4. Paper3\n");
                        printf("Choice:");
                        scanf("%d",&c);
                        if(c==1)
                        {
                          for(i=0;i<m;i++)
                        {
                            if(temp==st[i].roll)
                            {
                                printf("Roll no %d Current name is %s\nEnter new Name : ",st[i].roll,st[i].name);
                                scanf("%s",NAME);
                                printf("Do you really want to change the name \n Choice:");
                                scanf("%d",&c);
                                if(c==1)
                                {
                                    strcpy(st[i].name,NAME);
                                    printf("...OK RECORD UPDATED\n");
                                    fp=fopen("student.txt","w");
                        for(i=0;i<m;i++)
                       {
                           fprintf(fp,"%d %s %d %d %d\n",&st[i].roll,&st[i].name,&st[i].p1,&st[i].p2,&st[i].p3);
                           }
                      fclose(fp);


                                }
                                else
                                     printf("...OK RECORD NOT UPDATED\n");
                            }

                        }



                }

                 else if(c==2)
                        {
                          for(i=0;i<m;i++)
                        {
                            if(temp==st[i].roll)
                            {
                                printf("Do you really want to change the Marks \n Choice:");
                                scanf("%d",&c);
                                if(c==1)
                                {
                                    printf("Roll no %d Current paper1 marks are %d\nEnter new marks : ",st[i].roll,st[i].p1);
                                    scanf("%d",&st[i].p1);
                                     fp=fopen("student.txt","w");
                                   for(i=0;i<m;i++)
                           {
                           fprintf(fp,"%d %s %d %d %d\n",&st[i].roll,&st[i].name,&st[i].p1,&st[i].p2,&st[i].p3);
                           }
                      fclose(fp);
                                    printf("...OK RECORD UPDATED\n");



                                }
                                else
                                     printf("...OK RECORD NOT UPDATED\n");
                            }

                        }

                }


                else if(c==3)
                        {
                          for(i=0;i<m;i++)
                        {
                            if(temp==st[i].roll)
                            {
                                printf("Do you really want to change the Marks \n Choice:");
                                scanf("%d",&c);
                                if(c==1)
                                {
                                    printf("Roll no %d Current paper2 marks are %d\nEnter new marks : ",st[i].roll,st[i].p2);
                                    scanf("%d",&st[i].p2);
                                     fp=fopen("student.txt","w");
                                   for(i=0;i<m;i++)
                           {
                           fprintf(fp,"%d %s %d %d %d\n",&st[i].roll,&st[i].name,&st[i].p1,&st[i].p2,&st[i].p3);
                           }
                      fclose(fp);
                                    printf("...OK RECORD UPDATED\n");



                                }
                                else
                                     printf("...OK RECORD NOT UPDATED\n");
                            }

                        }

                }

                else if(c==4)
                        {
                          for(i=0;i<m;i++)
                        {
                            if(temp==st[i].roll)
                            {
                                printf("Do you really want to change the Marks \n Choice:");
                                scanf("%d",&c);
                                if(c==1)
                                {
                                    printf("Roll no %d Current paper3 marks are %d\nEnter new marks : ",st[i].roll,st[i].p3);
                                    scanf("%d",&st[i].p3);
                                     fp=fopen("student.txt","w");
                                   for(i=0;i<m;i++)
                           {
                           fprintf(fp,"%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\n",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);
                           }
                      fclose(fp);
                                    printf("...OK RECORD UPDATED\n");



                                }
                                else
                                     printf("...OK RECORD NOT UPDATED\n");
                            }

                        }

                }
        }




                else{
                       d++;
                    }

        }
         if(m==d) {
                    printf("No Record found!!\n");
                  }
                d=0;

       }


             break;
            case 5:
                for(i=0;i<m;i++)
                {


                        printf("Search:\n");
                        printf("1. Search By Name\n2. Search By Roll\n");
                        printf("Choice:");
                        scanf("%d",&c);
                        if(c==1)
                        {
                            printf("Enter Name : \n");
                            scanf("%s",&temp1);

             for(i=0;i<m;i++)
             {

                printf("Roll number\t|\tName\t|\tPaper1\t|\tPaper2\t|\tPaper3\t|\tResult\t|\tRemark\n");
                for(i=0;i<m;i++)
          {
              if(strcmp(temp1,st[i].name)==0){
                    printf("%d\t\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);

             if((st[i].p1+st[i].p2+st[i].p3)>100)
                printf("Pass\n");
              else
                printf("Fail\n");}

          }

             }




                        }
                        if(c==2)
                        {
                            printf("Enter Roll : \n");
                            scanf("%d",&temp);
              printf("Roll number\t|\tName\t|\tPaper1\t|\tPaper2\t|\tPaper3\t|\tResult\t|\tRemark\n");
             for(i=0;i<m;i++)
             {


                           if(temp==st[i].roll)
                                for(i=0;i<m;i++)
          {
              if(temp==st[i].roll){printf("%d\t\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);

             if((st[i].p1+st[i].p2+st[i].p3)>100)
                printf("Pass\n");
              else
                printf("Fail\n");}
          }

       }

     }
  }
            break;
            case 0:
                printf("NOTE: AFTER EXITING SYSTEM ALL RECORD IS DELETE AUTOMATICALLY...\n ");
                printf("Do you want to exit?(y/n)\n ");
                printf("choice: ");
                scanf("%d",&temp);

                l=0;
                if(temp==2)
                {
                     for(i=0;i<m;i++)
                   {
                    strcpy(st[i].name," ");
                  st[i].roll = 0;
                  st[i].p1 = 0;
                  st[i].p2 = 0;
                  st[i].p3 = 0;
                   }

                    fp=fopen("student.txt","w");
                    for(i=0;i<m;i++)
                   {
                       if(st[i].roll!=0)
                     fprintf(fp,"%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);
                    }
                     fclose(fp);
                    printf("THANK YOU!\nFOR USING SYSTEM");
                }

                if(temp==1)
                {
                     fp=fopen("student.txt","w");
                    for(i=0;i<m;i++)
                   {
                     fprintf(fp,"%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\n",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);
                    }
                     fclose(fp);
                    printf("THANK YOU!\nFOR USING SYSTEM");
                }

            break;

            default:

            break;
            }
       }
    return 0;
}

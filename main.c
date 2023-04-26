#include <stdio.h>
#include <stdlib.h>

struct student{
     int roll,p1,p2,p3;
    char name[20];
};
int main()
{
    int i,n=0,ch=0,m=0,l=1,temp,j,c,k;
    char temp1[20];
    FILE *fp;


    struct student st[5];
    fp=fopen("myfile.txt","r");
    for(i=0;i<m;i++)
                  {
                      fscanf(fp,"\n%d\t\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\t",&st[i].roll,&st[i].name,&st[i].p1,&st[i].p2,&st[i].p3,&st[i].p1+st[i].p2+st[i].p3);

                  }


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

          for(i=m,k=0;i<m+n,k<n;i++,k++)
          {

              printf("Student %d\n",k+1);
              printf("\nRoll number: ");
              scanf("%d",&st[i].roll);
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

          }
         m+=n;
        printf("Record Save..!\n");
            break;
            case 2:
                printf("RollNo\t|\tName\t|\tPaper1\t|\tPaper2\t|\tPaper3\t|\tResult\t|\tRemark\n");
                 for(i=0;i<m;i++)
          {
              printf("%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);

             if((st[i].p1+st[i].p2+st[i].p3)>100)
                printf("Pass\n");
              else
                printf("Fail\n");
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
                  }
              }
              for(i=0;i<m;i++)
              {
                   if(temp==st[i].roll)
                   {printf("Do you really want to delete this record? (y/n) \n");
              printf("Choice:");
              scanf("%d",&c);
           if(c==1)
           {
              for(i=0;i<m;i++)
              {
                if(temp==st[i].roll)
                {
                  for(j=i;j<m;j++)
                  {
                      st[j]=st[j+1];
                  }
                  m--;
                }
              }

              printf("...OK RECORD DELETED\n");

              printf("Roll number\t|\tName\t|\tPaper1\t|\tPaper2\t|\tPaper3\t|\tResult\t|\tRemark\n");
                 for(i=0;i<m;i++)
          {
              printf("%d\t\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);

             if((st[i].p1+st[i].p2+st[i].p3)>100)
                printf("Pass\n");
              else
                printf("Fail\n");
          }
           }
           else if(c==2)

              printf("....OK NO RECORD DELETED\n");
                    else
                    printf("this number is not in roll list!!!\n");
                   }


              }

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
                                scanf("%s",st[i].name);

                            }
                        }
                        }

                    else if(c==2)
                    {
                      for(i=0;i<m;i++)
                        {
                            if(temp==st[i].roll)
                            {
                                printf("Roll no %d Current paper1 marks are  %d\nEnter new paper1 marks : ",st[i].roll,st[i].p1);
                                scanf("%d",&st[i].p1);
                            }
                        }
                    }
                    else if(c==3)
                    {
                        for(i=0;i<m;i++)
                        {
                            if(temp==st[i].roll)
                            {
                                printf("Roll no %d Current paper2 marks are  %d\nEnter new paper2 marks : ",st[i].roll,st[i].p2);
                                scanf("%d",&st[i].p2);
                            }
                        }
                    }
                  else
                    {
                    for(i=0;i<m;i++)
                        {
                            if(temp==st[i].roll)
                            {
                                printf("Roll no %d Current paper3 marks are  %d\nEnter new paper3 marks : ",st[i].roll,st[i].p3);
                                scanf("%d",&st[i].p3);
                            }
                        }
                  }

                    }
                    }
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
                if(temp==2)
                main();
                l=0;

                if(temp==1)
                {
                  fp=fopen("myfile.txt","a");
                  for(i=0;i<m;i++)
                  {
                      fprintf(fp,"\n%d\t\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\t",st[i].roll,st[i].name,st[i].p1,st[i].p2,st[i].p3,st[i].p1+st[i].p2+st[i].p3);

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

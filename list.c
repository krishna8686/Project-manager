#include <stdio.h>
#include <string.h>
#include <yaml.h>                                                // this file contains the all list function(list5,list4,list3).
 #include<conio.h>
#include<process.h>
#include<dir.h>
#include<dirent.h>
///////////////////////////////////////////////////////////////
void list5(char* a,char*b){
    
    DIR *ptr;
    ptr = opendir(b);                                             // here the logic of showing  YES or NO.
    char * n;                                                     //if A type file present in B type folder
      struct dirent *directory;
       strcat(a,".yaml");
      
      
      while((directory = readdir(ptr)) != NULL)
      {
            n=directory->d_name;
            if(strcmp(a,n)==0)
            printf("yes,it is available\n");
            else
            printf("no,it is not available\n");

      }
      closedir(ptr);
}
///////////////////////////////////////////////////////////////
void list4(char*a){
                                                                // here the logic will show the list of project where A type file present
    DIR *ptr1,*ptr2;
    char * n,*m;
      struct dirent *directory1,*directory2;
       strcat(a,".yaml");
       ptr1 = opendir(".");

       while((directory1 = readdir(ptr1)) != NULL)
      {
            n=directory1->d_name;
            ptr2 = opendir("n");
            int i=0;

            while((directory2 = readdir(ptr2)) != NULL)
            {
            m=directory2->d_name;
            if(strcmp(a,n)==0)
            {
               i=1;
               break;
            }
            else
            continue;

            }
            closedir(ptr2);


            if(i==1)
            printf("%s\n",n);
            else
            continue;


      }
      closedir(ptr1);
    
}
////////////////////////////////////////////////////////////////////
void list3(char *s){
    DIR *ptr;
    char * n;                                                                  //// here the logic will show YES or NO if the s type folder is present or not.
      struct dirent *directory;
      
      ptr = opendir(".");
      
      while((directory = readdir(ptr)) != NULL)
      {
            n=directory->d_name;
            if(strcmp(s,n)==0)
            printf("yes,it is available\n");
            else
            printf("no,it is not available\n");

      }
      closedir(ptr);
    
}
//////////////////////////////////////////////////////////////////////////////
void list2(){

     DIR *ptr;                                                                // here the logic will show the all project folder ...
      struct dirent *directory;
      
      ptr = opendir(".");
      
      while((directory = readdir(ptr)) != NULL)
      {
            printf("%s\n", directory->d_name);
      }
      closedir(ptr);
}


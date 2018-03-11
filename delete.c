#include <stdio.h>
#include <string.h>
#include <yaml.h>
#include<conio.h>
#include<process.h>                                                       //his folder is for delete folders or files
#include<dir.h>
#include <dirent.h>
#include <direct.h>
#include <errno.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////



void delete5(char *a,char *b){
                                                                             // this is for delete all A type folder in B type project
   DIR *ptr;
      struct dirent *directory;
      
      ptr = opendir(b);
      strcat(a,".yaml");
      
      while((directory = readdir(ptr)) != NULL)
      {
           
            if(strcmp(a,directory->d_name)==0)
            remove(directory->d_name);
            else
            continue;

      }
      closedir(ptr);

}
///////////////////////////////////////////////////////////////////////////////////////
void delete4(char *a){
                                                                               //// this is for delete all A type folder in all projects
   DIR *ptr1,*ptr 2;
      struct dirent *directory1,*directory2;
      
      ptr1 = opendir(".");
      strcat(a,".yaml");
      
      while((directory1 = readdir(ptr1)) != NULL)
      {
           ptr2 = opendir(directory1->d_name);
           while((directory2 = readdir(ptr)) != NULL)
      {
           
            if(strcmp(a,directory->d_name)==0)
            remove(directory2->d_name);
            else
            continue;

      }
      closedir(ptr2);
            
      }
      closedir(ptr1);

}
/////////////////////////////////////////////////////////////////////////////////////////
void delete3(char* b){

                                                                                  // this is for delete the  B type project
           opendir(b);
            char buff[FILENAME_MAX];
            GetCurrentDir( buff, FILENAME_MAX );
            rmdir(buff);
      

}
//////////////////////////////////////////////////////////////////////////////////////////
void delete2(){                                                                     //this is for delete all projects.....

   DIR *ptr;
      struct dirent *directory;
      
      ptr = opendir(".");
      
      while((directory = readdir(ptr)) != NULL)
      {
           opendir(directory->d_name)
            char buff[FILENAME_MAX];
            GetCurrentDir( buff, FILENAME_MAX );
            rmdir(buff);
      }
      closedir(ptr);

}
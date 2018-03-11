#include <stdio.h>
#include <string.h>
#include <yaml.h>
#include<process.h>                                                       //this code is for showing types of projects and folder
#include<dir.h>
#include <dirent.h>
#include <direct.h>

/////////////////////////////////////////////////////////////////////////
void types5(char *a,char *b){
     DIR *ptr;                                                             //this code will show YES or NO if A type folder present in B type project
      struct dirent *directory;
      
      ptr = opendir(b);
      
      while((directory = readdir(ptr)) != NULL)
      {
            if(strcmp(a,directory->d_name)==0)
            {printf("yes. available");
            break;}
            else
            continue;
      }
      closedir(ptr);

}
///////////////////////////////////////////////////////////////////////////////////
void types4(char *a){
    printf("%s .yaml\n", a);                                                   //this code is for types of A type of file
}
//////////////////////////////////////////////////////////////////////////////////

void types3(char *b){                                                           // this code will show all files in B type projects
    DIR *ptr;
      struct dirent *directory;
      
      ptr = opendir(b);
      
      while((directory = readdir(ptr)) != NULL)
      {
            printf("%s//%s .yaml\n", b,directory->d_name);
      }
      closedir(ptr);
}
    
}
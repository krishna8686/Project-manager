#include <stdio.h>
#include <string.h>
#include <yaml.h>                                               // this is for describe all structures of projeects or file..


////////////////////////////////////////////////////////////////////////
void describe5(char *a,char *b){
                                                                // this is for describe all structures of A typee file in B type projeects.


    
}
///////////////////////////////////////////////////////////////////////////
void describe4(char *a){
                                                                //// this is for describe structures of A typee file only.
int c;
FILE *file;
file = fopen("a.yaml", "r");
if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);

}
///////////////////////////////////////////////////////////////////////////
void describe3(char *b){
                                                                // this is for describe all structures all the files in B type projeects.
   DIR *ptr;                                                                // here the logic will show the all project folder ...
      struct dirent *directory;
      
      ptr = opendir("b");
      
      while((directory = readdir(ptr)) != NULL)
      {

          int c;
          FILE *file;
          file = fopen("a.yaml", "r");
          if (file) {
          while ((c = getc(file)) != EOF)
           putchar(c);
           fclose(file);
            printf("%s.yaml\n", directory->d_name);

      }
      closedir(ptr);

}
///////////////////////////////////////////////////////////////////////////
void describe2(){
                                                                // this is for describe all structures of all file in all projeects.
}
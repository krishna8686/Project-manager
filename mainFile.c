/* this code will not work because i have not added all features and also did not get some syntax of parsing of yaml file in Programming C...*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>                                              // this is the main and controller file.
#include <yaml.h>                                                //included library....
#include <dirent.h>
#include "list.c"
#include "delete.c"                                              //included  other file....
#include "types.c"
#include "creat.c"
#include "describe.c"

int main(int argc, char **argv[])
 {


    //  get the environment variable.....
char *x=getenv(PROJMAN_TEMPLATES);

   if(x==NULL)
   FILE *fh = fopen("projman_templates.yaml", "r");
   else
   FILE *fh = fopen(x, "r");
   ///////////////////////////////////////////////////

//    parsing started.....................
   yaml_parser_t parser;
   yaml_token_t  token;

   
  if(!yaml_parser_initialize(&parser))
    fputs("Failed to initialize parser!\n", stderr);
  if(fh == NULL)
    fputs("Failed to open file!\n", stderr);

    yaml_parser_set_input_file(&parser, fh);


    int i=0,j=0;
    char **str;
    do {
    yaml_parser_scan(&parser, &token);
                                                                                     // parsing section.....str...ponter shows the all module in the YAML file
    if(token.type==YAML_VALUE_TOKEN  && i==0)
      str[j++]=token.data.scalar.value;

   
    if(token.type==YAML_BLOCK_MAPPING_START_TOKEN)
      {
        char *y=YAML_BLOCK_MAPPING_START_TOKEN;
        j--;
        i++;
        continue;
      }
    if(i==1 && y==YAML_BLOCK_MAPPING_START_TOKEN)
      {
        y=NULL;
        str[j++]=token.data.scalar.value;

      }

      if(token.type==YAML_BLOCK_END_TOKEN)
      i--;



    
       if(token.type != YAML_STREAM_END_TOKEN)
       yaml_token_delete(&token);
    } while(token.type != YAML_STREAM_END_TOKEN);

       yaml_token_delete(&token);

       yaml_parser_delete(&parser);
       fclose(fh);

/////////////////////////////////////////////////////

// checking for cmd line arguments combination and possibilities.........

   if(argc == 5)
   {                                                                          //if cmd line arg has 5 variable
       switch(argv[3])
       {                                                                       // ex.... (pm) (-t) (TYPE) (sub cmd) (name) 
           case "list":{                                                       //          pm -t maya create Avengers
               list5(argv[2],argv[4]);
               break;
           }       
           case "create":{
               create5(argv[2],argv[4]);
               break;
            }
           case "delete":{
               delete5(argv[2],argv[4]);
               break;
            } 
           case "types":{
               types5(argv[2],argv[4]);
               break;
            }
           case "describe":{
               describe5(argv[2],argv[4]);
               break;
            }                                                     
       }
   }
/////////////////////////////////////////////////////////

   if(argc == 4)                                                               // if cmd line arg has 4 variables...
   {                                                                            // ex.....pm -t maya describe
       switch(argv[3])
       {
           case "list":{
               list4(argv[2]);
               break;
            }
           
           case "delete":{
                delete4(argv[2]);
                break;
            }             
           case "types":{
                types4(argv[2]);
               break;
            }
           case "describe":{
                describe4(argv[2]);
               break;
            }                                                     
       }
   }
////////////////////////////////////////////////////////////////////////

   if(argc == 3)                                                             // if cmd line arg has 3 variables....
   {                                                                         // ex.......pm  list Avengers
       switch(argv[1])
       {
           case "list":{
               list3(argv[2]);
               break;
            }
           case "create":{
               create3(argv[2]);
               break;
            }             
           
           case "delete":{
                delete3(argv[12);
                break;
                } 
           case "types":{
                types3(argv[2]);
               break;
            }
           case "describe":{
                describe3(argv[2]);
               break;
            }                                                     
       }
   }

////////////////////////////////////////////////////////////////////////////
   if(argc == 2)                                                                 // if cmd line arg has 2 variables
   {                                                                             // ex.....pm list
       switch(argv[1])
       {
           case "list":{
               list2();
               break;
            }
           
           case "delete":{
              deleete2();
               break; 
            } 
           
           case "describe":{
             describe2();
               break;
            }                                                     
       }
   }
   return 0;

 }

 /* this code will not work because i have not added all features and also did not get some syntax of parsing of yaml file in Programming C...*/
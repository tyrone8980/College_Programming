#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<dirent.h>
#include <sys/wait.h>
#include<error.h>
#define MAXLEN 256
#define MAXARGS 10
int cd(char *mypath);
int main(){
  char command[MAXLEN];  /* Holds user's command. */
  char *words[MAXARGS];   /* The command is split into a list of words. */
  char *token; /* Used to tokenize command. */
  int count;
  char ch;
  int status = 0;
  strcmp(command, ""); /* Initialize to empty string. */

  while ( 1 ){ /* Loop forever */

    /* TBD: Display prompt. */
	printf("Welcome to the ultimate shell!\n Please enter some commands daddy:");
    /* TBD: Read "command" */
	 if(!fgets(command,MAXLEN,stdin))
	{            //check if command is exit
	        break;
        }

    command[strlen(command)-1] = '\0'; /* Strip off CR; see fgets docs. */

    /* Exit shell is exit command is typed. */
    if ( strcmp(command, "exit") == 0 ){
      printf("Bye bye.\n");
      /* TBD: Terminate this program. */
	break;

    }
    if(strcmp(command, "cd")==0)
    {
            token = strchr(command,' '); //use something more powerful
            if(token) {
                char *tempTok = token + 1;
                token = tempTok;
                char *locationOfNewLine = strchr(token, '\n');
                if(locationOfNewLine) {
                    *locationOfNewLine = '\0';
                }
                cd(token);
            }
        else{
            system("ls"); //for testing the CWD/PWD
        }
	////////
//	token = strtok(NULL, "\n");
//	cd(token);
    }

    /* TBD: Fork off a new process, get pid */
	int pid = fork();


    if (pid== 0/* TBD: Insert check here */ ){  /* Child process. */

      /* Parse command into a list of words. */
      count = 0;
      token = strtok(command, " 	");
      while ( token != NULL ){
        words[count] = (char *) malloc(strlen(token)+1);
        strcpy(words[count++], token);
        token = strtok(NULL, " 	");
      }
      words[count] = NULL;

      /* TBD: Use execvp system call to replace process code. */
	execvp(command,words);

      /* If we get to this line, something bad happened. */
      fprintf(stderr, "Error executing command.\n");
      exit(1);
    }
    else{ /* Parent process. */
      /* TBD: Wait for child to terminate. */
	wait(&status);
	

    }
  }  /* End of while loop */
}

int cd(char *mypath)
{
	char path[MAXLEN];
	strcpy(path, mypath);
	char cwd[MAXLEN];
	if(mypath[0] != '/')
	{
	getcwd(cwd,sizeof(cwd));
	strcat(cwd,"/"); 
        strcat(cwd,path);
        chdir(cwd);    
	}else{
		chdir(mypath);
}
	return 0;
}

/* Kyle Gamble - CS564 - HW2 */
/* This program repeatedly asks user for commands to execute */

#define TRUE 1
#define MAX_LEN 100
#include <stdio.h>
#include <unistd.h>

/* global variables */
char cmd[25];
char params[50];
int status;
const char *cmdptr;
char *paramptr;

/* method signatures */
void type_prompt();
void read_command(char[], char[]);

int main()
{
	while (TRUE)
	{
	   type_prompt();
	   read_command(cmd, params);
	   
	   cmdptr = cmd;
	   paramptr = params;

	   if (fork() != 0)
	   {
	      waitpid(-1, &status, 0);
	   }
	   else
	   {
	      execve(cmdptr, &paramptr, 0);	
 	   }
	}	
	return 0;
}

void type_prompt()
{
	printf("Enter command to execute: ");
	fgets (cmd, 25, stdin);
	printf("Enter parameters for the command: ");
	fgets (params, 50, stdin);
}

void read_command(char command[], char parameters[])
{
   /* check if array has valid cmd */
   if (command[0] == '\0')
   {
      printf("You have not provided a valid command!\n");
      type_prompt();
   }
   else
   {
      printf("Valid command!\nExecuting...\n");	
   }
}


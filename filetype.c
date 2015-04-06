/* Kyle Gamble - CS564 - HW5 */
/* This program attempts to recognize the file type of a file, which 
 * is input by the user. This is achieved by first looking at the file
 * extension, then looking at the magic number, and finally reading the 
 * contents of the file if needed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

// method sigs
char* getFileTypeByExt(char*);
char* magic(char[]);

int main(int argc, char *argv[])
{
   FILE *file = NULL;
   struct stat buf;

   // if no filename supplied, then print usage of filetype cmd
   if (argc != 2)
   {
      printf("usage:\n");
      printf("	filetype <filename>\n\n");
      printf("This command accepts a single filename as the input parameter. ");
      printf("The first check is to see whether or not the filename is a regular file or special file. This is accomplished using the system command stat().\n\nTo determine the file type, there are three steps.\nStep 1: Compare the file extension to known file extensions.\nStep 2: Examine the magic number at the beginning of the file.\nStep 3: Check the contents of the file (this will only work on txt files.)\n");
      return 1;
   }

   // use system command stat() to determine regular versus special file
   stat(argv[1], &buf);
   // debugging tools
   //printf("%d\n", errno);
   //printf("Permissions: %i\n", buf.st_mode);
   if ((buf.st_mode & S_IFMT) == S_IFREG)
   {
      printf("This is a regular file, so let's figure out the file type.\n");
   }
   else
   {
      printf("This is a special filetype, so we will not parse any further.\nProgram will now exit.\n");
      return 0;
   }

   // determine file extension
   //printf("The file extension is: %s", getFileExt(argv[1]));
   char *ext = strrchr(argv[1], '.');
   if (!ext)
   {
      // no ext
      printf("file extension could not be found\n");
   }
   else
   {
      printf("file extension: %s\n", ext + 1); 
      printf("file type: %s\n", getFileTypeByExt(ext + 1));
      //return 0;
   }

   // look for magic number
   printf("analyzing the file's magic number...\n");

   int i;
   char buffer[4];
   file = fopen(argv[1], "r");
   if (fread(buffer,1,4,file) == 4)
   {
      printf("fread was successful and the first 4 bytes are:\n\n");
      for (i = 0; i < 4; i++)
         printf("%02X ", buffer[i]);

      printf("\nthe file type based on the magic numbers is:\n");

      // determine file type
      printf("%s\n", magic(buffer));

      if (strcmp(magic(buffer), "was not able to parse file's magic number") == 0)
      {}
      else
         return 0;
   }
   else
      printf("could not read the magic 4 bytes from file!\n");


   printf("\nopening file %s...\n", argv[1]);
   //filep = fopen(argv[1], "w");
   if (file == NULL)
   {
      perror("error opening file!");
      return 1;
   }

   printf("writing first four bytes of output...\n\n%s...\n", buffer);

   // determine if file content is text
   printf("ASCII value of %c = %d\n", buffer[0], buffer[0]); 
   if (buffer[0] < 128 && buffer[0] > 0)
      printf("based on the ASCII values, this is a text file\n");

   printf("\nDone\n");
  
   return 0;
}

// look at the file extension to determine file type
char *getFileTypeByExt(char *ext)
{
   char *type = "file type could not be found by comparing extension\n";

   if (strcmp(ext, "txt") == 0) // 1
      type = "plain text file"; 
   else if (strcmp(ext, "c") == 0) // 2
      type = "C file";
   else if (strcmp(ext, "h") == 0) // 3
      type = "header file";
   else if (strcmp(ext, "log") == 0) // 4
      type = "log file";
   else if (strcmp(ext, "rtf") == 0) // 5
      type = "rich text format file";
   else if (strcmp(ext, "csv") == 0) // 6
      type = "comma separated values file";
   else if (strcmp(ext, "dat") == 0) // 7
      type = "data file";
   else if (strcmp(ext, "sdf") == 0) // 8
      type = "standard data file";
   else if (strcmp(ext, "tar") == 0) // 9
      type = "consolidated unix file archive";
   else if (strcmp(ext, "vcf") == 0) // 10
      type = "vCard file";
   else if (strcmp(ext, "xml") == 0) // 11
      type = "xml file";
   else if (strcmp(ext, "m4a") == 0) // 12
      type = "mpeg-4 audio file";
   else if (strcmp(ext, "mid") == 0) // 13
      type = "midi file";
   else if (strcmp(ext, "mp3") == 0) // 14
      type = "mp3 audio file";
   else if (strcmp(ext, "avi") == 0) // 15
      type = "audio video interleave file";
   else if (strcmp(ext, "mpg") == 0) // 16
      type = "mpeg video file";
   else if (strcmp(ext, "bmp") == 0) // 17
      type = "bitmap image file";
   else if (strcmp(ext, "gif") == 0) // 18
      type = "graphical interchange format file";
   else if (strcmp(ext, "jpg") == 0) // 19
      type = "jpeg image file";
   else if (strcmp(ext, "png") == 0) // 20
      type = "portable network graphic";
   else if (strcmp(ext, "tif") == 0) // 21
      type = "tagged image file";
   else if (strcmp(ext, "tiff") == 0) // 22
      type = "tagged image file format";
   else if (strcmp(ext, "pdf") == 0) // 23
      type = "portable document format file";
   else if (strcmp(ext, "bat") == 0) // 24
      type = "dos batch file";
   else if (strcmp(ext, "exe") == 0) // 25
      type = "windows executable file";

   return type;
}

// look at the file's magic number to determine file type
char *magic(char hex[])
{
   char *type = "was not able to parse file's magic number";
   int i;
   char *allhex;
   allhex = (char *)malloc(100);
   char *str;
   str = (char *)malloc(100);
   for (i = 0; i < 4; i++)
   {
      sprintf(str, "%02X", hex[i]);
      strcat(allhex, str);
   }
   // determine file type
   if (strcmp(allhex, "25504446") == 0)
      type = "pdf file";
   else if (strcmp(allhex, "89504E47") == 0)
      type = "png image file";
   else if (strcmp(allhex, "49492A00") == 0)
      type = "tif file";
   else if (strcmp(allhex, "4D4D002A") == 0)
      type = "tiff file";
   else if (strcmp(allhex, "494E4458") == 0)
      type = "idx file";
   else if (strcmp(allhex, "2F2F2061") == 0)
      type = "exe file";
   else if (strcmp(allhex, "49443303") == 0)
      type = "mp3 audio file";
   else if (strcmp(allhex, "424DFFFFFFB651") == 0)
      type = "bmp image file";
   else if (strcmp(allhex, "FFFFFFFFFFFFFFD8FFFFFFFFFFFFFFE0") == 0)
      type = "jpeg image file";
   else if (strcmp(allhex, "47494638") == 0)
      type = "gif image file";

   //printf("allhex: %s", allhex);
   return type;
} 

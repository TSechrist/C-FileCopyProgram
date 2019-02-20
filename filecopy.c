#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 21
// ABOVE VALUE CANNOT BE CHANGED //



int
main(int argc, char const *argv[])
{

    char fromFile[255];
    char toFile[255];

    printf("Welcome to the File Copy Program by Thomas Sechrist!\n");
    printf("Enter the name of the file to copy from:");
    scanf("%s", fromFile);
    printf("Enter the name of the file to copy to: ");
    scanf("%s", toFile);
    

    return 0;
}
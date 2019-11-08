// C program to Open a File,
// Read from it, And Close the File

#include <stdio.h>
#include <string.h>

int main()
{

    // Declare the file pointer
    FILE *filePointer;

    // Declare the variable for the data to be read from file
    char dataToBeRead[50];

    // Open the existing file GfgTest.c using fopen()
    // in read mode using "r" attribute
    filePointer = fopen("read.txt", "r+"); //mode specifies how file will be read
                                           //wx mode to keep check on existinf file
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if (filePointer == NULL)
    {
        printf("file.c file failed to open.");
    }
    else
    {

        printf("The file is now opened.\n");

        // Read the dataToBeRead from the file
        // using fgets() method
        while (fgets(dataToBeRead, 50, filePointer) != NULL)
        {

            // Print the dataToBeRead
            printf("%s", dataToBeRead);
        }
        //================TEST FUNCTIONS=========
        //1
        fpos_t position;
        fgetpos(filePointer, &position);
        fputs("HelloWorld!", filePointer);
        fsetpos(filePointer, &position);
        // previous function is override
        fputs("geeksforgeeks", filePointer);

        //2
        //// File name is changed here
        //value = rename(old_name, new_name);

        //3
        //FILE* tmp = tmpfile();

        //=======================================================END
        // Closing the file using fclose()
        fclose(filePointer);

        printf("\nData successfully read from file GfgTest.c\n");
        printf("The file is now closed.");
    }
    return 0;
}

//======
/*
1. if ( fseek(fp, 0L, SEEK_SET) != 0 ) { 
    //int fseek(FILE *pointer, long int offset, int position)
  // Handle repositioning error
  //to move the read pointer head
  //rewind can be used
SEEK_END : It denotes end of the file.
SEEK_SET : It denotes starting of the file.
SEEK_CUR : It denotes file pointer’s current position.  
}

2. feoe is used to detect end of file as EOF

3.long ftell(FILE *pointer) sends position from begining

4. remove file :remove("abc.txt")

5. fread(char **lineptr, n, fp)

//=====================FIle SCAN=========
1. gets
2. puts
3. getc
4. putc
5. fscanf
6. fprintf
7. fread //read binary data
8. fwrite
9. getline // allocates the buffer itself


*/
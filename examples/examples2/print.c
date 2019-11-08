#include <stdio.h>
#include <unistd.h>
#include <error.h>

//===Escape sequence
/*
\a    Alarm or Beep   
\b    Backspace
\f    Form Feed
\n    New Line
\r    Carriage Return
\t    Tab (Horizontal)
\v    Vertical Tab
\\    Backslash
\'    Single Quote
\"    Double Quote
\?    Question Mark
\ooo  octal number
\xhh  hexadecimal number
\0    Null */
int main()
{
    //===Print functions testing
    // printf("hellobabua");
    // // scanf("%*d");
    // printf("\r");
    // printf("done");

    // printf("hello");
    // //scanf("%*d");
    // printf("\rbye");

    //===terminal commands ==ncurses can be used for animation
    // man console_codes
    // printf("\033[8;5Hhello");
    // printf("\033[1A ddf"); // Move up X lines;
    // printf("\033[3B qw");  // Move down X lines;
    // printf("\033[4Cdf");   // Move right X column;
    // printf("\033[4Dhjhh"); // Move left X column;
    // sleep(2);
    // printf("\033[2Jdfd"); // Clear screen without chaning cursor position

    //===Loop testing
    //printf("\033[0J");
    //printf("\033[1B");
    //printf("\033[2J");
    //printf("\033[31");
    /*for (int i = 0; i < 5; i++)
    {
        printf("\033[2J");
        printf("hello:%d\r", i); // /f is form feed used to start priting at new line below
        sleep(1);
        // -- / single slash is used for multiple line in strings
        fflush(stdout);
        //printf("\033c");
        //printf("\033[2J"); // terminal commands for unix
    }*/

    //==Loading screen
    /*
    for (int i = 0; i < 20; i++)
    {
        printf("\033[0;0HLoading: %d%%", i);
        printf("\033[2;%dH", i + 1);
        printf("|");
        fflush(stdout);
        sleep(1);
    }*/

    //===ERROR Prining
    perror("error"); //print error
    //errno- the number for error strerror()-covert error no to string
    return -1;
}

//==conclusion
//printf send data and cursor location to the terminal
//terminal is a file which displays the data. Can't be modified directly
/*-----------------------------------
Name : SUBRAT PRASAD PANDA
Roll number : CS1913
Date : 01/11/2019
Program description : ASSIGNMENT 3, Question 3- Finding Cycle in a graph
Acknowledgements : NIL
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

//Detect edge and put edge
#define is_edgeExist(a, b) schedule[i].trans_num != schedule[j].trans_num && \
                               !strcmp(schedule[i].cmd, a) &&                \
                               !strcmp(schedule[j].cmd, b) &&                \
                               !strcmp(schedule[i].var, schedule[j].var)

#define putEdge adj_mat[schedule[i].trans_num - 1][schedule[j].trans_num - 1] = 1 //To put 1 in the matrix when called

#define err_msg(x) \
    {              \
        perror(x); \
        exit(0);   \
    }

typedef struct nodes // Struct node to hold single instruction data
{
    int trans_num; // Transaction file number eg T1, T2 etc
    char *cmd;     // Command used eg read, write, commit
    char *var;     // variable used inside command
} NODE;

//====================FUNCTION DECLARATIONS========================
void to_low(char string[]);                     //function to convert text to lowercase
int find_schedule_length(int, char *[]);        //to find schedule length
int build_schedule(int, char *[], NODE *, int); //to build schedule table

/*========================LOGIC==========================
1. Build SCHEDULE table from the transaction file
2. From the table, build adjacency matrix using cases given in question
3. Use matrix multiplication to find the cycle; (Depth First Search can be used instead)
=========================================================*/

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("error: No files entered\n");
        exit(0);
    }
    int schedule_length;                                // total length schedule of schedule
    int numofTrans = argc - 1;                          //Total number of transactions
    schedule_length = find_schedule_length(argc, argv); //length of schedule

    // 1 based index of array
    NODE schedule[schedule_length + 1]; //Create array of instrutions [1 based index]

    //-------------BUILD SCHEDULE TABLE-------------------
    build_schedule(argc, argv, schedule, schedule_length); //Create schedule table from file

    //------------Create Adjacency Matrix------
    int adj_mat[numofTrans][numofTrans]; //adjacency matrix
    int temp = 0;
    memset(adj_mat, temp, sizeof(adj_mat)); //initialize the adj matrix with 0

    //Build adjacency matrix from the schedule
    for (int i = 1; i <= schedule_length; i++)
    {
        if (!strcmp(schedule[i].cmd, "read") || !strcmp(schedule[i].cmd, "write"))
        {
            for (int j = i + 1; j <= schedule_length; j++)
            { //Case(a) Ti executes write(Q) before Tj executes read(Q).
                if (is_edgeExist("write", "read"))
                    putEdge; //put one in adjmatrix - defined as function

                //Case(b) Ti executes read(Q) before Tj executes write(Q).
                if (is_edgeExist("read", "write"))
                    putEdge;
                //Case(c) Ti executes write(Q) before Tj executes write(Q).
                if (is_edgeExist("write", "write"))
                    putEdge;
            }
        }
    }

    //===========================FINDING CYCLE using MATRIX MULTIPLICATION=============
    int power[numofTrans][numofTrans];  // to store power value
    int temp_m[numofTrans][numofTrans]; // to store temp result
    //Aim is to find adj_mat to the power (numofTrans) which is the max length cycle posible
    for (int p = 1; p <= numofTrans; p++) //p is exponential power to the adj_mat
    {
        if (p == 1) //Finding power of 1, hence creating new power matrix
        {
            for (int i = 0; i < numofTrans; i++)
                for (int j = 0; j < numofTrans; j++)
                    power[i][j] = adj_mat[i][j];
        }
        else //For powers other than 1
        {
            for (int i = 0; i < numofTrans; i++)
            {
                for (int j = 0; j < numofTrans; j++)
                {
                    temp_m[i][j] = 0;
                    for (int k = 0; k < numofTrans; k++)
                        temp_m[i][j] += power[i][k] * adj_mat[k][j]; //Multiplication result stored in temp_m matrix
                }
            }
            //==========================copy the result to power matrix and CHECK if there is any cycle or not
            for (int i = 0; i < numofTrans; i++)
            {
                for (int j = 0; j < numofTrans; j++)
                {
                    power[i][j] = temp_m[i][j];     //result is used to store the multiplication result
                    if (i == j && power[i][i] != 0) //when diagonal entries becomes 0->cycle exists
                    {
                        printf("Not Conflict Serializable\n");
                        for (int i = 1; i <= schedule_length; i++)
                            free(schedule[i].cmd);
                        return 0;
                    }
                }
            }
        }
    }
    printf("Conflict Serializable\n");
    for (int i = 1; i <= schedule_length; i++)
        free(schedule[i].cmd);
    return 0;
}

//=====================FUNCTION DEFINITIONS========================

//Function 1
void to_low(char string[])
{
    int i = 0;
    while (string[i])
    {
        string[i] = tolower(string[i]);
        i++;
    }
}

//Function 2
int find_schedule_length(int t, char *ptr[])
{
    int length = 0; // To store the total length
    int temp;
    for (int i = 1; i < t; i++)
    {
        FILE *fp;
        fp = fopen(ptr[i], "r");
        if (!fp)
            err_msg("error");
        fscanf(fp, "%d", &temp);
        length = length + temp;
        fclose(fp);
    }

    return length;
}

//function 3
int build_schedule(int t, char *ptr[], NODE *sdl, int total_len)
{
    FILE *fp;
    int len;
    int sl_num;
    char *str;
    char *cmd;
    char *var;
    for (int i = 1; i < t; i++)
    {
        fp = fopen(ptr[i], "r");
        fscanf(fp, "%d", &len);
        for (int j = 1; j <= len; j++)
        {
            fscanf(fp, "%d %m[^\n\r]", &sl_num, &str);
            if (sl_num > total_len)
                err_msg("err:Invalid Inputs"); // error in case of invalid serial number
            if (str == NULL)
                str = "blank";
            cmd = strtok_r(str, "(", &str); // Tokens of command and variable got separated
            to_low(cmd);                    //convert string to lowercase-> for string comparision ahead
            if (!strcmp(cmd, "read") || !strcmp(cmd, "write"))
                var = strtok_r(str, ")", &str);
            else
                var = "0";

            sdl[sl_num] = (NODE){i, cmd, var}; //Assign values to schedule
        }
        fclose(fp);
    }
    return 1;
}

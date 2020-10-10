/*-----------------------------------
Name : SUBRAT PRASAD PANDA
Roll number : CS1913
Date : 15/12/2019
Program description : Project
Acknowledgements : Research paper link provided in the DFSLAB webpage
------------------------------------*/

/* =================== Introduction =======================
1. All the operations are O(1).
2. Redundancy memory used is n-bits, where 'n' is the size of array.
3. 'w' here is integer hence 32 bits.
4. Hence, this program performs O(1) operation using (n-bit + n*w bit) memory as opposed to (1-bit + n*w bit) operation
   given in research paper. (Linked list model can be adapted from this basic version as given in paper)
5. PRESS EXTRA ENTER TO EXIT FROM PROGRAM
*/

/* =================== Logic =======================
1. n-bit array is created to store the information, if a particular index is written after fill operation or not.
eg: array = [2 3 4 5], bitfiled= [0 0 1 0] means only index 2 is written after a fill operation.
2. If bitfield[index] is zero then fill_value is returned else value from array is returned.

*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct bit{
    unsigned int value : 1; // one bit memory
}BIT;

typedef struct data{
    BIT *bitfield; //Array of BIT to store single bit information of main array
    int *array; // Main array which stores the data
    int fill_value;
}DATA;


int main() {

    //0. Heap memory allocation to data
    DATA fillable_array;
    fillable_array.array = (int*) malloc(sizeof(int)); //1 Byte memory allocation
    fillable_array.fill_value = 0; //default initilization value

    //1. Read first line 
    int var;
    char temp;
    int array_size=1;
    do{
    scanf("%d%c", &var, &temp);
    fillable_array.array[array_size-1] = var; //store input value in the
    array_size = array_size + 1;
    fillable_array.array = (int *)realloc(fillable_array.array, array_size*sizeof(int));
    }while(temp != '\n');

    array_size = array_size - 1; // Correct array size

    fillable_array.bitfield = (BIT *)calloc(array_size, sizeof(BIT)); //Allocation of bitfiled array init with 1
    memset((BIT*)fillable_array.bitfield, 1, array_size* sizeof(BIT));

    
    //2. Write data to fillable array
    char operation;
    int index, val;
    while(1){
        scanf("%c", &operation);
        
        switch (operation)
        {
        case '+': // write (index value)
            scanf("%d %d", &index, &val);
            if((index+1) > array_size){
                array_size = index+1;
                fillable_array.array = (int *)realloc(fillable_array.array, array_size * sizeof(int));
                fillable_array.bitfield = (BIT *)realloc(fillable_array.bitfield, array_size*sizeof(BIT));
            }
            fillable_array.bitfield[index].value = 1;
            fillable_array.array[index] = val;
            
            //print
            for (int i = 0; i < array_size; i++)
            {
                if (fillable_array.bitfield[i].value == 0)
                    printf("%d ", fillable_array.fill_value);
                else
                    printf("%d ", fillable_array.array[i]);
            }
            printf("\n");

            getchar(); // eat away '\n' character
            break;
        
        case '=': // read(index)
            scanf("%d", &index);

            if (fillable_array.bitfield[index].value == 0)
                printf("%d \n", fillable_array.fill_value);
            else
                printf("%d \n", fillable_array.array[index]);

            getchar(); // eat away '\n' character
            break;
        
        case '@': // fill(value)
            scanf("%d", &val);
            fillable_array.fill_value = val;
            memset((BIT *)fillable_array.bitfield, 0, array_size * sizeof(BIT));

            //print
            for (int i = 0; i < array_size; i++){
                if (fillable_array.bitfield[i].value == 0)
                    printf("%d ", fillable_array.fill_value);
                else
                    printf("%d ", fillable_array.array[i]);
            }
            printf("\n");

            getchar();
            break;

        default:
            free(fillable_array.array);
            free(fillable_array.bitfield);
            return 0;
        }

    }
}
#include <stdio.h>
#include "Decoder.h" //include Decoder file

int main(){
    int temp = 0;
    FILE *file = stdin; //Gets file name
    fscanf(file, "%d", &temp); //stores the first int(%d) inside file and stores it at the adress of temp
    printf("%d\n", temp); //print the integer temp
    decipherOneInstruction(&temp); //pass in the address of temp(A pointer to temp)

    //No classes in C, to run decipherOneInstruction(), just run statically
}


/*
Other: 
 - No need to touch the makefile unless you need to make another file, which you shouldn't have to.
 - Put all methods in Decoder
 - .o files are object files. Idk what that means, but they are needed to compile into exe
 - No strings in C. char name[10] essentially makes a list of char with length 10. name is a pointer to the first char. It behaves almost exactly like a string


How to do project according to Jeremy <3:
 - Take an instruction and do a shift on it to get every possible field for an instruction and store it in its own variable:
    - 8 bit opcode
    - 9 bit opcode
    - ...
    - shamt
    - etc
 - Cross reference 8 bit opcode value with 8 bit opcodes. If match, then use only the values you need for 8 bit code. You will have stored
 shamt and other things, but you won't need em(Its inefficient by design)
 - If no 8 bit, then try 9 bit, then 10, etc.
*/
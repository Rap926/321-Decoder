#include "Decoder.h"
#include <stdio.h>
//accepts pointer to a 32bit instruction
//changing instruction directly changes the actual value. It is not a copy like in java
void decipherOneInstruction(int* instruction){
    printf("Decoding %d", *instruction); //get the value being pointed to by instruction(dereference), then print it
    int opcodeInstruction1 = (*instruction >> 26) & 0x3F; // Extract the first 6 bits
    int size6 = sizeof(sixBitInstructions) / sizeof(sixBitInstructions[0]);
    for (int i = 0; i < size6; i++) {
        if (sixBitInstructions[i].opcode == opcodeInstruction) {
            char instruction = sixBitInstructions[i].opcode
            int BR_address = *instruction & 0x03FFFFFF; // Extract the remaining 26 bits
            //should return combined instruction for B type
        }
    }
    int opcodeInstruction2 = (*instruction >> 24) & 0xFF; // Extract the first 8 bits
    int size8 = sizeof(eightBitInstructions) / sizeof(eightBitInstructions[0]);
    for (int i = 0; i < size8; i++) {
        if (eightBitInstructions[i].opcode == opcodeInstruction2) {
            char instruction = eightBitInstructions[i].opcode
            int COND_BR_address = (*instruction >> 6) & 0x3FFFF; // Extract the next 18 bits
            int Rt = (*instruction) & 0x1F; // Extract the last 5 bits
            //should return combined instruction for CB type
        }
    }
    int opcodeInstruction3 = (*instruction >> 22) & 0x3FF; // Extract the first 10 bits
    int size9 = sizeof(tenBitInstructions) / sizeof(tenBitInstructions[0]);
    for (int i = 0; i < size4; i++) {
        if (tenBitInstructions[i].opcode == opcodeInstruction3) {
            char instruction = tenBitInstructions[i].opcode
            int ALU_immediate = (*instruction >> 10) & 0xFFF; // Extract the next 12 bits
            int Rn = (*instruction >> 5) & 0x1F; // Extract the next 5 bits
            int Rd = (*instruction) & 0x1F; // Extract the last 5 bits
            //should return combined instruction for I type
        }
    }
    int opcodeInstruction4 = (*instruction >> 21) & 0x7FF; // Extract the first 11 bits
    int size11 = sizeof(elevenBitInstructions) / sizeof(elevenBitInstructions[0]);
    for (int i = 0; i < size11; i++) {
        if (elevenBitInstructions[i].opcode == opcodeInstruction4) {
            char instruction = elevenBitInstructions[i].opcode

        }
    }
    int rTypeSize = sizeof(rTypeInstructions) / sizeof(rTypeInstructions[0]);
    for (int i = 0; i < rTypeSize; i++) {
        if (rTypeInstructions[i] == opcodeInstruction4) {
            int Rm = (*instruction >> 16) & 0x1F; // Extract the next 5 bits
            int shamt = (*instruction >> 10) & 0x3F; // Extract the next 6 bits
            int Rn = (*instruction >> 5) & 0x1F; // Extract the next 5 bits
            int Rd = (*instruction) & 0x1F; // Extract the last 5 bits
        }
    }
    int dTypeSize = sizeof(dTypeInstructions) / sizeof(dTypeInstructions[0]);
    for (int i = 0; i < dTypeSize; i++) {
        if (dTypeInstructions[i] == opcodeInstruction4) {
            int DT_address = (*instruction >> 12) & 0x1FF; // Extract the next 9 bits
            int op = 00; //ops are 00 in legv8 I think
            int Rn = (*instruction >> 5) & 0x1F; // Extract the next 5 bits
            int Rt = (*instruction) & 0x1F; // Extract the last 5 bits
        }
    }
    //should return combined instruction for R or D type

    //this function should seperate instruction into different possible fields, then figure out what instruction type it is.
    //It will then call the corresponding function
}

//will probably want a function that accepts the fields for the instruction type for all types
char* bTypeToEnglish(int* opcodeInstruction, int* BR_address){ //will accept parameters needed for 8 bit opcode instructions
    int size6 = sizeof(sixBitInstructions) / sizeof(sixBitInstructions[0]);
    for (int i = 0; i < size6; i++) {
        if (sixBitInstructions[0].opcode == opcodeInstruction) {
            return sixBitInstructions[i].name;
        }
    }
    int BR_address_integer = *BR_address;
    char result[100];
    sprintf(result, "Instruction%d", BR_address); //B: label?

    return result;
        //returns instruction in string form for 8 bit instruction
}

char* cbTypeToEnglish(int* opcodeInstruction, int* COND_BR_address, int* Rt){ //will accept parameters needed for 8 bit opcode instructions
    int size6 = sizeof(sixBitInstructions) / sizeof(sixBitInstructions[0]);
    for (int i = 0; i < size6; i++) {
        if (sixBitInstructions[0].opcode == opcodeInstruction) {
            return sixBitInstructions[i].name;
        }
    }
    int COND_BR_address_integer = *COND_BR_address;
    int Rt_integer = *Rt;
    char result[100];
    sprintf(result, "Instruction: %dX%d", COND_BR_address_integer, Rt_integer); //CBZ: 2,x0 example

    return result;
    //returns instruction in string form for 8 bit instruction
}

char* iTypeToEnglish(int* opcodeInstruction, int* ALU_immediate, int* Rn, int* Rd){ //will accept parameters needed for 8 bit opcode instructions
    int size6 = sizeof(sixBitInstructions) / sizeof(sixBitInstructions[0]);
    for (int i = 0; i < size6; i++) {
        if (sixBitInstructions[0].opcode == opcodeInstruction) {
            return sixBitInstructions[i].name;
        }
    }
    int ALU_immediate_integer = *ALU_immediate;
    int Rn_integer = *Rn;
    int Rd_integer = *Rd;
    char result[100];
    sprintf(result, "Instruction: X%d,X%d,#%d", Rn_integer, Rd_integer, ALU_immediate_integer); //ADDI: x0,x1,#2 example

    return result;
    //returns instruction in string form for 8 bit instruction
}

char* rTypeToEnglish(int* opcodeInstruction, int* Rm, int* shamt, int* Rn, int* Rd){ //will accept parameters needed for 8 bit opcode instructions
    int size6 = sizeof(sixBitInstructions) / sizeof(sixBitInstructions[0]);
    for (int i = 0; i < size6; i++) {
        if (sixBitInstructions[0].opcode == opcodeInstruction) {
            return sixBitInstructions[i].name;
        }
    }
    int Rm_integer = *Rm;
    int shamt_integer = *shamt;
    int Rn_integer = *Rn;
    int Rd_integer = *Rd;
    char result[100];
    sprintf(result, "Instruction: X%d,X%d,X%d", Rn_integer, Rd_integer, ALU_immediate_integer); //ADD: x0,x1,x2 example

    return result;
    //returns instruction in string form for 8 bit instruction
}

char* dTypeToEnglish(int* opcodeInstruction, int* DT_address, int* Rn, int* Rd){ //will accept parameters needed for 8 bit opcode instructions
    int size6 = sizeof(sixBitInstructions) / sizeof(sixBitInstructions[0]);
    for (int i = 0; i < size6; i++) {
        if (sixBitInstructions[0].opcode == opcodeInstruction) {
            return sixBitInstructions[i].name;
        }
    }
    int DT_address_integer = *DT_address;
    int Rn_integer = *Rn;
    int Rd_integer = *Rd;
    char result[100];
    sprintf(result, "Instruction: X%d,[X%d,#%d]", Rn_integer, Rd_integer, DT_address_integer); //LDUR: x0,[SP,#2] example
    //returns instruction in string form for 8 bit instruction
}

instruction_t sixBitInstructions[] = {
    { "B",       B_inst,      0b000101      },
    { "BL",      BL_inst,     0b100101      }
};
instruction_t eightBitInstructions[] = {
    { "CBNZ",    CBNZ_inst,   0b10110101    },
    { "CBZ",     CBZ_inst,    0b10110100    },
    { "B.cond",  B_cond_inst, 0b01010100    }
};
instruction_t tenBitInstructions[] = {
    { "ADDI",    ADDI_inst,   0b1001000100  },
    { "ADDIS",   ADDIS_inst,  0b1011000100  },
    { "ANDI",    ANDI_inst,   0b1001001000  },
    { "ANDIS",   ANDIS_inst,  0b1111001000  },
    { "EORI",    EORI_inst,   0b1101001000  },
    { "ORRI",    ORRI_inst,   0b1011001000  },
    { "SUBI",    SUBI_inst,   0b1101000100  },
    { "SUBIS",   SUBIS_inst,  0b1111000100  }
};
instruction_t elevenBitInstructions[] = {
    { "ADD",     ADD_inst,    0b10001011000 },
    { "ADDS",    ADDS_inst,   0b10101011000 },
    { "AND",     AND_inst,    0b10001010000 },
    { "ANDS",    ANDS_inst,   0b1110101000  },
    { "BR",      BR_inst,     0b11010110000 },
    { "DUMP",    DUMP_inst,   0b11111111110 },
    { "EOR",     EOR_inst,    0b11001010000 },
    { "FADDD",   FADDD_inst,  0b00011110011 },
    { "FADDS",   FADDS_inst,  0b00011110001 },
    { "FCMPD",   FCMPD_inst,  0b00011110011 },
    { "FCMPS",   FCMPS_inst,  0b00011110001 },
    { "FDIVD",   FDIVD_inst,  0b00011110011 },
    { "FDIVS",   FDIVS_inst,  0b00011110001 },
    { "FMULD",   FMULD_inst,  0b00011110011 },
    { "FMULS",   FMULS_inst,  0b00011110001 },
    { "FSUBD",   FSUBD_inst,  0b00011110011 },
    { "FSUBS",   FSUBS_inst,  0b00011110001 },
    { "HALT",    HALT_inst,   0b11111111111 },
    { "LDUR",    LDUR_inst,   0b11111000010 },
    { "LDURB",   LDURB_inst,  0b00111000010 },
    { "LDURD",   LDURD_inst,  0b11111100010 },
    { "LDURH",   LDURH_inst,  0b01111000010 },
    { "LDURS",   LDURS_inst,  0b10111100010 },
    { "LDURSW",  LDURSW_inst, 0b10111000100 },
    { "LSL",     LSL_inst,    0b11010011011 },
    { "LSR",     LSR_inst,    0b11010011010 },
    { "MUL",     MUL_inst,    0b10011011000 },
    { "ORR",     ORR_inst,    0b10101010000 },
    { "PRNL",    PRNL_inst,   0b11111111100 },
    { "PRNT",    PRNT_inst,   0b11111111101 },
    { "SDIV",    SDIV_inst,   0b10011010110 },
    { "SMULH",   SMULH_inst,  0b10011011010 },
    { "STUR",    STUR_inst,   0b11111000000 },
    { "STURB",   STURB_inst,  0b00111000000 },
    { "STURD",   STURD_inst,  0b11111100000 },
    { "STURH",   STURH_inst,  0b01111000000 },
    { "STURS",   STURS_inst,  0b10111100000 },
    { "STURSW",  STURW_inst,  0b10111000000 },
    { "SUB",     SUB_inst,    0b11001011000 },
    { "SUBS",    SUBS_inst,   0b11101011000 },
    { "UDIV",    UDIV_inst,   0b10011010110 },
    { "UMULH",   UMULH_inst,  0b10011011110 }
};
int rTypeInstructions[] = {
    0b10001011000, //ADD
    0b10101011000, //ADDS
    0b10001010000, //AND
    0b1110101000,  //ANDS
    0b11010110000, //BR
    0b11111111110, //DUMP
    0b11001010000, //EOR
    0b00011110011, //FADDD
    0b00011110001, //FADDS
    0b00011110011, //FCMPD
    0b00011110001, //FCMPS
    0b00011110011, //FDIVD
    0b00011110001, //FDIVS
    0b00011110011, //FMULD
    0b00011110001, //FMULS
    0b00011110011, //FSUBD
    0b00011110001, //FSUBS
    0b11111111111, //HALT
    0b11010011011, //LSL
    0b11010011010, //LSR
    0b10011011000, //MUL
    0b10101010000, //ORR
    0b11111111100, //PRNL
    0b11111111101, //PRNT
    0b10011010110, //SDIV
    0b10011011010, //SMULH
    0b11001011000, //SUB
    0b11101011000, //SUBS
    0b10011010110, //UDIV
    0b10011011110,  //UMULH
    0b10111100010, //LDURS
    0b10111100000 //STURS
}
int dTypeInstructions[] = {
    0b11111000010, //LDUR
    0b00111000010, //LDURB
    0b11111100010, //LDURD
    0b01111000010, //LDURH
    0b10111000100, //LDURSW
    0b11111000000, //STUR
    0b00111000000, //STURB
    0b11111100000, //STURD
    0b01111000000, //STURH
    0b10111000000 //STURSW
}

/*
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#include <iostream>

template<typename C, typename T>
bool contains(C&& c, T e) {
    return std::find(std::begin(c), std::end(c), e) != std::end(c);
};

template<typename C, typename T>
void check(C&& c, T e) {
    std::cout << e << (contains(c,e) ? "" : " not") <<  " found\n";
}

int main() {
    int a[] = { 10, 15, 20 };
    std::array<int, 3> b { 10, 10, 10 };
    std::vector<int> v { 10, 20, 30 };
    std::string s { "Hello, Stack Overflow" };

    check(a, 10);
    check(b, 15);
    check(v, 20);
    check(s, 'Z');

    return 0;
}
Code for contains https://stackoverflow.com/questions/19215027/check-if-element-found-in-array-c
*/
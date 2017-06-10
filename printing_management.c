// printing_management.c
#include "printing_management.h"

  static char *instructions[256] = {
    "NOP\n",
    "AJMP\t0x%4.4X\n",
    "LJMP\t0x%4.4X\n",
    "RR\t\tA\n",
    "INC\t\tA\n",
    "INC\t\t0x%X2.2\n",
    "INC\t\t@R0\n",
    "INC\t\t@R1\n",
    "INC\t\tR0\n",
    "INC\t\tR1\n",
    "INC\t\tR2\n",
    "INC\t\tR3\n",
    "INC\t\tR4\n",
    "INC\t\tR5\n",
    "INC\t\tR6\n",
    "INC\t\tR7\n",
    "JBC\t\t0x%2.2X,\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "LCALL\t0x%4.4X\n",
    "RRC\t\tA\n",
    "DEC\t\tA\n",
    "DEC\t\t0x%2.2X\n",
    "DEC\t\t@R0\n",
    "DEC\t\t@R1\n",
    "DEC\t\tR0\n",
    "DEC\t\tR1\n",
    "DEC\t\tR2\n",
    "DEC\t\tR3\n",
    "DEC\t\tR4\n",
    "DEC\t\tR5\n",
    "DEC\t\tR6\n",
    "DEC\t\tR7\n",
    "JB\t\t0x%2.2X,\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "RET\n",
    "RL\t\tA\n",
    "ADD\t\tA,\t0x%2.2X\n",
    "ADD\t\tA,\t0x%2.2X\n",
    "ADD\t\tA,\t@R0\n",
    "ADD\t\tA,\t@R1\n",
    "ADD\t\tA,\tR0\n",
    "ADD\t\tA,\tR1\n",
    "ADD\t\tA,\tR2\n",
    "ADD\t\tA,\tR3\n",
    "ADD\t\tA,\tR4\n",
    "ADD\t\tA,\tR5\n",
    "ADD\t\tA,\tR6\n",
    "ADD\t\tA,\tR7\n",
    "JNB\t\t0x%2.2X,\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "RETI\n",
    "RLC\t\tA\n",
    "ADDC\tA,\t0x%2.2X\n",
    "ADDC\tA,\t0x%2.2X\n",
    "ADDC\tA,\t@R0\n",
    "ADDC\tA,\t@R1\n",
    "ADDC\tA,\tR0\n",
    "ADDC\tA,\tR1\n",
    "ADDC\tA,\tR2\n",
    "ADDC\tA,\tR3\n",
    "ADDC\tA,\tR4\n",
    "ADDC\tA,\tR5\n",
    "ADDC\tA,\tR6\n",
    "ADDC\tA,\tR7\n",
    "JC\t\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "ORL\t\t0x%2.2X,\tA\n",
    "ORL\t\t0x%2.2X,\t0x%2.2X\n",
    "ORL\t\tA,\t0x%2.2X\n",
    "ORL\t\tA,\t0x%2.2X\n",
    "ORL\t\tA,\t@R0\n",
    "ORL\t\tA,\t@R1\n",
    "ORL\t\tA,\tR0\n",
    "ORL\t\tA,\tR1\n",
    "ORL\t\tA,\tR2\n",
    "ORL\t\tA,\tR3\n",
    "ORL\t\tA,\tR4\n",
    "ORL\t\tA,\tR5\n",
    "ORL\t\tA,\tR6\n",
    "ORL\t\tA,\tR7\n",
    "JNC\t\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "ANL\t\t0x%2.2X,\tA\n",
    "ANL\t\t0x%2.2X,\t0x%2.2X\n",
    "ANL\t\tA,\t0x%2.2X\n",
    "ANL\t\tA,\t0x%2.2X\n",
    "ANL\t\tA,\t@R0\n",
    "ANL\t\tA,\t@R1\n",
    "ANL\t\tA,\tR0\n",
    "ANL\t\tA,\tR1\n",
    "ANL\t\tA,\tR2\n",
    "ANL\t\tA,\tR3\n",
    "ANL\t\tA,\tR4\n",
    "ANL\t\tA,\tR5\n",
    "ANL\t\tA,\tR6\n",
    "ANL\t\tA,\tR7\n",
    "JZ\t\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "XRL\t\t0x%2.2X,\tA\n",
    "XRL\t\t0x%2.2X,\t0x%2.2X\n",
    "XRL\t\tA,\t0x%2.2X\n",
    "XRL\t\tA,\t0x%2.2X\n",
    "XRL\t\tA,\t@R0\n",
    "XRL\t\tA,\t@R1\n",
    "XRL\t\tA,\tR0\n",
    "XRL\t\tA,\tR1\n",
    "XRL\t\tA,\tR2\n",
    "XRL\t\tA,\tR3\n",
    "XRL\t\tA,\tR4\n",
    "XRL\t\tA,\tR5\n",
    "XRL\t\tA,\tR6\n",
    "XRL\t\tA,\tR7\n",
    "JNZ\t\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "ORL\t\tC,\t0x%2.2X\n",
    "JMP\t\t@A+DPTR\n",
    "MOV\t\tA,\t0x%2.2X\n",
    "MOV\t\t0x%2.2X,\t0x%2.2X\n",
    "MOV\t\t@R0,\t0x%2.2X\n",
    "MOV\t\t@R1,\t0x%2.2X\n",
    "MOV\t\tR0,\t0x%2.2X\n",
    "MOV\t\tR1,\t0x%2.2X\n",
    "MOV\t\tR2,\t0x%2.2X\n",
    "MOV\t\tR3,\t0x%2.2X\n",
    "MOV\t\tR4,\t0x%2.2X\n",
    "MOV\t\tR5,\t0x%2.2X\n",
    "MOV\t\tR6,\t0x%2.2X\n",
    "MOV\t\tR7,\t0x%2.2X\n",
    "SJMP\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "ANL\t\tC,\t0x%2.2X\n",
    "MOVC\tA,\t@A+PC\n",
    "DIV\t\tA,\tB\n",
    "MOV\t\t0x%2.2X,\t0x%2.2X\n",
    "MOV\t\t0x%2.2X,\t@R0\n",
    "MOV\t\t0x%2.2X,\t@R1\n",
    "MOV\t\t0x%2.2X,\tR0\n",
    "MOV\t\t0x%2.2X,\tR1\n",
    "MOV\t\t0x%2.2X,\tR2\n",
    "MOV\t\t0x%2.2X,\tR3\n",
    "MOV\t\t0x%2.2X,\tR4\n",
    "MOV\t\t0x%2.2X,\tR5\n",
    "MOV\t\t0x%2.2X,\tR6\n",
    "MOV\t\t0x%2.2X,\tR7\n",
    "MOV\t\tDPTR,\t0x%4.4X\n",
    "ACALL\t0x%4.4X\n",
    "MOV\t\t0x%2.2X,\tC\n",
    "MOVC\tA,\t@A+DPTR\n",
    "SUBB\tA,\t0x%2.2X\n",
    "SUBB\tA,\t0x%2.2X\n",
    "SUBB\tA,\t@R0\n",
    "SUBB\tA,\t@R1\n",
    "SUBB\tA,\tR0\n",
    "SUBB\tA,\tR1\n",
    "SUBB\tA,\tR2\n",
    "SUBB\tA,\tR3\n",
    "SUBB\tA,\tR4\n",
    "SUBB\tA,\tR5\n",
    "SUBB\tA,\tR6\n",
    "SUBB\tA,\tR7\n",
    "ORL\t\tC,\t/0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "MOV\t\tC,\t0x%2.2X\n",
    "INC\t\tDPTR\n",
    "MUL\t\tA,\tB\n",
    "RESERVED\n",
    "MOV\t\t@R0,\t0x%2.2X\n",
    "MOV\t\t@R1,\t0x%2.2X\n",
    "MOV\t\tR0,\t0x%2.2X\n",
    "MOV\t\tR1,\t0x%2.2X\n",
    "MOV\t\tR2,\t0x%2.2X\n",
    "MOV\t\tR3,\t0x%2.2X\n",
    "MOV\t\tR4,\t0x%2.2X\n",
    "MOV\t\tR5,\t0x%2.2X\n",
    "MOV\t\tR6,\t0x%2.2X\n",
    "MOV\t\tR7,\t0x%2.2X\n",
    "ANL\t\tC,\t/0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "CPL\t\t0x%2.2X\n",
    "CPL\t\tC\n",
    "CJNE\tA,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE\tA,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE\t@R0,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE\t@R1,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R0,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R1,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R2,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R3,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R4,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R5,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R6,\t0x%2.2X,\t0x%2.2X\n",
    "CJNE R7,\t0x%2.2X,\t0x%2.2X\n",
    "PUSH\t0x%2.2X\n",
    "AJMP\t0x%4.4X\n",
    "CLR\t\t0x%2.2X\n",
    "CLR\t\tC\n",
    "SWAP\tA\n",
    "XCH\t\tA,\t0x%2.2X\n",
    "XCH\t\tA,\t@R0\n",
    "XCH\t\tA,\t@R1\n",
    "XCH\t\tA,\tR0\n",
    "XCH\t\tA,\tR1\n",
    "XCH\t\tA,\tR2\n",
    "XCH\t\tA,\tR3\n",
    "XCH\t\tA,\tR4\n",
    "XCH\t\tA,\tR5\n",
    "XCH\t\tA,\tR6\n",
    "XCH\t\tA,\tR7\n",
    "POP\t\t0x%2.2X\n",
    "ACALL\t0x%4.4X\n",
    "SETB\t0x%2.2X\n",
    "SETB\tC\n",
    "DA\t\tA\n",
    "DJNZ\t0x%2.2X,\t0x%2.2X\n",
    "XCHD\tA,\t@R0\n",
    "XCHD\tA,\t@R1\n",
    "DJNZ\tR0,\t0x%2.2X\n",
    "DJNZ\tR1,\t0x%2.2X\n",
    "DJNZ\tR2,\t0x%2.2X\n",
    "DJNZ\tR3,\t0x%2.2X\n",
    "DJNZ\tR4,\t0x%2.2X\n",
    "DJNZ\tR5,\t0x%2.2X\n",
    "DJNZ\tR6,\t0x%2.2X\n",
    "DJNZ\tR7,\t0x%2.2X\n",
    "MOVX\tA,\t@DPTR\n",
    "AJMP\t0x%4.4X\n",
    "MOVX\tA,\t@R0\n",
    "MOVX\tA,\t@R1\n",
    "CLR\t\tA\n",
    "MOV\t\tA,\t0x%2.2X\n",
    "MOV\t\tA,\t@R0\n",
    "MOV\t\tA,\t@R1\n",
    "MOV\t\tA,\tR0\n",
    "MOV\t\tA,\tR1\n",
    "MOV\t\tA,\tR2\n",
    "MOV\t\tA,\tR3\n",
    "MOV\t\tA,\tR4\n",
    "MOV\t\tA,\tR5\n",
    "MOV\t\tA,\tR6\n",
    "MOV\t\tA,\tR7\n",
    "MOVX\t@DPTR,\tA\n",
    "ACALL\t0x%4.4X\n",
    "MOVX\t@R0,\tA\n",
    "MOVX\t@R1,\tA\n",
    "CPL\t\tA\n",
    "MOV\t\t0x%2.2X,\tA\n",
    "MOV\t\t@R0,\tA\n",
    "MOV\t\t@R1,\tA\n",
    "MOV\t\tR0,\tA\n",
    "MOV\t\tR1,\tA\n",
    "MOV\t\tR2,\tA\n",
    "MOV\t\tR3,\tA\n",
    "MOV\t\tR4,\tA\n",
    "MOV\t\tR5,\tA\n",
    "MOV\t\tR6,\tA\n",
    "MOV\t\tR7,\tA\n"
 };

/*
extern record *print_record(record *record) {
  printf("size: %u, address: 0x%4.4X, ", record->size, record->address);
 
  switch (record->mode) {
    case DATA: printf("record mode: DATA"); break;
    case END: printf("record mode: END");
  }
 
  if (record->size) {
    printf("\nbytecode: ");
    for (unsigned short int j = 0; j < record->size; j++)
      printf("%.2X", record->bytecode[j]);
  }
 
  printf("\nchecksum: 0x%X\n\n", record->checksum);
 
  return destroy_record(record);
}
*/

unsigned short int addr11_to_addr16(record *record) {
  return ((record->address + 2) & 0xF800) + ((record->bytecode[0] & 0x00E0) << 3) + record->bytecode[1];
}

extern void print_instruction(record *records) {
  unsigned char *bytecode = records->bytecode, instruction;
  instruction = bytecode[0];
  printf("0x%4.4X\t", records->address);

  for (unsigned short int i = 0; i < 4; i++) {
    if (i < records->size) printf("%2.2X ", records->bytecode[i]);
    else printf("   ");
  }

  switch (instruction_types[(unsigned char)records->bytecode[0]]) {
    case ONE_BYTE_INSTRUCTION:
      printf(instructions[instruction]);
      break;
    case ADDR_11:
      printf(instructions[instruction], addr11_to_addr16(records));
      break;
    case DIRECT:
    case IMMEDIATE:
    case OFFSET:
    case BIT:
    case NOT_BIT:
      printf(instructions[instruction], bytecode[1]);
      break;
    case ADDR_16:
    case IMMEDIATE_16:
      printf(instructions[instruction], bytes_to_word(bytecode[1], bytecode[2]));
      break;
    case BIT_OFFSET:
    case DIRECT_IMMEDIATE:
    case DIRECT_DIRECT:
    case IMMEDIATE_OFFSET:
    case DIRECT_OFFSET:
      printf(instructions[instruction], bytecode[1], bytecode[2]);
  }
}

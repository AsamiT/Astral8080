/* QD8080
Another pointless and silly attempt at emulating an 8080 processor system
Version 0.0 Alpha 1
Asami Tachibana

File: internals.h
"Header file containing the data we need to execute 8080 code in the emulation--opcodes and the like."
28 Sept. 2017

*/

typedef struct ConditionCodes {
  uint8_t z:1;
  uint8_t s:1;
  uint8_t p:1;
  uint8_t cy:1;
  uint8_t ac:1;
  uint8_t pad:3;
} ConditionCodes;

typedef struct State8080 {
  uint8_t   a;
  uint8_t   b;
  uint8_t   c;
  uint8_t   d;
  uint8_t   e;
  uint8_t   h;
  uint8_t   l;
  uint16_t  sp;
  uint16_t  pc;
  uint8_t *memory;
  struct ConditionCodes cc;
  uint8_t int_enable;
} State8080;

void UnimplementedInstruction(State8080* state)
{
  printf("Error: Unimplemented instruction\n");
  exit(1);
}

void Emulate8080_Op(State8080* state)
{
  unsigned char *opcode = &state->memory[state->pc];

  switch(*opcode)
  {
    case 0x00: break;
    case 0x01:
      state->c = opcode[1];
      state->b = opcode[2];
      state->pc +=2;
      break;
    case 0x40: state->b = state->b; break; //MOV B,B
    case 0x41: state->b = state->c; break; //MOV B,C
    case 0x42: state->b = state->d; break; //MOV B,D
    case 0x43: state->b = state->e; break;
    //we'll have to implement the full op-codes later, but I'm sure Alan could help with making the code not "line-for-line" like Emu101 wants it to be...There are seven groups and 255 opcodes (there abouts), I should really look into an easier way to execute this code without having to bother with opcodes.
  }
  state->pc+=1;
}

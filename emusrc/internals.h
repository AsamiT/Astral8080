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
  
  /*At the present time, opcodes are not fully implemented. It requires a bit of logical writing,
  and the developer is only so wise in discrete logic. She is also a very depressed and tired girl.
  Note to self: Talk to Alan about the logic in this section to see if I'm actually doing something or just creating dummy code... */

  switch(*opcode)
  {
    default: UnimplementedInstruction(state); break;
    case 0x00: break; //NOP
    case 0x01: //LXI  B,word
      state->c = opcode[1];
      state->b = opcode[2];
      state->pc +=2;
      break;

    //MOV B,*
    case 0x40: state->b = state->b; break; //MOV B,B
    case 0x41: state->b = state->c; break; //MOV B,C
    case 0x42: state->b = state->d; break; //MOV B,D
    case 0x43: state->b = state->e; break; //MOV B,E
    case 0x44: state->b = state->h; break; //MOV B,H
    case 0x45: state->b = state->l; break; //MOV B,L
    case 0x46: state->b = state->m; break; //MOV B,M
    case 0x47: state->b = state->a; break; //MOV B,A
    //MOV C,*
    case 0x48: state->c = state->b; break; //MOV C,B
    case 0x49: state->c = state->c; break; //MOV C,C
    case 0x4A: state->c = state->d; break; //MOV C,D
    case 0x4B: state->c = state->e; break; //MOV C,E
    case 0x4C: state->c = state->h; break; //MOV C,H
    case 0x4D: state->c = state->l; break; //MOV C,L
    case 0x4E: state->c = state->m; break; //MOV C,M
    case 0x4F: state->c = state->a; break; //MOV C,A
	//MOV D,*
	case 0x50: state->d = state->b; break; //MOV D,B
    case 0x51: state->d = state->c; break; //MOV D,C
    case 0x52: state->d = state->d; break; //MOV D,D
    case 0x53: state->d = state->e; break; //MOV D,E
    case 0x54: state->d = state->h; break; //MOV D,H
    case 0x55: state->d = state->l; break; //MOV D,L
    case 0x56: state->d = state->m; break; //MOV D,M
    case 0x57: state->d = state->a; break; //MOV D,A
	//MOV E,*
	case 0x58: state->e = state->b; break; //MOV E,B
    case 0x59: state->e = state->c; break; //MOV E,C
    case 0x5A: state->e = state->d; break; //MOV E,D
    case 0x5B: state->e = state->e; break; //MOV E,E
    case 0x5C: state->e = state->h; break; //MOV E,H
    case 0x5D: state->e = state->l; break; //MOV E,L
    case 0x5E: state->e = state->m; break; //MOV E,M
    case 0x5F: state->e = state->a; break; //MOV E,A
	//MOV H,*
	case 0x60: state->h = state->b; break; //MOV H,B
    case 0x61: state->h = state->c; break; //MOV H,C
    case 0x62: state->h = state->d; break; //MOV H,D
    case 0x63: state->h = state->e; break; //MOV H,E
    case 0x64: state->h = state->h; break; //MOV H,H
    case 0x65: state->h = state->l; break; //MOV H,L
    case 0x66: state->h = state->m; break; //MOV H,M
    case 0x67: state->h = state->a; break; //MOV H,A	
	//MOV L,*
	case 0x68: state->l = state->b; break; //MOV L,B
    case 0x69: state->l = state->c; break; //MOV L,C
    case 0x6A: state->l = state->d; break; //MOV L,D
    case 0x6B: state->l = state->e; break; //MOV L,E
    case 0x6C: state->l = state->h; break; //MOV L,H
    case 0x6D: state->l = state->l; break; //MOV L,L
    case 0x6E: state->l = state->m; break; //MOV L,M
    case 0x6F: state->l = state->a; break; //MOV L,A
	//MOV M,*
	case 0x70: state->m = state->b; break; //MOV M,B
    case 0x71: state->m = state->c; break; //MOV M,C
    case 0x72: state->m = state->d; break; //MOV M,D
    case 0x73: state->m = state->e; break; //MOV M,E
    case 0x74: state->m = state->h; break; //MOV M,H
    case 0x75: state->m = state->l; break; //MOV M,L
    case 0x76: break; //because this is all HLT does
    case 0x77: state->m = state->a; break; //MOV M,A
	//MOV A,*
	case 0x78: state->a = state->b; break; //MOV A,B
	case 0x79: state->a = state->c; break; //MOV A,C
	case 0x7A: state->a = state->d; break; //MOV A,D
	case 0x7B: state->a = state->e; break; //MOV A,E
	case 0x7C: state->a = state->h; break; //MOV A,H
	case 0x7D: state->a = state->l; break; //MOV A,L
	case 0x7E: state->a = state->m; break; //MOV A,M
	case 0x7F: state->a = state->a; break; //MOV A,A
	
    //this is where we're going to do ADD functions
    case 0x80: //ADD B, which is going to explain our logic; all the other ADD functions will not use this kind of feature.
	{
		//we're going to do the math with high precision in order to capture the result
		uint16_t answer = (uint16_t) state->a + (uint6_t) state ->b;

		//zero flag: if result is zero, set flag to zero, else, clear the flag.
		if ((answer & 0x80) == 0)
			state->cc.z = 1;
		else
			state->cc.z = 0;

		/Carry flag
		if (answer > 0xff)
            state->cc.cy = 1;
		else
            state->cc.cy = 0;

    //Parity by subroutine
    state->cc.p = Parity(answer & 0xff);
    state->a = answer & 0xff;
	}
	
	case 0x81: //ADD C
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->c;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x81) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;
	}
	
	case 0x82: //ADD D
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->d;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x82) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;		
	}
	
	case 0x83: //ADD E
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->e;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x83) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;				
	}
	case 0x84: //ADD H
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->h;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x84) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;				
	}
	
	case 0x85: //ADD L 
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->l;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x85) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;				
	}	
	case 0x86: //ADD M
	{
        uint16_t offset = (state->h<<8) | (state->l);    
        uint16_t answer = (uint16_t) state->a + state->memory[offset];    
        state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x86) != 0);    
        state->cc.cy = (answer > 0xff);    
        state->cc.p = Parity(answer&0xff);    
        state->a = answer & 0xff; 		
	}	
	case 0x87: //ADD A
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->a;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x87) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;				
	}
	case 0x88: //ADC B
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->b + state->cc.cy;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x88) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;			
	}
	
	case 0x89: //ADC C
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->c + state->cc.cy;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x89) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;			
	}	
	case 0x8A: //ADC D
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->d + state->cc.cy;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x8A) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;			
	}	
	case 0x8B: //ADC E
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->e + state->cc.cy;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x8B) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;			
	}	
	case 0x8C: //ADC H
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->h + state->cc.cy;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x8C) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;			
	}
	case 0x8D: //ADC L
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->l + state->cc.cy;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x8D) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;			
	}	
	case 0x8E: //ADC M
	{
			//unimplemented because this is actually memory add, which requires more buggery.
	}	
	case 0x8F: //ADC A
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) state->a + state->cc.cy;
		state->cc.z = ((answer & 0xff) == 0);    
        state->cc.s = ((answer & 0x8F) != 0);    
		state->cc.cy = (answer > 0xff);    
		state->cc.p = Parity(answer&0xff);    
		state->a = answer & 0xff;			
	}
	
	case 0xC2: //JNZ
	{
		if (0 == state->cc.z)
			state->pc = (opcode[2] << 8) | opcode[1];
		else
			state->pc +=2;
		break;
	}
	case 0xC3: //JMP
	{
		state->pc = (opcode[2] << 8) | opcode[1];
		break;
	}
	case 0xC6: //ADI byte
	{
		uint16_t answer = (uint16_t) state->a + (uint16_t) opcode[1];
		state->cc.z = ((answer & 0xff) == 0);
		state->cc.s = ((answer & 0xC6) != 0);
		state->cc.cy = (answer > 0xff);
		state->cc.p = Parity(answer & 0xff);
		state->a = answer & 0xff;
	}
  }
  state->pc+=1;
}

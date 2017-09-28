/* QD8080
Another pointless and silly attempt at emulating an 8080 processor system
Version 0.0 Alpha 1
Asami Tachibana

File: main.c
"Heart and soul of our program."
28 Sept. 2017

*/

#include <stdlib.h>
#include <stdio.h>
#include "disassembler_functions.h"

int main(int argc, char**argv)
{
  FILE *f = fopen(argv[1], "rb");
  if (f==NULL)
  {
    printf("Error: Couldn't open %s\n", argv[1]);
    exit(1);
  }
  //Bring file into memory
  fseek(f, 0L, SEEK_END);
  int fsize = ftell(f);
  fseek(f, 0L, SEEK_SET);

  unsigned char *buffer=malloc(fsize);

  fread(buffer, fsize, 1, f);
  fclose(f);

  int pc = 0;

  while (pc < fsize)
  {
    pc += DA8080_Op(buffer, pc);
  }
}

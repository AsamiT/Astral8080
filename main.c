/* Astral8080
Another pointless and silly attempt at emulating an 8080 processor system
Version 0.0 Alpha 1
Asami Tachibana */

int main()
{
  Counter=InterruptPeriod;
  PC=InitialPC;
  while(CPUIsRunning)
  {
    OpCode=Memory[PC++];
    Counter-=Cycles[Opcode];

    switch(Opcode)
    {
      case Opcode1:
      case Opcode2:
    }
    if(Counter <= 0)
    {
      /* Check for interrupts and do other cyclic tasks here */
      Counter+=InterruptPeriod;
      if(ExitRequired) break;
    }
  }
  return 0;
}

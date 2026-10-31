/* FUN_8000de40
 * image   boot (boot), base 0x80000480
 * address 0x8000de40  body 0x8000de40..0x8000de77  size 59 B
 * sha256  dedea0878e66edbfdfd3005352e8d2aff6f59399883bb7a0644c2ef7eb8eba98
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
char * FUN_8000de40(char *param_1,char param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == param_2) {
      return param_1;
    }
    param_1 = param_1 + 1;
    if (cVar1 == '\0') break;
    cVar1 = *param_1;
  }
  return (char *)0x0;
}

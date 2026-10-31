/* FUN_8000de40
 * image   boot (boot), base 0x80000480
 * address 0x8000de40  body 0x8000de40..0x8000de77  size 59 B
 * body sha256 94d3119cacfafee6eab613e2b6e99804e225165961794deb47827e6fb85e08a1
 * provider record sha256 bdc4bfbf08a6c7c2d30e419258c80994a5e1d670fb2356a8f9b083d156c3e284
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

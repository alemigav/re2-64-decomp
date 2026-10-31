/* FUN_80053994
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053994  body 0x80053994..0x8005399f  size 15 B
 * sha256  e145db95c67bb4a8e2fc3c56779842d0c22bfafe70b6723ee52036b02cee77f7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80053994(uint param_1)

{
  return (param_1 & 0xff) + 0x3f;
}

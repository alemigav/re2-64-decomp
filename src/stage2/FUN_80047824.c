/* FUN_80047824
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047824  body 0x80047824..0x80047853  size 51 B
 * sha256  caeff5da8cd93e167d8eb1118dc0ee67af21594ab5a53eecb327d965ea44cba8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047824(int param_1,char param_2,char param_3,char param_4,char param_5)

{
  *(char *)(param_1 + 0x10) = param_2;
  *(char *)(param_1 + 8) = param_2;
  *(char *)(param_1 + 0x20) = param_2 + param_4;
  *(char *)(param_1 + 0x18) = param_2 + param_4;
  *(char *)(param_1 + 0x19) = param_3;
  *(char *)(param_1 + 9) = param_3;
  *(char *)(param_1 + 0x21) = param_3 + param_5;
  *(char *)(param_1 + 0x11) = param_3 + param_5;
  return;
}

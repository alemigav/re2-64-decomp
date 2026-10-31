/* FUN_80039a18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039a18  body 0x80039a18..0x80039a97  size 131 B
 * sha256  92b2906a8516283f2613781c5922727691c7f6f631b571818dac3c2fe5af7789
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039a18(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  param_3 = param_3 >> 1;
  puVar1 = (undefined2 *)(param_1 + param_3 * 2);
  puVar2 = (undefined2 *)(param_2 + param_3 * 2);
  if ((((param_5 == 0) || (param_5 == 8)) || (param_5 == 9)) ||
     ((param_5 == 0x1f || (param_5 == 0x26)))) {
    FUN_8003994c();
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      puVar2 = puVar2 + -1;
      puVar1 = puVar1 + -1;
      *puVar1 = *puVar2;
    }
  }
  return;
}

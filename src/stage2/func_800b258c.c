/* func_800b258c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b258c  body 0x800b258c..0x800b2617  size 143 B
 * body sha256 548225078c5fc273d1849704d416342b72ef39a226f265ee4b337e2c94b421ef
 * provider record sha256 4966dd63f86a7dcc2d3c7de3b303d74f9ed0746a34db3e02e0cb973968731288
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void func_800b258c(undefined2 param_1,char param_2)

{
  int iVar1;
  
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    iVar1 = FUN_800ae034(param_1);
    if (iVar1 != 0) {
      if (param_2 == -2) {
        *(undefined1 *)(iVar1 + 9) = 0x1f;
      }
      else {
        *(char *)(iVar1 + 9) = param_2;
        FUN_800a832c(param_2,3);
      }
    }
    FUN_800a56c0();
  }
  return;
}

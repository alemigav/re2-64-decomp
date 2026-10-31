/* FUN_8000b65c
 * image   boot (boot), base 0x80000480
 * address 0x8000b65c  body 0x8000b65c..0x8000b6ff  size 167 B
 * sha256  fa5389f65aaab20388eee310cb0afafe2b21d756fde94a5a2e09e455d7336f0a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000b65c(undefined1 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_10;
  
  puVar2 = (undefined4 *)&DAT_80016470;
  iVar1 = 0;
  _DAT_800164ac = 1;
  local_10 = CONCAT31(0xff0103,param_1);
  DAT_80014fe0 = param_1;
  if (DAT_80014f9c != 0) {
    do {
      *puVar2 = local_10;
      puVar2[1] = 0xffffffff;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 2;
    } while (iVar1 < (int)(uint)DAT_80014f9c);
  }
  *(undefined1 *)puVar2 = 0xfe;
  return;
}

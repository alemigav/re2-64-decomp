/* FUN_800aedc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aedc0  body 0x800aedc0..0x800aee7f  size 195 B
 * sha256  164b2648101bad4ed613e0b2b7af662a63db8a51345a4b119f99dc12ff5ef8d9
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800aedc0(undefined1 param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  
  uVar1 = FUN_800ae6b4(param_1,0xff,0xffff,1);
  if (uVar1 != 0xffffffff) {
    iVar2 = uVar1 * 0x1a0;
    puVar4 = (undefined4 *)(&DAT_80144448 + iVar2);
    (&DAT_80144505)[iVar2] = 1;
    (&DAT_80144494)[iVar2] = 1;
    FUN_800ae1a0(puVar4);
    *(uint *)(&DAT_801444a8 + iVar2) = uVar1 | 0xffffff00;
    cVar3 = FUN_800a5890(uVar1);
    if (cVar3 == '\0') {
      *puVar4 = 0;
    }
    else {
      FUN_800a5acc(uVar1);
      *puVar4 = 0;
    }
    FUN_800ae4d8(puVar4,param_1);
  }
  return uVar1;
}

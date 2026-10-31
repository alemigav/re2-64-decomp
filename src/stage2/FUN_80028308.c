/* FUN_80028308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028308  body 0x80028308..0x80028327  size 35 B
 * sha256  55487f224b6eb5479d0326658ae7f730d2d76a29b9d2865effe0cf474a738f50
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80028308(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0x1e;
  do {
    bVar1 = iVar2 != -1;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return param_1;
}

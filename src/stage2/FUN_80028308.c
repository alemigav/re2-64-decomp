/* FUN_80028308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028308  body 0x80028308..0x80028327  size 35 B
 * body sha256 c804ad05336e71c242cbe59799f23a233d0d5160242279ab52ec319a9eea1dc7
 * provider record sha256 6302a02815f94196e0ab7de4138381277d431aa4a983a1b46bd3958bddae102a
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

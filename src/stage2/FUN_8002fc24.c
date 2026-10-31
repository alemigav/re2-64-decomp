/* FUN_8002fc24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fc24  body 0x8002fc24..0x8002fc77  size 87 B
 * body sha256 e835da40de734d7c8a3d028b823c8627a6bbccfb4cad22a650b809d1005777af
 * provider record sha256 e2a1afa8bc56d73447d6e304981af0dfcd5258d77179b2551b1e1e94ed39a121
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8002fc24(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_8010b6e4;
  if (DAT_800c56f4 != '\0') {
    iVar1 = DAT_8010b6f8;
  }
  iVar1 = DAT_800ea270 + iVar1;
  DAT_800ea270 = DAT_800ea270 + param_1;
  return iVar1;
}

/* FUN_8008bdd4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008bdd4  body 0x8008bdd4..0x8008be27  size 87 B
 * sha256  107a5069519160ba542f7e13ecd451a0cb0eba44afc8cfab6ff7549076761949
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008bdd4(void)

{
  int iVar1;
  
  iVar1 = FUN_8002767c(0);
  if (iVar1 != 0) {
    FUN_800274f8(0x200,0,7,1);
    FUN_800275c0(0,0x7fff,0xffff,0);
    DAT_8012bf98 = 2;
  }
  return;
}

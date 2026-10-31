/* FUN_8005d700
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d700  body 0x8005d700..0x8005d79f  size 163 B
 * sha256  525535d6f281ee3422943cc20b9231496e75a002219fb3a2c0e3d31237039c50
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d700(int param_1)

{
  int iVar1;
  
  iVar1 = (*(byte *)(param_1 + 0x1ab) - 2 & 0xff) * 6;
  FUN_80052bd0((&DAT_80110f6c)[iVar1],0);
  FUN_80052c6c((&DAT_80110f6d)[iVar1],(&DAT_80110f6e)[(*(ushort *)(param_1 + 0x1aa) - 2) * 6],0);
  FUN_80052d10((&DAT_80110f71)[iVar1],(&DAT_80110f6f)[iVar1],(&DAT_80110f70)[iVar1],
               (&DAT_80110f6d)[iVar1]);
  return;
}

/* FUN_80088eec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088eec  body 0x80088eec..0x80088f1b  size 51 B
 * sha256  e05f3cf2c091e9380863c6c269209e27fe025c7ae65540f1483126b32efcbc31
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80088eec(int param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0xc4) + 7);
  *(int *)(param_1 + 0x234) = param_2;
  *(byte *)(param_1 + 0x1a3) = bVar1;
  return param_2 + (uint)bVar1 * 0x178;
}

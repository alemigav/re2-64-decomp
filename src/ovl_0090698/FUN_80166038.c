/* FUN_80166038
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166038  body 0x80166038..0x801660b7  size 128 B
 * body sha256 e7d013e1a8c9c4243f108078dd73d0c6c1c60686d5af77c3aa919319137fca05
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80166038.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80166038(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_8016703c(param_1,0x13,1);
    FUN_80166248(param_1);
    uVar1 = func_0x80033604();
    FUN_80167688(param_1,0x2004,(uVar1 & 3) + 6);
  }
  FUN_801658fc(param_1,param_2,param_3);
  return;
}

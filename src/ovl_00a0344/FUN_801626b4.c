/* FUN_801626b4
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801626b4  body 0x801626b4..0x80162753  size 160 B
 * body sha256 79612808797101e37d011d7dce0009c044831db2421a04c356cda08e8d90d99b
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/801626b4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_801626b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 7) * 0x10000 + 0x5000700;
    *(undefined2 *)(param_1 + 0x2c2) = 0;
    *(undefined2 *)(param_1 + 700) = *(undefined2 *)(param_1 + 0x2c0);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  FUN_8016375c(param_1,0);
  return;
}

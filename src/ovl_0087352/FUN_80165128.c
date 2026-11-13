/* FUN_80165128
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165128  body 0x80165128..0x8016519b  size 116 B
 * body sha256 27de8ff42e3e47f136d852b05214a521c490c55aee369ad5fcfed56fd374dbe3
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0087352/80165128.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef void code();
extern unsigned int DAT_800e1158;
extern unsigned int PTR_FUN_801666cc;












void FUN_80165128(int param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  (*(code *)(&PTR_FUN_801666cc)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

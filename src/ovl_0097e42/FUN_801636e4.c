/* FUN_801636e4
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x801636e4  body 0x801636e4..0x8016375f  size 124 B
 * body sha256 f7fcbb0b34c24278449cdbe4d86886d2a957137a1f41dd85cb28b1a839577d48
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0097e42/801636e4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int uint;












void FUN_801636e4(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [8];
  
  iVar2 = *(int *)(param_1 + 0x234);
  func_0x80082200(auStack_20,0,8);
  iVar1 = func_0x80033604();
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(iVar1 << 0x18) >> 0x14,iVar2 + 0x38,
                  auStack_20);
  return;
}

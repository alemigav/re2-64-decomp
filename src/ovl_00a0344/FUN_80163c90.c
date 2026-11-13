/* FUN_80163c90
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163c90  body 0x80163c90..0x80163cef  size 96 B
 * body sha256 e5c149ff511292bf4e3f5003fde645ece8af59e39bbfbd85cd33d4a6ce7aaa71
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/80163c90.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_80163e68;
extern unsigned int DAT_80163ed4;












void FUN_80163c90(int param_1)

{
  undefined4 uVar1;
  
  if (*(unsigned char *)(param_1 + 0x2cc) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x234);
    func_0x80036290(param_1,uVar1,&DAT_80163e68);
    func_0x80036290(param_1,uVar1,&DAT_80163ed4);
    func_0x80036694(param_1);
  }
  return;
}

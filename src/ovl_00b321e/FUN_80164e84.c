/* FUN_80164e84
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164e84  body 0x80164e84..0x80164f13  size 144 B
 * body sha256 ad5484702442a77a850069bb7ed83f46de74d9341c8518be35f4956c96845fc8
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/80164e84.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_801667a8;












void FUN_80164e84(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_80164684();
    *(undefined1 *)(param_1 + 0x2cf) = 0x14;
  }
  else {
    (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}

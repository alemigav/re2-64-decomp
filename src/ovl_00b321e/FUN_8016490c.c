/* FUN_8016490c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016490c  body 0x8016490c..0x801649ab  size 160 B
 * body sha256 2b4a341641a4cf256dc1458003be809215a227b79c2a5a9b329ff61fdbd6f25b
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/8016490c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_801667a8;












void FUN_8016490c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_80166270(param_1,0,7);
    FUN_80164684(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}

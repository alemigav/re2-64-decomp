/* FUN_80164dbc
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164dbc  body 0x80164dbc..0x80164e83  size 200 B
 * body sha256 a16107529689ef14c148e57a74b3874a7ca4bb7b27238c2ae348399922e2896f
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/80164dbc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned int PTR_FUN_801667a8;












void FUN_80164dbc(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,8,uVar1 & 3);
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,8,uVar1 & 3 | 4);
    FUN_80164684(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}

/* FUN_80165bb4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165bb4  body 0x80165bb4..0x80165c5b  size 168 B
 * body sha256 5b3861a38a6c16326f38b74a121544e5ef659852038db1018359e161d3201a1d
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80165bb4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;












void FUN_80165bb4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)(param_1 + 700) == '\0') {
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 500));
    FUN_8016655c(param_1,10,0);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,(int)*(short *)(param_1 + 0x1f6));
  if (iVar1 != 0) {
    if (*(unsigned char *)(param_1 + 7) == '\0') {
      *(undefined1 *)(param_1 + 7) = 1;
      *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x1ea) * 0x100 + 0x12000000;
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0x7000000;
    }
  }
  return;
}

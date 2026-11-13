/* FUN_801627f0
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801627f0  body 0x801627f0..0x8016289b  size 172 B
 * body sha256 37dc37e25378ad8e00b5c861744581376e0e2e64a3a0a15f57c7563a97653a90
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/801627f0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_801627f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x2c7) = 1;
    *(undefined2 *)(param_1 + 0x2c2) = 0x400;
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 7) << 0x10;
    func_0x80089d54(param_1,param_2,param_3,0x200);
    if ((*(unsigned char *)(param_1 + 0x2bf) == '\x01') && (*(unsigned char *)(param_1 + 0x2c6) == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x2020000;
      *(undefined1 *)(param_1 + 0x2be) = 0;
      *(undefined1 *)(param_1 + 0x206) = 1;
    }
  }
  FUN_8016375c(param_1,0);
  return;
}

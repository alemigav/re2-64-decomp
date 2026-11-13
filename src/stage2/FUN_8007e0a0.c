/* FUN_8007e0a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e0a0  body 0x8007e0a0..0x8007e10b  size 108 B
 * body sha256 5fcee7be4862a23e62c580828cc46ccc8b4f39ffb794f6aad90cbb9faf43d180
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007e0a0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_8007e0a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9010f00;
  }
  iVar1 = FUN_80089d54(param_1,param_2,param_3,0x10100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined1 *)(param_1 + 0x2c6) = 0x1e;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
  }
  return;
}

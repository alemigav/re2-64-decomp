/* FUN_8016256c
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x8016256c  body 0x8016256c..0x801625d3  size 104 B
 * body sha256 c28e18f73e097d6e9e8715ba88baccc9db7bbca45a83871cb51c90a4fadbada3
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b08a2/8016256c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;












void FUN_8016256c(int param_1)

{
  ushort uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar1 & 0x3f) + 0x3c;
    **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) & 0xfffffffe;
  }
  return;
}

/* FUN_80165c50
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165c50  body 0x80165c50..0x80165ca7  size 88 B
 * body sha256 a0ea3b979f0a60f20da291f725b9a4f459fc8fa8d50fd2e91a9a78339b3f528e
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0098ee0/80165c50.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_LAB_80166894;












void FUN_80165c50(int param_1)

{
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  if (*(unsigned char *)(param_1 + 4) == '\x01') {
    (*(code *)(&PTR_LAB_80166894)[*(byte *)(param_1 + 5)])();
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}

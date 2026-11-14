/* FUN_800a56c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a56c0  body 0x800a56c0..0x800a56ff  size 64 B
 * body sha256 884fd874f5d5b8c1a95737f279d612afa287d0898244093cffac78cfd70e2074
 * recovered byte-exact (imported: guard with an early exit plus a SIGNED declaration gives blez (M424 workbench))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a56c0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;
extern int DAT_80135cac;
extern unsigned char D_80143fb0[];
void FUN_800a56c0(void)
{
  if (DAT_80135cac <= 0) {
    return;
  }
  DAT_80135cac = DAT_80135cac - 1;
  if (DAT_80135cac == 0) {
    func_0x8000cb60((u32)D_80143fb0, 0, 0);
  }
}

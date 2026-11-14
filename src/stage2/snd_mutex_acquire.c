/* snd_mutex_acquire
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5678  body 0x800a5678..0x800a56bf  size 72 B
 * body sha256 6afcab62acd0e30d6e6cecae0a56d357a602620559e3d055235cdf3aa0da3dcc
 * recovered byte-exact (imported: closed by the symbol:addr mechanism pass (17 of 18 -> 18 of 18) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a5678.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;
extern unsigned char D_80143fb0[];
extern unsigned int DAT_80135cac;












void FUN_800a5678(void)

{
  if (DAT_80135cac == 0) {
    func_0x8000c9e0((u32)D_80143fb0,0,1);
  }
  DAT_80135cac = DAT_80135cac + 1;
  return;
}

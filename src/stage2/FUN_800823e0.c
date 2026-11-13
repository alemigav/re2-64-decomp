/* FUN_800823e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800823e0  body 0x800823e0..0x80082473  size 148 B
 * body sha256 f1ff4f3269591b988e08fdb736e66308e6d3c6328cc70673cf7c056f2f258bf1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800823e0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;
extern unsigned int DAT_8010b6e8;
extern unsigned int DAT_8010b6ec;
extern unsigned int DAT_801137f0;
extern unsigned int DAT_801137f4;












void FUN_800823e0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = (uint)(DAT_801137f0 * DAT_801137f4) >> 1;
  puVar1 = DAT_8010b6e8;
  while (uVar2 = uVar2 - 1, uVar2 != 0xffffffff) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  if (DAT_8010b6ec != (undefined4 *)0x0) {
    uVar2 = (uint)(DAT_801137f0 * DAT_801137f4) >> 1;
    puVar1 = DAT_8010b6ec;
    while (uVar2 = uVar2 - 1, uVar2 != 0xffffffff) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
  }
  return;
}

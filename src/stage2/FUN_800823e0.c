/* FUN_800823e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800823e0  body 0x800823e0..0x80082473  size 151 B
 * sha256  b3526325d3d93681619d5aa38af75339b5747c819881bb6de007e11871e11cee
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
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

/* FUN_800510d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800510d0  body 0x800510d0..0x80051103  size 55 B
 * body sha256 0a75457fa68bfe1011c45182105a087b6ecd41d537ab63ee5a77de885a31558d
 * provider record sha256 5e682c69cdf33a934d7be7dc9777cfeeaf61ffc16fb5dece7e635439e7a9c748
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800510d0(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_8010bc30 < 5) {
    iVar1 = DAT_8010bc30 * 4;
    DAT_8010bc30 = DAT_8010bc30 + 1;
    *(undefined4 *)(&DAT_8010bf90 + iVar1) = param_1;
  }
  return;
}

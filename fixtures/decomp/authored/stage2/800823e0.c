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

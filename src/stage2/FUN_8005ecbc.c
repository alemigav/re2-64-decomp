/* FUN_8005ecbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ecbc  body 0x8005ecbc..0x8005ee1f  size 359 B
 * body sha256 070cddb55d601931669ab9e2f42aa7c3da6cf12bcf09757fa04bb0a2b1ace850
 * provider record sha256 a45fd3104c4b905466c2acdddc0fceb28d2ad1e3aa83e4d703e80920d2d6bbd8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005ecbc(int param_1)

{
  int iVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if ((uint)*(byte *)(param_1 + 0x1e9) % 3 == 1) {
    local_18 = 0x46;
    local_16 = 1000;
    if (DAT_800e1138 < 4) {
      local_14 = 0xffc4;
    }
    else {
      local_14 = 0xff9c;
    }
    iVar1 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1011000,0,iVar1,&local_18);
    FUN_80037780(0x30c1000,0,iVar1,&local_18);
    FUN_8005d700(param_1);
  }
  if ((uint)*(byte *)(param_1 + 0x1e9) % 6 == 1) {
    local_18 = 0xaa;
    local_16 = 0x118;
    local_14 = 0x50;
    FUN_80037780(0x2010900,(int)((DAT_800e1196 + 0x4b0) * 0x10000) >> 0x10,
                 *(int *)(param_1 + 0x234) + 0x1060,&local_18);
  }
  return;
}

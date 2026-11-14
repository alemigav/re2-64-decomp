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

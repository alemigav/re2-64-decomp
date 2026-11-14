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

/* FUN_800aebfc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aebfc  body 0x800aebfc..0x800aeccb  size 211 B
 * sha256  3dd1e086851c13aa91b3232236e4237fb83ef64b7172aabc47ef532c08fd0244
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800aebfc(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  
  FUN_800ae3d0();
  bVar1 = *(byte *)((int)param_1 + 99);
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 0x2e) = 0;
  iVar2 = (uint)bVar1 * 4;
  if (*(short *)(iVar2 + -0x7fea773e) == 0) {
    *(undefined2 *)(iVar2 + -0x7fea773e) = 1;
    if (DAT_80158a40 == 0xff) {
      *(undefined1 *)(iVar2 + -0x7fea773f) = 0xff;
      (&DAT_801588c0)[iVar2] = 0xff;
      DAT_80158a40 = bVar1;
    }
    else {
      *(undefined1 *)(iVar2 + -0x7fea773f) = 0xff;
      (&DAT_801588c0)[iVar2] = DAT_80158839;
      *(byte *)((uint)DAT_80158839 * 4 + -0x7fea773f) = bVar1;
    }
    DAT_80158839 = bVar1;
    if (*(char *)(param_1 + 0x13) == '\0') {
      DAT_80158838 = DAT_80158838 + -1;
    }
    else {
      DAT_8015883c = DAT_8015883c + -1;
    }
  }
  param_1[0x18] = 0xffffffff;
  return;
}

/* func_800b3a70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b3a70  body 0x800b3a70..0x800b3b9b  size 303 B
 * body sha256 0d024599b6d76cffbc412a801c494a3664b2143785fa7d43e2430bcf9fe4e08f
 * provider record sha256 b570e9bd498707ca2a13145bfd3ef31f1bb23290f3d747252d2c7d913df402d8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4
func_800b3a70(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
             undefined1 param_5)

{
  int in_v0;
  int iVar1;
  uint uVar2;
  
  if (in_v0 != 0) {
    uVar2 = 0;
    iVar1 = -0x7fea74e0;
    do {
      if ((*(char *)(iVar1 + 0x1200) != '\0') && (*(int *)(iVar1 + 0x1224) == param_1))
      goto LAB_800b3ae0;
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0x1228;
    } while (uVar2 < 2);
    uVar2 = 0xffffffff;
LAB_800b3ae0:
    if (uVar2 != 0xffffffff) {
      osRecvMesg(0x8015afa0,0,1);
      iVar1 = uVar2 * 0x1228;
      if (*(int *)(iVar1 + -0x7fea62d4) != -1) {
        FUN_800a949c(*(undefined4 *)(iVar1 + -0x7fea62d4),param_2,param_3,param_4,param_5);
      }
      *(undefined1 *)(iVar1 + -0x7fea62de) = param_3;
      *(undefined1 *)(iVar1 + -0x7fea62dd) = param_4;
      *(undefined1 *)(iVar1 + -0x7fea62df) = param_2;
      osSendMesg(0x8015afa0,0,0);
      return 1;
    }
  }
  return 0;
}

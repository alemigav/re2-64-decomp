/* FUN_80087f24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087f24  body 0x80087f24..0x800880cf  size 431 B
 * sha256  5fc987f1ee9d632b7aeacca37ec103fb526f1364b2dfa8870a0e9d10e8e2f739
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087f24(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = func_0x8000bbf0(&UNK_80129e94 + *param_1 * 0x68,*(undefined2 *)(param_1 + 7),param_1[6],
                          (int)param_1 + 0x22,(int)param_1 + 0x1e,param_1 + 4);
  *(undefined4 *)param_1[1] = uVar1;
  uVar2 = *(uint *)param_1[1];
  if (uVar2 != 0) {
    if (uVar2 < 5) {
      iVar3 = param_1[0xe];
      goto LAB_800880a8;
    }
    if (uVar2 == 5) {
      if (param_1[3] == 0) {
        iVar3 = param_1[0xe];
        goto LAB_800880a8;
      }
      uVar1 = func_0x80009640(&UNK_80129e94 + *param_1 * 0x68,*(undefined2 *)(param_1 + 7),
                              param_1[6],(int)param_1 + 0x22,(int)param_1 + 0x1e,param_1[5],
                              param_1 + 4);
      *(undefined4 *)param_1[1] = uVar1;
      uVar2 = *(uint *)param_1[1];
      if ((uVar2 != 0) && ((uVar2 < 6 || ((uVar2 < 10 && (6 < uVar2)))))) {
        iVar3 = param_1[0xe];
        goto LAB_800880a8;
      }
    }
  }
  uVar1 = func_0x8000b7c0(&UNK_80129e94 + *param_1 * 0x68,param_1[4],
                          *(undefined1 *)((int)param_1 + 0xf),param_1[2],param_1[5],param_1[0xd]);
  *(undefined4 *)param_1[1] = uVar1;
  iVar3 = param_1[0xe];
LAB_800880a8:
  osSendMesg(iVar3,0,0);
  return;
}

/* FUN_80087e30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087e30  body 0x80087e30..0x80087f23  size 247 B
 * sha256  1d389822d337d675defb69812d8ec554c631ea33c18614ed3a6402f70d4b393e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087e30(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if ((&DAT_8012a034)[*param_1] == '\x01') {
    iVar2 = 0;
    iVar3 = 0x48;
    *(undefined4 *)param_1[1] = 0;
    piVar4 = param_1;
    do {
      uVar1 = func_0x8000a6c0(&UNK_80129e94 + *param_1 * 0x68,iVar2,(int)param_1 + iVar3);
      piVar4[2] = uVar1;
      if ((uVar1 < 5) && (uVar1 != 0)) {
        *(uint *)param_1[1] = uVar1;
      }
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while (iVar2 < 0x10);
    osSendMesg(param_1[0x92],0,0);
  }
  else {
    *(undefined4 *)param_1[1] = 0xffff;
  }
  return;
}

/* FUN_8002e640
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e640  body 0x8002e640..0x8002e6fb  size 191 B
 * sha256  d4979d007639bd65e34cb36ff117f9465923bd94e74123edda86a3cddedf160b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e640(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int *param_6,int param_7)

{
  uint uVar1;
  int iVar2;
  int local_18 [2];
  
  iVar2 = *(int *)(param_1 + 0x170);
  uVar1 = param_7 - *param_6;
  if (*(uint *)(iVar2 + 0x10) < (uint)(param_7 - *param_6)) {
    uVar1 = *(uint *)(iVar2 + 0x10);
  }
  local_18[0] = 0;
  (**(code **)(*(int *)(param_1 + 0x180) + 4))
            (param_1,param_2,param_3,param_4,*(undefined4 *)(iVar2 + 0xc),local_18,uVar1);
  (**(code **)(*(int *)(param_1 + 0x188) + 4))
            (param_1,*(undefined4 *)(iVar2 + 0xc),param_5 + *param_6 * 4,local_18[0]);
  *param_6 = *param_6 + local_18[0];
  return;
}

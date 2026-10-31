/* func_800b3ba4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b3ba4  body 0x800b3ba4..0x800b3ddb  size 571 B
 * body sha256 11d4cef6b964ba7115ba5606edfbe64860b28f7e006b4a0c03f87d5e34b2d46f
 * provider record sha256 557215ecd679cb57bc436001a608b96e33bb90f3e7fd3fbb165e6091b91ae9b8
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_800b3ba4(void)

{
  byte bVar1;
  int in_v0;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  if (in_v0 != 0) {
    osRecvMesg(0x8015afa0,0,1);
    iVar4 = 0;
    iVar3 = -0x7fea74e0;
    do {
      if (*(char *)(iVar3 + 0x1200) != '\0') {
        FUN_800b4a04(iVar3);
        bVar1 = *(byte *)(iVar3 + 0x1200);
        if (bVar1 == 2) {
          if (*(char *)(iVar3 + 0x11dd) == '\x04') {
            *(undefined1 *)(iVar3 + 0x1200) = 3;
            *(undefined1 *)(iVar3 + 0x1218) = 4;
          }
        }
        else if (bVar1 < 3) {
          if ((bVar1 == 1) && (*(char *)(iVar3 + 0x11dd) == '\x02')) {
            iVar2 = *(int *)(iVar3 + 0x1208);
            if (iVar2 < 0) {
              fVar5 = (float)iVar2 + 4.2949673e+09;
            }
            else {
              fVar5 = (float)iVar2;
            }
            *(float *)(iVar3 + 0x1220) = ((float)*(ushort *)(iVar3 + 0x11a0) * 160.0) / fVar5;
            *(undefined4 *)(iVar3 + 0x121c) = 0;
            *(undefined1 *)(iVar3 + 0x1200) = 2;
            FUN_800b4d90(iVar3);
            iVar2 = FUN_800a924c(*(undefined1 *)(iVar3 + 0x1204),*(undefined4 *)(iVar3 + 0x1210),
                                 *(undefined4 *)(iVar3 + 0x1214),*(undefined4 *)(iVar3 + 0x1208),
                                 *(undefined1 *)(iVar3 + 0x1201),*(undefined1 *)(iVar3 + 0x1202),
                                 *(undefined1 *)(iVar3 + 0x1203),*(undefined1 *)(iVar3 + 0x1219),
                                 FUN_800b4478,iVar4);
            *(int *)(iVar3 + 0x120c) = iVar2;
            if (iVar2 == -1) {
              FUN_800b4dac(iVar3);
LAB_800b3d3c:
              if ((_DAT_8015af90 & 1) == 0) {
                (*_DAT_8014400c)(*(undefined4 *)(iVar3 + 0x1210));
              }
              *(undefined1 *)(iVar3 + 0x1200) = 0;
            }
          }
        }
        else if (bVar1 == 3) {
          if (*(char *)(iVar3 + 0x1218) == '\0') goto LAB_800b3d3c;
          if (*(char *)(iVar3 + 0x1218) == '\x02') {
            FUN_800a942c(*(undefined4 *)(iVar3 + 0x120c));
            *(undefined4 *)(iVar3 + 0x120c) = 0xffffffff;
          }
          *(char *)(iVar3 + 0x1218) = *(char *)(iVar3 + 0x1218) + -1;
        }
      }
      iVar3 = iVar3 + 0x1228;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    osSendMesg(0x8015afa0,0,0);
  }
  return;
}

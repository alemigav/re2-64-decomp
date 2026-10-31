/* FUN_8004a3e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a3e0  body 0x8004a3e0..0x8004a48f  size 179 B
 * sha256  57d60d9b0663e330b08d998f4af8017ab0d6dc8ccce636198fd3367e7d3ca8f7
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004a3e0(undefined4 *param_1)

{
  char cVar1;
  
  if ((DAT_800e10f1 == '\x02') ||
     (cVar1 = FUN_8004a328(*(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20,DAT_800e10f1,
                           param_1 + 10), cVar1 != '\0')) {
    FUN_8004a490(param_1);
    DAT_80124830 = DAT_80124830 | 1;
    FUN_80088990(param_1,param_1[0x8d],*param_1,param_1 + 10);
    DAT_80124830 = DAT_80124830 & 0xfffffffe;
  }
  return;
}

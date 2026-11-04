/* FUN_800acb68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acb68  body 0x800acb68..0x800acb6f  size 8 B
 * body sha256 c205abac13b0b043ae64d6f4857f86ba450025bec7271cdf460b9c5d428bc88d
 * provider record sha256 38fc9f7d4f05e7a8cf21c1d581b4ace0102e2cfe4bebe6c060aca7c15898defa
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800acb40::caseD_84
               (undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined2 param_4)

{
  int in_t1;
  
  if (*(char *)(in_t1 + 0x4a) != -1) {
    FUN_800ab7e0(param_2,*(char *)(in_t1 + 0x4a),*(undefined1 *)(in_t1 + 0x4b),param_4);
  }
  return;
}

/* FUN_800acb50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acb50  body 0x800acb50..0x800acb57  size 8 B
 * body sha256 5a278c22a316cc06f0e2b4afd602369b89398d639a86f31b34331491be5d4484
 * provider record sha256 11d2f4d361c60a33aff539e3f430392e29e95fc2efaa6e618cca497889c719f0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800acb40::caseD_81
               (undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined2 param_4)

{
  int in_t1;
  
  if (*(char *)(in_t1 + 0x4a) != -1) {
    FUN_800ab7e0(param_2,*(char *)(in_t1 + 0x4a),*(undefined1 *)(in_t1 + 0x4b),param_4);
  }
  return;
}

/* FUN_800acb48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acb48  body 0x800acb48..0x800acb4f  size 11 B
 * body sha256 bc9c00624476e3d1c05c2bf7a8c5ff9453fbdd636a27857a474793b2d05367a0
 * provider record sha256 9718bbd7023696c5d7947237f0e41ed4c1e1d5cf4d5cc445f4c90a8fd2228037
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800acb40::caseD_80
               (undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined2 param_4)

{
  int in_t1;
  
  if (*(char *)(in_t1 + 0x4a) != -1) {
    FUN_800ab7e0(param_2,*(char *)(in_t1 + 0x4a),*(undefined1 *)(in_t1 + 0x4b),param_4);
  }
  return;
}

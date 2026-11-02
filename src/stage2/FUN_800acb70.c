/* FUN_800acb70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acb70  body 0x800acb70..0x800acbb7  size 72 B
 * body sha256 334a84ad77a2fbd8e68cdd8fff48f71c210ef05b3d1e9f026846c7fb8b788bcc
 * provider record sha256 23ed729ff93f2f429fe0ec64ec7c8bdd3aa7c4d9fbc9273a6fee1f0d371f39e9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800acb40::caseD_85
               (undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined2 param_4)

{
  int in_t1;
  
  if (*(char *)(in_t1 + 0x4a) != -1) {
    FUN_800ab7e0(param_2,*(char *)(in_t1 + 0x4a),*(undefined1 *)(in_t1 + 0x4b),param_4);
  }
  return;
}

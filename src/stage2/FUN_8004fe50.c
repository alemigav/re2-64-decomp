/* FUN_8004fe50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004fe50  body 0x8004fe50..0x8004fea3  size 87 B
 * body sha256 a428905ea792a339260ae2ff5e442288d512bb98746f3a75d251765a5c8871fb
 * provider record sha256 92db01afecd3924b61a302e9b950c4087a270cc6c3b86ce1effc571395ddfc0d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8004fd3c::caseD_4
               (undefined4 param_1,undefined2 *param_2,undefined4 param_3,undefined1 *param_4)

{
  char cVar1;
  
  cVar1 = param_4[1];
  param_4[1] = cVar1 - 1U;
  if ((byte)param_4[2] == 0) {
    trap(0x1c00);
  }
  *param_2 = (short)((uint)(byte)(cVar1 - 1U) / (uint)(byte)param_4[2] << 4);
  if (param_4[1] == '\0') {
    *param_4 = 0x83;
    param_4[1] = param_4[2];
  }
  return;
}

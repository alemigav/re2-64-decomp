/* FUN_8007e170
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e170  body 0x8007e170..0x8007e1ff  size 147 B
 * body sha256 ceb529bd53397e5be247699728030623842aec34df03dc7f153459e1c53e9c45
 * provider record sha256 7e61041c4e3247f8dd5010265ff4758d299d6e7a65b48aa3618047f1eb04485f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007e170(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9030f00;
  }
  else if (*(char *)(param_1 + 7) != '\x01') {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x250);
  FUN_80032dbc(param_1,*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x30),0xd8);
  iVar1 = FUN_80032e74(param_1,*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x30),0x10);
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}

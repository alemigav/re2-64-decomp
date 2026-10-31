/* FUN_80059d5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059d5c  body 0x80059d5c..0x80059dff  size 167 B
 * body sha256 941a41a6465e89179e70063a76c1dc3cbed732b291bbce8eb7cb113528f7a93e
 * provider record sha256 a48d10b19a99e69e9a54833fad919546dfb8a66c0818a09937b081352ac22c40
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059d5c(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x208);
  if (*(char *)(param_1 + 5) == '\0') {
    *(undefined1 *)(param_1 + 5) = 1;
    FUN_800341dc(iVar2,0);
    *(undefined2 *)(param_1 + 500) = 0x3c;
  }
  else if (*(char *)(param_1 + 5) != '\x01') {
    return;
  }
  *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + 8;
  *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + 8;
  sVar1 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar1;
  if (sVar1 == -1) {
    *(undefined1 *)(param_1 + 5) = 2;
  }
  return;
}

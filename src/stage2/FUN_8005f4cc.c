/* FUN_8005f4cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005f4cc  body 0x8005f4cc..0x8005f59f  size 215 B
 * body sha256 3e96656e7917fd95e9a7dd8388c4da813c4eae1f5fb4136b1f39ea93d92389b6
 * provider record sha256 f810efbbafec7a5c4d75587d95cc7699b9d986275d4ebe79c9fde42e90df77df
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005f4cc(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    FUN_8005f5a0(param_1);
    if (*(int *)(param_1 + 0x250) == param_1) goto LAB_8005f584;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9030f00;
    *(undefined1 *)(param_1 + 0x207) = 0xc;
  }
  else if (*(char *)(param_1 + 7) != '\x01') {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x250);
  if (iVar2 != param_1) {
    FUN_80032dbc(param_1,*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x30),0xd8);
  }
  iVar2 = FUN_80032e74(param_1,*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x30),0x10);
  if (iVar2 == 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  cVar1 = *(char *)(param_1 + 0x207) + -1;
  *(char *)(param_1 + 0x207) = cVar1;
  if (cVar1 != -1) {
    return;
  }
LAB_8005f584:
  *(undefined2 *)(param_1 + 6) = 0x100;
  return;
}

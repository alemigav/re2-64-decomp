/* FUN_800700d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800700d0  body 0x800700d0..0x8007011f  size 83 B
 * body sha256 c18acca3a07f1a7f38ff7d77ae71a8fc2914a50e08fb0f7ad5580b9f3d40c79b
 * provider record sha256 d6abaae403f48f8f79015c4ab11862913206cf64d5307712332b9e2a5476fcc5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800700d0(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  cVar1 = *(char *)(iVar3 + 1);
  cVar2 = *(char *)(iVar3 + 2);
  *(int *)(param_1 + 0x1c) = iVar3 + 3;
  uVar4 = FUN_800701d8(*(undefined4 *)(param_1 + 0x154),(int)cVar2);
  (&DAT_800e8c78)[cVar1] = uVar4;
  return 1;
}

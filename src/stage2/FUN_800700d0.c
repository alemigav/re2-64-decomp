/* FUN_800700d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800700d0  body 0x800700d0..0x8007011f  size 80 B
 * body sha256 40ae600b5f89845900a5003b7bf7c868b5490889d02bb9d2d0596d6b4f9223ea
 * recovered byte-exact (imported: closed by the localtype pass, round 2 (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800700d0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern short DAT_800e8c78;












undefined4 FUN_800700d0(int param_1)

{
  int cVar1;
  int cVar2;
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

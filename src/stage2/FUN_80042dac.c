/* FUN_80042dac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042dac  body 0x80042dac..0x80042ddf  size 52 B
 * body sha256 96d9b4f92111f36d04f092c58da7f4145f4862f6c45a6bef86b21637a5237bfc
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80042dac.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_80139a64;












void FUN_80042dac(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)&DAT_80139a64;
  iVar2 = 2;
  puVar3 = (undefined4 *)(param_1 + 0x14);
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  } while (iVar2 != -1);
  return;
}

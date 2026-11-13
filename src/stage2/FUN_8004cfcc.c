/* FUN_8004cfcc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cfcc  body 0x8004cfcc..0x8004d02f  size 100 B
 * body sha256 1bedc72609673a6c0b2f784cf656b1491f63d9baef2777b5ade7dd2190584966
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8004cfcc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_8010b6c0;












undefined4 FUN_8004cfcc(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &DAT_8010b6c0;
  do {
    uVar1 = FUN_8008b048(4);
    uVar1 = FUN_8004cf30(uVar1);
    *puVar2 = uVar1;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 4);
  return param_1;
}

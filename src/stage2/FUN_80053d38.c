/* FUN_80053d38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053d38  body 0x80053d38..0x80053d7b  size 68 B
 * body sha256 dc6772125df9cb34ac25f86af04e989008087be7ade1397854e954c794f48b73
 * recovered byte-exact (imported: closed by the order:adjacent mechanism pass (15 of 17 -> 17 of 17) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80053d38.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int uint;
extern unsigned int DAT_8010d940;












void FUN_80053d38(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  puVar1 = DAT_8010d940;
  uVar4 = 0;
  puVar3 = DAT_8010d940 + 4;
  puVar2 = DAT_8010d940 + 0x16c;
  do {
    *puVar3 = 0x20;
    puVar3 = puVar3 + 1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x168);
  puVar1[0x2d7] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  return;
}

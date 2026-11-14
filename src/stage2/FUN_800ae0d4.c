/* FUN_800ae0d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae0d4  body 0x800ae0d4..0x800ae143  size 112 B
 * body sha256 a175e254f36be6016b0b593725b62fb401e408da7445ab22c2c87902e98674bd
 * recovered byte-exact (imported: closed by the order:adjacent mechanism pass (25 of 28 -> 28 of 28) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800ae0d4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
extern unsigned int DAT_80153610;
extern unsigned int _DAT_8014e16c;
extern unsigned int _DAT_8014e1d0;
extern unsigned int _DAT_801521e0;
extern unsigned int _DAT_801529f0;
extern unsigned int _DAT_80153600;
extern unsigned int _DAT_80157e10;














void FUN_800ae0d4(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (undefined2 *)&DAT_80153610;
  _DAT_8014e16c = 0;
  _DAT_8014e1d0 = 0;
  _DAT_801521e0 = 0;
  _DAT_801529f0 = 0;
  _DAT_80157e10 = 0;
  _DAT_80153600 = 0;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x200);
  FUN_800a5cdc();
  return;
}

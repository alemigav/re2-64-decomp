/* FUN_800ae0d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae0d4  body 0x800ae0d4..0x800ae143  size 115 B
 * sha256  0cfd3b32917f4342eb57f1ba91ad9cf9c848c0e00ebb9c3e9bec20ff84abcc8a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 2;
  } while (iVar2 < 0x200);
  FUN_800a5cdc();
  return;
}

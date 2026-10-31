/* FUN_80077a80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80077a80  body 0x80077a80..0x80077adb  size 95 B
 * sha256  a31aea10d6ab0396cbc82ea7010fbbdd5dea14cd6a2cdc64519b7993cb8f3a71
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80077a80(uint param_1)

{
  byte bVar1;
  undefined2 uVar2;
  
  bVar1 = (&DAT_80117117)[param_1 >> 0x18];
  uVar2 = FUN_800844cc((int)(short)param_1);
  *(undefined2 *)(&UNK_800e8b5c + (param_1 >> 0xf & 0x1fe) + (uint)bVar1 * 2) = uVar2;
  return;
}

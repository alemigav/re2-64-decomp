/* FUN_800270a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800270a8  body 0x800270a8..0x80027147  size 163 B
 * body sha256 97c59db443418cd6dde3b9a7c74537e2bb5f9dceb60490ffd062d4ea33c5e3d9
 * provider record sha256 c2d90eec08675a83345b2dc171bca315d144caaf8bd46383c177b501bd80ac8c
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800270a8(void)

{
  undefined4 uVar1;
  
  FUN_80026aa8();
  FUN_80024d60();
  uVar1 = func_0x800072e0();
  DAT_80112968 = 4;
  FUN_8006b3dc(0,0,2);
  DAT_80112780 = 1;
  FUN_8006b3dc(1,0,1);
  (&DAT_80112968)[DAT_80112780] = 1;
  func_0x80007300(uVar1);
  FUN_8006b6b4();
  return;
}

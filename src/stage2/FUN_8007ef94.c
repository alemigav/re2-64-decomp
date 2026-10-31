/* FUN_8007ef94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ef94  body 0x8007ef94..0x8007efe7  size 87 B
 * body sha256 03fa35c86110d838260944f373db4b2f8fd924fe465baa1acf53f974cc2235d9
 * provider record sha256 6daa3d723e95d192ea35f675fe3456b9a46e776ed3a3b20fef1c4e8b5762cce7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ef94(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),
                       0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  else {
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),0xa0);
  }
  return;
}

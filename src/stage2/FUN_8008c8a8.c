/* FUN_8008c8a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c8a8  body 0x8008c8a8..0x8008c96f  size 203 B
 * sha256  8412a5cf62017941ed1e896dd147e8a2b6b832bc939ad47c499c8b86035a5244
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c8a8(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_8008c4b8(0);
  if (param_1 - 0xeU < 6) {
    FUN_8008c6c8(1);
    FUN_8008c314(0,param_1,param_2,1);
    FUN_8008c970(0,param_3);
    FUN_8008c314(1,param_1,param_2,2);
    iVar2 = 1;
    param_3 = param_3 + 0x4b0;
  }
  else {
    FUN_8008c314(uVar1,param_1,param_2,0);
    iVar2 = (uVar1 >> 1) + uVar1;
  }
  FUN_8008c970(iVar2,param_3);
  return;
}

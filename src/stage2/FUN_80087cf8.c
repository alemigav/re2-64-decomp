/* FUN_80087cf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087cf8  body 0x80087cf8..0x80087d8f  size 155 B
 * sha256  f0ae0b4f63b692760c2c8a5d3b3f1245e60c1e08fda822d3a711561f8507a640
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087cf8(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  func_0x800068d0(0x8013a2f0,&DAT_80129e90,0x8013a340);
  puVar2 = &UNK_80129e94 + param_1 * 0x68;
  iVar1 = func_0x800082d0(0x8013a2f0,puVar2,param_1);
  if (iVar1 == 0) {
    func_0x80007f50(puVar2);
    func_0x80007f50(puVar2);
    func_0x80007f50(puVar2);
  }
  return;
}

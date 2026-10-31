/* FUN_800267a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800267a4  body 0x800267a4..0x8002681f  size 127 B
 * sha256  94a48cb16b5320b78b44f622cf51d4d3934050804d8ca5881fc925413de14719
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800267a4(int param_1,code *param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x800072e0();
  DAT_80112780 = (undefined1)param_1;
  (&DAT_80112968)[param_1] = 1;
  func_0x80007300(uVar1);
  (*param_2)();
  uVar1 = func_0x800072e0();
  (&DAT_80112968)[param_1] = param_3;
  func_0x80007300(uVar1);
  return;
}

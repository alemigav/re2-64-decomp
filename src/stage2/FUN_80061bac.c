/* FUN_80061bac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061bac  body 0x80061bac..0x80061c97  size 239 B
 * sha256  9d81eea5986c8c0e3504b2a7981cd98a3e4805a7f924471397ef03fe4de4ba27
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80061bac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x13000700;
  }
  iVar1 = FUN_80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  if (((**(uint **)(param_1 + 0x214) & 0x200000) != 0) && ((*(ushort *)(param_1 + 0x1f0) & 1) != 0))
  {
    FUN_8005bea0(param_1);
    *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0xfffe;
  }
  if ((**(uint **)(param_1 + 0x214) & 0x400000) != 0) {
    FUN_8008d090();
    *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) | 1;
  }
  return;
}

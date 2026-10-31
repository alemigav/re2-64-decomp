/* FUN_800a5c50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c50  body 0x800a5c50..0x800a5c97  size 75 B
 * sha256  e4178964d9a9dd9ecf2d29d10bcb2b155d6d1d05ac1825c27c6eeb1a3184c3d7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a5c50(undefined2 *param_1,int param_2)

{
  undefined2 *puVar1;
  
  puVar1 = param_1 + param_2;
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  func_0x8000efa0(puVar1,8);
  return;
}

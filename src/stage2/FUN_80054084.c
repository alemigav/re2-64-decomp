/* FUN_80054084
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054084  body 0x80054084..0x800540d3  size 83 B
 * sha256  aaea4b1944a85a43de9d5f38c2a7f84a94465e304a809a2152e2f0d6fbe8ca8a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054084(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2] + (uint)*(ushort *)((int)param_2 + 10);
  param_1[3] = (uint)*(byte *)(param_2 + 3) * 0x1000000 +
               (uint)*(byte *)((int)param_2 + 0xd) * 0x10000 +
               (uint)*(byte *)((int)param_2 + 0xe) * 0x100 + (uint)*(byte *)((int)param_2 + 0xf);
  return;
}

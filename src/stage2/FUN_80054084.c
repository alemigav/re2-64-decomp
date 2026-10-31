/* FUN_80054084
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054084  body 0x80054084..0x800540d3  size 83 B
 * body sha256 d0f379ba1c60108f1bb310040613dd29c9e3f32356511913c06940f9c833cad2
 * provider record sha256 7b1c1b190415c65452f3804aacbc67e92b5dbf92620bed4d7c14dfa96b096508
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

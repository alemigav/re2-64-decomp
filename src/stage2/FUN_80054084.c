/* FUN_80054084
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054084  body 0x80054084..0x800540d3  size 80 B
 * body sha256 29998b093b7eea93501550fbae63aa82f78c72f35fc58845d09c42d705ed74be
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80054084.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;












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

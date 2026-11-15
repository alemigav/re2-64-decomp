/* FUN_80165df8
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165df8  body 0x80165df8..0x80165e9f  size 168 B
 * body sha256 1bad6db80dfbf3f934e605095632faa59e413e4e1c1201405573516a7dd2b829
 * recovered byte-exact (imported: closed by the cast pass, round 1 (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/80165df8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_80165df8(undefined4 param_1,int param_2)

{
  if (*(unsigned char *)(param_2 + 7) == '\0') {
    *(undefined1 *)(param_2 + 1) = 0;
  }
  FUN_80165ea0(param_1,param_2);
  if (*(char *)(param_2 + 1) == '\0') {
    if (*(unsigned char *)(param_2 + 7) == '\x02') {
      *(undefined1 *)(param_2 + 1) = 1;
    }
  }
  else if (*(unsigned char *)(param_2 + 7) == '\x01') {
    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0x7f;
  }
  FUN_80165bd0(param_1,0x83,(int)*(short *)(param_2 + 2),0);
  FUN_80165bd0(param_1,0x84,(int)*(short *)(param_2 + 4),0);
  return;
}

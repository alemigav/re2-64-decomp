/* FUN_80165a0c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165a0c  body 0x80165a0c..0x80165a5b  size 80 B
 * body sha256 7065b2f8ba08a0cccd371ec334847e3403cdfea47d480021fe290796709d4ff8
 * recovered byte-exact (imported: closed by the cast pass, round 1 (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80165a0c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int uint;












void FUN_80165a0c(uint *param_1)

{
  if (((*param_1 & 0x18000000) != 0) && (*(unsigned char *)((int)param_1 + 0x2b5) == '\0')) {
    *(undefined1 *)((int)param_1 + 0x2b5) = 1;
    *(short *)((int)param_1 + 0x1e2) = 0xff74;
    *(undefined2 *)(param_1 + 0x78) = 0xf0;
  }
  FUN_80164d90();
  return;
}

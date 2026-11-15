/* FUN_80163a84
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80163a84  body 0x80163a84..0x80163b33  size 176 B
 * body sha256 407d9d07b487d7ee778df4de0d3da30bd7a493c9dd67bfa0b07cdae2ea2941aa
 * recovered byte-exact (imported: closed by the cast pass, round 1 (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008bef8/80163a84.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_801660f0;
extern unsigned int PTR_LAB_801660d0;












void FUN_80163a84(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned short *)(param_1 + 0x2ce) == 0) {
    func_0x80077d18(5,param_1);
  }
  FUN_80165364(param_1);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  if (*(unsigned char *)(param_1 + 4) == '\x01') {
    (*(code *)(&PTR_LAB_801660d0)[*(byte *)(param_1 + 5)])(param_1);
    (*(code *)(&PTR_FUN_801660f0)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

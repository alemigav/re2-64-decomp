/* FUN_8002e044
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e044  body 0x8002e044..0x8002e0a7  size 100 B
 * body sha256 571c22a3aab16659cf0efada1e1f0551e416818b49778ae816432d221e233dc1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002e044.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef void code();












void FUN_8002e044(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int param_5,
                 int *param_6)

{
  (**(code **)(*(int *)(param_1 + 0x180) + 0xc))(param_1,param_2,*param_3,param_5 + *param_6 * 4);
  *param_6 = *param_6 + 1;
  *param_3 = *param_3 + 1;
  return;
}

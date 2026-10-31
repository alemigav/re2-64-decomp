/* FUN_8004a7c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a7c8  body 0x8004a7c8..0x8004a7f3  size 47 B
 * body sha256 794576bd5907b96f6284c4569c772f13281f4fd88dd4943620591954f1b688c9
 * provider record sha256 5ed79752f456b0b5b67145cde7f796f6490e579d2da9145de9cb5d64589f5bd0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004a7c8(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  FUN_8004a7f4(param_1,param_2,param_3 << 4 | param_4 | 0x200,&param_5);
  return;
}

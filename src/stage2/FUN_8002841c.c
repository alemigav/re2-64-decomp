/* FUN_8002841c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002841c  body 0x8002841c..0x80028447  size 47 B
 * body sha256 aa5c328c75bc80e0870c9477ed4d73a8e7f6b4f6e83c57d593b6abd41858a57f
 * provider record sha256 42d707baa94454aa1ae24c50031f6c24750d13ad5dc4e187e264da1d86c21d35
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002841c(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x118);
  *(undefined4 *)(iVar1 + 0x114) = 0;
  return;
}

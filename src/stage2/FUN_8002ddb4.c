/* FUN_8002ddb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002ddb4  body 0x8002ddb4..0x8002de0b  size 91 B
 * sha256  5ff44898d1f0675407df5f85835ebbbb685ff36f7deaf99c046591fcc96ee855
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002ddb4(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x24);
  *(undefined4 **)(param_1 + 0x164) = puVar1;
  *puVar1 = FUN_8002dbdc;
  puVar1[1] = FUN_8002dd34;
  FUN_8002da50();
  return;
}

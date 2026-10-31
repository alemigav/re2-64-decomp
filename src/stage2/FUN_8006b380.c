/* FUN_8006b380
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b380  body 0x8006b380..0x8006b3db  size 95 B
 * body sha256 252c0c8bce2f7e223cc3d89a3fd28a8e96301d119d6f5c11db6a0f5ffab673fb
 * provider record sha256 5ec8763168a93604262120dbb6d8052f30f47e8a57acb7180c516bc4a8400a27
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006b380(void)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar1 = 0, iVar2 < 5; iVar2 = iVar2 + 1) {
    do {
      FUN_8006b3dc(iVar2,iVar1,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
  }
  return;
}

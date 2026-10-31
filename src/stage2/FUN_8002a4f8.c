/* FUN_8002a4f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002a4f8  body 0x8002a4f8..0x8002a567  size 115 B
 * sha256  20edd1f456580bff9dfbb0a5b8dce6938d5cc55326dd15c667e4225da4bb3447
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002a4f8(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x48);
  iVar2 = 0;
  *(undefined4 **)(param_1 + 0x178) = puVar1;
  *puVar1 = FUN_800298a0;
  puVar1[1] = FUN_80029fa8;
  do {
    puVar1[0xe] = 0;
    puVar1[10] = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 4);
  return;
}

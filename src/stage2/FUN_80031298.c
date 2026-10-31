/* FUN_80031298
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80031298  body 0x80031298..0x8003132b  size 151 B
 * sha256  5266696969fbb8c40289247b612150e227f967a72df0fb7593510aad55922e68
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80031298(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  uVar3 = *(undefined4 *)(param_1 + 0x5c);
  uVar4 = *(undefined4 *)(param_1 + 0x60);
  puVar1 = (undefined4 *)
           (**(code **)(*(int *)(param_1 + 4) + 0x1c))(param_1,*(undefined4 *)(param_2 + 0x1c),0,0);
  FUN_8009ef50(*puVar1,uVar2,uVar3,uVar4,DAT_801137d8,DAT_801137dc,DAT_801137d8);
  return;
}

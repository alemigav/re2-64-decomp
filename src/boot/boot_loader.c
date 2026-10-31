/* boot_loader
 * image   boot (boot), base 0x80000480
 * address 0x80000598  body 0x80000598..0x800006b7  size 291 B
 * body sha256 a0c0e59cd613724c4c15428d1860cd310548e5c38f13f6ee773fb7efda14f1b1
 * provider record sha256 d766b5dcfe993c1c7192fc5b51df8eb2cbc10940afd87e891490663903f73ae8
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void boot_loader(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 auStack_68 [88];
  
  puVar1 = (uint *)cart_record(1);
  _DAT_80132110 = 0;
  _DAT_80112a18 = 0;
  iVar4 = puVar1[1] + (puVar1[1] & 1);
  do {
    uVar2 = FUN_8000be50();
  } while ((uVar2 & 7) != 0);
  pi_dma_raw(0,*puVar1 & 0xfffffff,0x8015b030,iVar4);
  do {
    uVar2 = FUN_8000be50();
  } while ((uVar2 & 7) != 0);
  inflate_init(auStack_68,iVar4 + 0x8015b037U & 0xfffffff8);
  inflate(auStack_68,0x8015b030,puVar1[2],puVar1[1]);
  inflate_free(auStack_68,2);
  puVar3 = (undefined4 *)&DAT_80136d90;
  iVar4 = 0x90a7;
  do {
    *puVar3 = 0;
    iVar4 = iVar4 + -1;
    puVar3 = puVar3 + 1;
  } while (iVar4 != -1);
  stage2_entry();
  return;
}

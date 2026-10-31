/* FUN_8006d7ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d7ac  body 0x8006d7ac..0x8006d88f  size 231 B
 * sha256  2f1587ccede377cb159ed031d43606f90cf13c7217abda3aedf5e278c71a0f8d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d7ac(void)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  bVar1 = *(byte *)(DAT_800df92c + 2);
  uVar4 = 0;
  if (bVar1 != 0) {
    puVar3 = &DAT_800e18f8;
    do {
      uVar4 = uVar4 + 1;
      if (((*puVar3 & 1) != 0) && ((*(byte *)((int)puVar3 + 0x1e1) & 0x80) != 0)) {
        uVar2 = (*(byte *)((int)puVar3 + 0x1e1) & 0x60) >> 5;
        local_20 = 0;
        local_1e = 0xffa6;
        local_1c = 0;
        if (uVar2 == 0) {
          uVar2 = 1;
        }
        FUN_80037780((uVar2 * 8 + 7) * 0x10000 | 0x5002800,0,puVar3 + 5,&local_20);
      }
      puVar3 = puVar3 + 0xda;
    } while (uVar4 < bVar1);
  }
  return;
}

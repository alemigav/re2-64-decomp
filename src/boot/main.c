/* main
 * image   boot (boot), base 0x80000480
 * address 0x80000520  body 0x80000520..0x80000597  size 123 B
 * sha256  aaeb7ff243c69f681d5234970829ba68c9df262dea630fc4d264ef7d95b4fadd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void main(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_800138a0;
  iVar1 = 0x1477;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != -1);
  FUN_800004f0(0);
  vector_installer();
  if (_DAT_80000300 != 0) {
    boot_loader();
    return;
  }
  do {
  } while( true );
}

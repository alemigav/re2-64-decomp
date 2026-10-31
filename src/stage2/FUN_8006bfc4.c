/* FUN_8006bfc4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bfc4  body 0x8006bfc4..0x8006c043  size 131 B
 * body sha256 47134bf21adaaf11ede225405e20ac643f59490bd9529e4d30f6b7af9b8acf89
 * provider record sha256 ec272442cb4c7aeb866fc92266c7b7e83433b17b8dcd5e7104bc6eb458aeb449
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006bfc4(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x800072e0();
  if (DAT_80112969 == '\x03') {
    func_0x80007300(uVar1);
    osSendMesg(0x80139f30,0,0);
  }
  else {
    if ((_DAT_80139e60 & 0x100) != 0) {
      _DAT_80139e60 = _DAT_80139e60 & 0xfffffeff;
      DAT_80112969 = '\x03';
    }
    func_0x80007300(uVar1);
  }
  return;
}

/* FUN_8004ce40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ce40  body 0x8004ce40..0x8004ce8f  size 83 B
 * sha256  64d462cfb70e178fa6b39c2d3f3f4813b824f2a01cbe5032b1eb4100c844560e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ce40(undefined4 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_8010b6b8;
  if (DAT_8010b6b8 != (undefined2 *)0x0) {
    *(undefined4 *)(DAT_8010b6b8 + 0xdc) = param_1;
    *puVar1 = 2;
    func_0x80007450(0x80139b30,0,0);
    func_0x8000dcb0(0);
  }
  return;
}

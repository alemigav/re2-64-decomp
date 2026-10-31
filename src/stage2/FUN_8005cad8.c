/* FUN_8005cad8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005cad8  body 0x8005cad8..0x8005cb0b  size 55 B
 * body sha256 7d4b284651f7c384e1e1ba6fd8aa0a911508ea2576fda51684b98574eec3aa60
 * provider record sha256 1889d1bab14c88ddf472339de35e2b1b18caaf90b732d19bba6954ca6c50a973
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005cad8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}

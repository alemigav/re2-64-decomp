/* FUN_8000db20
 * image   boot (boot), base 0x80000480
 * address 0x8000db20  body 0x8000db20..0x8000db6b  size 79 B
 * sha256  c76e50b90045862f9a7990759b4bcd202c9da2dccd52d8353f8f35fcd57e9add
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8000db20(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_8000db70();
  uVar2 = uVar1 >> 8 & 1;
  if ((uVar1 & 0x80) != 0) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffd | uVar2;
  }
  return uVar2;
}

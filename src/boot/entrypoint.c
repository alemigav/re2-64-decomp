/* entrypoint
 * image   boot (boot), base 0x80000480
 * address 0x80000480  body 0x80000480..0x800004ef  size 115 B
 * sha256  f1dad170fbeedf129e83dd655607e3f55ca31f58cc12178dd0b7960618505762
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x800004c8) */

void processEntry entrypoint(void)

{
  undefined4 in_a0;
  undefined4 *puVar2;
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)&DAT_800138a0;
  do {
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (puVar2 < (undefined4 *)0x80018a80);
  main();
  trap(0x402);
  setCopReg(0,WatchLo,in_a0);
  setCopReg(0,WatchHi,0);
  return;
}

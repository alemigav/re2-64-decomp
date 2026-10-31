/* entrypoint
 * image   boot (boot), base 0x80000480
 * address 0x80000480  body 0x80000480..0x800004ef  size 115 B
 * body sha256 8e393560a715a31c64b540f947ca556980d0e8acbc6430682dca1c7d83a29c1d
 * provider record sha256 935694489977969f5f55ea1f1e327f1d5ed421217d2967f0af690c2c13e22bdd
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

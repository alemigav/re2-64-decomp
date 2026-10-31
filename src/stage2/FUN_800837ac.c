/* FUN_800837ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800837ac  body 0x800837ac..0x800837cf  size 39 B
 * body sha256 8e8abf4b4968d76d5cbed6aca664cd4da3d6861514f50ee19d3af6a808e3a0b3
 * provider record sha256 6e826be371896231b263776896e6d3c43346719ff5e3d46544c4e3b4cdc7d663
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800837ac(int param_1,uint param_2)

{
  return *(uint *)((param_2 >> 5) * 4 + param_1) & 0x80000000U >> (param_2 & 0x1f);
}

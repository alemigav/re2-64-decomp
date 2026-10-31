/* FUN_8008cb48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008cb48  body 0x8008cb48..0x8008cc1b  size 215 B
 * sha256  19862b9ae5cf7796e7e2ba71e56f6114b6052e260d0274e1b3167f16cd0bb0a5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008cb48(uint param_1,uint param_2)

{
  short local_10;
  short local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  if ((DAT_800e110c & 0x8000) != 0) {
    local_c = 0x28;
    local_a = 0x1e;
    local_10 = (short)(param_1 % 3) * 0x28;
    local_e = (short)(param_1 / 3) * 0x1e;
    FUN_80047cc8(&DAT_8012f530,&local_10,(param_2 % 3) * 0x28,(param_2 / 3) * 0x1e & 0xfffe);
  }
  return;
}

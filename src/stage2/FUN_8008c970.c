/* FUN_8008c970
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c970  body 0x8008c970..0x8008ca0b  size 159 B
 * sha256  ee889d7adbfa84925c7f61ce07c97041a65fd1554cdfce2c8032a8562c3da464
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c970(uint param_1,undefined4 param_2)

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
    FUN_80047b74(&DAT_8012f530,&local_10,param_2);
  }
  return;
}

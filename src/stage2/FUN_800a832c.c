/* FUN_800a832c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a832c  body 0x800a832c..0x800a8363  size 59 B
 * body sha256 a155e61d29a47302782e45f881eedb957bd9249af40d1e37acd4a4fd4e15c193
 * provider record sha256 0be8324300cc42427ee08e764a3d2485f061a4f2433d942023062ebf0f7ef970
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a832c(uint param_1,undefined1 param_2)

{
  if (DAT_80136310 != '\0') {
    (&DAT_80147ab4)[(param_1 & 0xff) * 0x28] = param_2;
  }
  return;
}

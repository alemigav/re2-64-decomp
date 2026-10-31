/* FUN_80048390
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048390  body 0x80048390..0x8004842b  size 159 B
 * sha256  fd8d0896cf933c10c88b556f36d77c7195c14287b1570a39642741638ffb191c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
float FUN_80048390(float param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)(int)(param_1 * 20.0);
  if (fVar1 < 0.0) {
    fVar1 = -fVar1;
  }
  if ((int)fVar1 < 0x191) {
    fVar2 = 1.0;
    if (param_1 < 0.0) {
      fVar2 = -1.0;
    }
    fVar2 = fVar2 * *(float *)(&DAT_800f57ec + (int)fVar1 * 4);
  }
  else {
    fVar2 = (float)FUN_80048294();
  }
  return fVar2;
}

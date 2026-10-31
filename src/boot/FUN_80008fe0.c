/* FUN_80008fe0
 * image   boot (boot), base 0x80000480
 * address 0x80008fe0  body 0x80008fe0..0x80009077  size 155 B
 * sha256  8ad87053f71f6d41fc36bbdd222ad2cde99887612f22f36c4c2bd23a3b9f65a3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80008fe0(float *param_1,uint *param_2)

{
  float *pfVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  
  puVar3 = param_2 + 8;
  iVar4 = 0;
  do {
    iVar2 = 0;
    pfVar1 = param_1;
    do {
      fVar6 = *pfVar1;
      fVar5 = pfVar1[1];
      pfVar1 = pfVar1 + 2;
      iVar2 = iVar2 + 1;
      *param_2 = (int)(fVar6 * 65536.0) & 0xffff0000U | (uint)(int)(fVar5 * 65536.0) >> 0x10;
      param_2 = param_2 + 1;
      *puVar3 = (int)(fVar6 * 65536.0) << 0x10 | (int)(fVar5 * 65536.0) & 0xffffU;
      puVar3 = puVar3 + 1;
    } while (iVar2 < 2);
    iVar4 = iVar4 + 1;
    param_1 = param_1 + 4;
  } while (iVar4 < 4);
  return;
}

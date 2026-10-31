/* FUN_800482e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800482e0  body 0x800482e0..0x8004838f  size 179 B
 * body sha256 6ad6cfb435cfb7864a8801500da8fca7b29d9c65bd2a84b45e4fc7a96c0f3e41
 * provider record sha256 ce15185527fd75d6d8a2fec69897f36171d63efdf4d3801fa1fc4c293ba76da2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
float FUN_800482e0(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = param_1;
  if (param_1 < 0.0) {
    fVar2 = -param_1;
  }
  iVar3 = (int)(fVar2 * 20.0);
  if (iVar3 < 400) {
    fVar1 = 1.0;
    if (param_1 < 0.0) {
      fVar1 = -1.0;
    }
    fVar1 = fVar1 * (*(float *)(&DAT_800f57ec + iVar3 * 4) +
                    (*(float *)(&DAT_800f57ec + (iVar3 + 1) * 4) -
                    *(float *)(&DAT_800f57ec + iVar3 * 4)) * (fVar2 * 20.0 - (float)iVar3));
  }
  else {
    fVar1 = (float)FUN_80048294();
  }
  return fVar1;
}

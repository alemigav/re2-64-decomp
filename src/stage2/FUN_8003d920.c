/* FUN_8003d920
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d920  body 0x8003d920..0x8003da97  size 379 B
 * sha256  f7e610049b5b2d26c35c09d5ae1634bf4ee062fc1a1b322abe7141a6d0dfce34
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d920(void)

{
  ushort *puVar1;
  char cVar2;
  undefined1 *puVar3;
  ushort uVar4;
  
  puVar3 = DAT_800ebb94;
  cVar2 = DAT_800ebb94[0x1b];
  if (cVar2 == '\x01') {
    if (*(short *)(DAT_800ebb94 + 0x42) == 0) {
      DAT_800ebb94[0x1b] = 0;
    }
    else {
      puVar1 = (ushort *)(DAT_800ebb94 + 4);
      uVar4 = *(ushort *)(DAT_800ebb94 + 6);
      *(short *)(DAT_800ebb94 + 0x42) = *(short *)(DAT_800ebb94 + 0x42) + -1;
      *(short *)(puVar3 + 4) = (short)(((uint)*puVar1 * 0x370) / 1000);
      *(short *)(puVar3 + 6) = (short)(((uint)uVar4 * 800) / 1000);
    }
  }
  else if (cVar2 < '\x02') {
    if (cVar2 == '\0') {
      *DAT_800ebb94 = 0;
      *(undefined2 *)(puVar3 + 0x18) = 0;
    }
  }
  else if (cVar2 == '\x02') {
    if (*(short *)(DAT_800ebb94 + 0x42) == 0) {
      DAT_800ebb94[0x1b] = 1;
      uVar4 = FUN_80033604();
      *(ushort *)(DAT_800ebb94 + 0x42) = (uVar4 & 1) + 2;
    }
    else {
      puVar1 = (ushort *)(DAT_800ebb94 + 4);
      *(short *)(DAT_800ebb94 + 0x42) = *(short *)(DAT_800ebb94 + 0x42) + -1;
      *(short *)(puVar3 + 4) = (short)(((uint)*puVar1 * 0x3f2) / 1000);
      *(short *)(puVar3 + 6) = (short)(((uint)*(ushort *)(puVar3 + 6) * 0x3ef) / 1000);
    }
  }
  return;
}

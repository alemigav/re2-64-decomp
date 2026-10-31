/* FUN_800a1234
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1234  body 0x800a1234..0x800a12f7  size 199 B
 * body sha256 76baeacbe01c708f9b302df1ff5c5fa939d6909d1ef7510e7b5127e0ad18e4a2
 * provider record sha256 87be80388ca5d9738267d99a243d75af96aacb07eff81a8df652f3f5eca198e5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a1234(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = 0;
  puVar3 = (uint *)&DAT_8013bc90;
  while ((*(char *)((int)puVar3 + 0xfc1) != '\0' || (*puVar3 != (param_1 & 0x7fffffff)))) {
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 0x3fe;
    if (7 < uVar2) {
      uVar2 = 0xffffffff;
LAB_800a127c:
      if (uVar2 != 0xffffffff) {
        if (-1 < (int)uVar2) {
          (&DAT_8013cc50)[uVar2 * 0xff8] = 1;
          return;
        }
        iVar1 = (uVar2 * 0x200 - (uVar2 & 0x7fffffff)) * 8;
        *(byte *)(iVar1 + -0x7fec3382) = *(byte *)(iVar1 + -0x7fec3382) & 0xf7;
      }
      return;
    }
  }
  uVar2 = uVar2 | param_1 & 0x80000000;
  goto LAB_800a127c;
}

/* FUN_8007ab24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ab24  body 0x8007ab24..0x8007ac13  size 240 B
 * body sha256 5c824eaea2ff5812346bd0b6a5c9723414be5ecc8b2a4fdf3a22330abaee1ec7
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007ab24.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned short ushort;












void FUN_8007ab24(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x178,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x2f0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x758,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xeb0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x1318,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
  }
  return;
}

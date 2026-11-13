/* FUN_80167360
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80167360  body 0x80167360..0x80167497  size 312 B
 * body sha256 c62afe76a188178b2b7dfa5c7706ca3c6ae140660ca0696e23e88b2b6454cf79
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/80167360.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












void FUN_80167360(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0xee8,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1fa0 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x38,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x790,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x2668,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x17b8,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1b0,0);
  return;
}

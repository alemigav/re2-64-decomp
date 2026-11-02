/* FUN_800701d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800701d8  body 0x800701d8..0x8007040b  size 564 B
 * body sha256 3c908af227ed747bc59b607cf195ee0a39f7023edf8777923e22c5d9e9967a91
 * provider record sha256 1239194528acd430df045f778af275ba932ad39a360d989002a31d19a967a497
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800701d8(ushort *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  switch(param_2) {
  case 0:
    return (uint)param_1[1];
  case 1:
    uVar1 = (uint)*param_1;
    break;
  case 2:
    return (uint)*(byte *)(param_1 + 2);
  case 3:
    return (uint)*(byte *)((int)param_1 + 5);
  case 4:
    return (uint)*(byte *)(param_1 + 3);
  case 5:
    return (uint)*(byte *)((int)param_1 + 7);
  case 6:
    return (uint)*(byte *)(param_1 + 4);
  case 7:
    return (uint)param_1[0xd5];
  case 8:
    return (uint)*(byte *)(param_1 + 5);
  case 9:
    return (uint)*(byte *)((int)param_1 + 0xb);
  case 10:
    return *(uint *)(param_1 + 8);
  case 0xb:
    return *(uint *)(param_1 + 0x14);
  case 0xc:
    return *(uint *)(param_1 + 0x16);
  case 0xd:
    return *(uint *)(param_1 + 0x18);
  case 0xe:
    return (int)(short)param_1[0x32];
  case 0xf:
    return (int)(short)param_1[0x33];
  case 0x10:
    return (int)(short)param_1[0x34];
  case 0x11:
    return (uint)*(byte *)(param_1 + 0xd1);
  case 0x12:
    return (uint)param_1[0xf8];
  case 0x13:
    return (int)(short)param_1[0x12f];
  case 0x14:
    return (int)(short)param_1[0x130];
  case 0x15:
    return (int)(short)param_1[0x131];
  case 0x16:
    return (uint)param_1[0x134];
  case 0x17:
    return (int)(short)param_1[0x138];
  case 0x18:
    return (int)(short)param_1[0x139];
  case 0x19:
    return (int)(short)param_1[0x13a];
  case 0x1a:
    return (int)(short)param_1[0x13b];
  case 0x1b:
    return (uint)*(byte *)(param_1 + 0xf0);
  case 0x1c:
    return (int)(short)param_1[0xf0];
  case 0x1d:
    return (int)(short)param_1[0xf1];
  case 0x1e:
    return (int)(short)param_1[0xf2];
  case 0x1f:
    return (uint)*(byte *)(param_1 + 0xf5);
  case 0x20:
    return (int)(short)param_1[0x98];
  case 0x21:
    return (int)(short)param_1[0x9a];
  case 0x22:
    return (int)(short)param_1[0x99];
  case 0x23:
    return (uint)param_1[0x9b];
  case 0x24:
    return (uint)param_1[0x9d];
  case 0x25:
    return (uint)param_1[0x9c];
  case 0x26:
    return (int)(short)param_1[0x13d];
  case 0x27:
    return (int)(short)param_1[0xda];
  case 0x28:
    return (int)(short)param_1[0xdb];
  case 0x29:
    return (uint)param_1[0x15a];
  case 0x2a:
    return (uint)param_1[0x15b];
  case 0x2b:
    return (uint)*(byte *)((int)param_1 + 0x26f);
  }
  return uVar1;
}

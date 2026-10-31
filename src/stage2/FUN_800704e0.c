/* FUN_800704e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800704e0  body 0x800704e0..0x800706cb  size 495 B
 * body sha256 1b9cf90aed8d06fcb8536edb5ca27780d4835010586eae56a7510a5b34a10fc7
 * provider record sha256 74793085a0678fc8350196e3384aade4abdcd501af1994797ac683227719e90d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800704e0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  switch(param_2) {
  case 0:
    return param_1 + 2;
  case 1:
    return param_1;
  case 2:
    param_1 = param_1 + 4;
    break;
  case 3:
    param_1 = param_1 + 5;
    break;
  case 4:
    param_1 = param_1 + 6;
    break;
  case 5:
    param_1 = param_1 + 7;
    break;
  case 6:
    param_1 = param_1 + 8;
    break;
  case 7:
    return param_1 + 0x1aa;
  case 8:
    param_1 = param_1 + 10;
    break;
  case 9:
    param_1 = param_1 + 0xb;
    break;
  case 10:
    return param_1 + 0x10;
  case 0xb:
    return param_1 + 0x28;
  case 0xc:
    return param_1 + 0x2c;
  case 0xd:
    return param_1 + 0x30;
  case 0xe:
    return param_1 + 100;
  case 0xf:
    return param_1 + 0x66;
  case 0x10:
    return param_1 + 0x68;
  case 0x11:
    return param_1 + 0x1a2;
  case 0x12:
    return param_1 + 0x1f0;
  case 0x13:
    return param_1 + 0x25e;
  case 0x14:
    return param_1 + 0x260;
  case 0x15:
    return param_1 + 0x262;
  case 0x16:
    return param_1 + 0x268;
  case 0x17:
    return param_1 + 0x270;
  case 0x18:
    return param_1 + 0x272;
  case 0x19:
    return param_1 + 0x274;
  case 0x1a:
    return param_1 + 0x276;
  case 0x1b:
    param_1 = param_1 + 0x1e0;
    break;
  case 0x1c:
    return param_1 + 0x1e0;
  case 0x1d:
    return param_1 + 0x1e2;
  case 0x1e:
    return param_1 + 0x1e4;
  case 0x1f:
    param_1 = param_1 + 0x1ea;
    break;
  case 0x20:
    return param_1 + 0x130;
  case 0x21:
    return param_1 + 0x134;
  case 0x22:
    return param_1 + 0x132;
  case 0x23:
    return param_1 + 0x136;
  case 0x24:
    return param_1 + 0x13a;
  case 0x25:
    return param_1 + 0x138;
  case 0x26:
    return param_1 + 0x27a;
  case 0x27:
    return param_1 + 0x1b4;
  case 0x28:
    return param_1 + 0x1b6;
  case 0x29:
    return param_1 + 0x2b4;
  case 0x2a:
    return param_1 + 0x2b6;
  case 0x2b:
    iVar1 = param_1 + 0x26f;
    DAT_80115120 = DAT_80115120 + 1;
  default:
    return iVar1;
  }
  DAT_80115120 = DAT_80115120 + 1;
  return param_1;
}

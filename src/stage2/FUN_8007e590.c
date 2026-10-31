/* FUN_8007e590
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e590  body 0x8007e590..0x8007e923  size 919 B
 * body sha256 30d5c7b05759d0dbddd5d2e4396ea8801b40ff9a964478ae26c4d7d5d2387e83
 * provider record sha256 d22a16fd5018ff8524e15a7292fde84240009893bcc6e52a80a0ec84e32a89a6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007e590(uint *param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 0x7a) = 6;
    if ((*(byte *)((int)param_1 + 6) & 2) != 0) {
      *(undefined1 *)(param_1 + 0x7a) = 7;
    }
    *(undefined1 *)((int)param_1 + 0x1ea) = 7;
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    param_1[0x7a] = 0x700;
    *(undefined2 *)(param_1 + 0x78) = 0x32;
    *(undefined2 *)((int)param_1 + 0x66) = *(undefined2 *)(param_1 + 0xac);
    *param_1 = *param_1 | 4;
  case 1:
    FUN_80089d54(param_1,param_1[0x87],param_1[0x88],0x200);
    uVar2 = *(ushort *)((int)param_1 + 0x66);
    if ((uVar2 & 0x200) == 0) {
      uVar3 = -(uVar2 >> 2 & 0xff);
    }
    else {
      uVar3 = uVar2 >> 2 & 0xff;
    }
    *(ushort *)((int)param_1 + 0x66) = uVar2 + uVar3;
    if ((*(ushort *)((int)param_1 + 0x66) & 0x3e0) == 0) {
      *(ushort *)((int)param_1 + 0x66) = *(ushort *)((int)param_1 + 0x66) & 0xff00;
      *(undefined1 *)((int)param_1 + 7) = 2;
      if ((*(byte *)((int)param_1 + 6) & 2) != 0) {
        *(undefined1 *)((int)param_1 + 7) = 0;
        *(char *)((int)param_1 + 5) = *(char *)((int)param_1 + 5) + '\x01';
      }
    }
    break;
  case 2:
    *(undefined1 *)((int)param_1 + 7) = 3;
    *(undefined1 *)(param_1 + 0x7a) = 6;
    *(undefined1 *)((int)param_1 + 0x1ea) = 3;
  case 3:
    if (*(char *)((int)param_1 + 0x1e9) == '\x11') {
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    }
    bVar1 = *(byte *)(param_1 + 2);
    if ((bVar1 == 0x45) || (bVar1 == 0x4f)) {
      cVar5 = *(char *)((int)param_1 + 0x1e9);
      cVar4 = 'w';
      if (cVar5 == 'c') {
        *(undefined1 *)((int)param_1 + 0x1ea) = 0;
        if (*(byte *)(param_1 + 2) < 0x10) {
          iVar7 = *(byte *)(param_1 + 2) + 0x10;
        }
        else {
          iVar7 = *(byte *)(param_1 + 2) - 0x40;
        }
        *(undefined2 *)(param_1 + 0x78) = *(undefined2 *)(&DAT_8010ba78 + iVar7 * 2);
        FUN_80032b5c(param_1,0);
        param_1[0xb] = param_1[0xb] - 0x708;
        *(short *)((int)param_1 + 0x25e) = *(short *)((int)param_1 + 0x25e) + -0x708;
        *(undefined2 *)((int)param_1 + 0x1b6) = *(undefined2 *)((int)param_1 + 0x32);
        *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)((int)param_1 + 0x32);
        *(char *)((int)param_1 + 0x1a2) = *(char *)((int)param_1 + 0x1a2) + '\x01';
        *(undefined2 *)(param_1 + 0x6d) = *(undefined2 *)((int)param_1 + 0x2a);
        *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)((int)param_1 + 0x2a);
        *(undefined2 *)((int)param_1 + 0x36) = *(undefined2 *)((int)param_1 + 0x2e);
        cVar5 = *(char *)((int)param_1 + 0x1e9);
        cVar4 = 'w';
      }
    }
    else {
      cVar5 = *(char *)((int)param_1 + 0x1e9);
      cVar4 = '1';
      if (cVar5 == '\x1d') {
        if (bVar1 < 0x10) {
          iVar7 = *(byte *)(param_1 + 2) + 0x10;
        }
        else {
          iVar7 = *(byte *)(param_1 + 2) - 0x40;
        }
        *(undefined2 *)(param_1 + 0x78) = *(undefined2 *)(&DAT_8010ba78 + iVar7 * 2);
        FUN_80032b5c(param_1,0);
        param_1[0xb] = param_1[0xb] - 0x708;
        *(short *)((int)param_1 + 0x25e) = *(short *)((int)param_1 + 0x25e) + -0x708;
        *(undefined2 *)((int)param_1 + 0x1b6) = *(undefined2 *)((int)param_1 + 0x32);
        *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)((int)param_1 + 0x32);
        *(char *)((int)param_1 + 0x1a2) = *(char *)((int)param_1 + 0x1a2) + '\x01';
        *(undefined2 *)(param_1 + 0x6d) = *(undefined2 *)((int)param_1 + 0x2a);
        *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)((int)param_1 + 0x2a);
        *(undefined2 *)((int)param_1 + 0x36) = *(undefined2 *)((int)param_1 + 0x2e);
        cVar5 = *(char *)((int)param_1 + 0x1e9);
        cVar4 = '1';
      }
    }
    if (cVar5 == cVar4) {
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *param_1 = *param_1 & 0xfffffffb;
    }
    cVar5 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x400);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar5;
  default:
    if ((*(uint *)param_1[0x85] & 0x4000) != 0) {
      FUN_80077f30(1,((*(uint *)param_1[0x85] & 0x2000) >> 0xd) * 3 + 4,param_1);
      DAT_800e112a = DAT_800e112a | 4;
    }
    break;
  case 4:
    if (((DAT_800e110c & 0x10000000) == 0) || (param_1 != DAT_800e13ec)) {
      uVar6 = 5;
      if (*(char *)((int)param_1 + 5) == '\x16') {
        uVar6 = 4;
      }
      *(undefined1 *)((int)param_1 + 5) = uVar6;
    }
    else {
      *(undefined1 *)((int)param_1 + 5) = 0;
    }
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 7) = 0;
  }
  return;
}

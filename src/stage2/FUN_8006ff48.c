/* FUN_8006ff48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ff48  body 0x8006ff48..0x800700cf  size 395 B
 * sha256  9ffa378d82b6e307ad53bed98c0ee9c09e417238e77af52f87d022dcb602c660
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006ff48(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar2;
  undefined2 uVar1;
  
  uVar2 = (undefined1)param_3;
  uVar1 = (undefined2)param_3;
  switch(param_2) {
  case 0:
    param_1[1] = uVar1;
    return;
  case 1:
    *param_1 = uVar1;
    return;
  case 2:
    *(undefined1 *)(param_1 + 2) = uVar2;
    return;
  case 3:
    *(undefined1 *)((int)param_1 + 5) = uVar2;
    return;
  case 4:
    *(undefined1 *)(param_1 + 3) = uVar2;
    return;
  case 5:
    *(undefined1 *)((int)param_1 + 7) = uVar2;
    return;
  case 6:
    *(undefined1 *)(param_1 + 4) = uVar2;
    return;
  case 7:
    param_1[0xd5] = uVar1;
    return;
  case 8:
    *(undefined1 *)(param_1 + 5) = uVar2;
    return;
  case 9:
    *(undefined1 *)((int)param_1 + 0xb) = uVar2;
    return;
  case 10:
    *(undefined4 *)(param_1 + 8) = param_3;
    return;
  case 0xb:
    *(undefined4 *)(param_1 + 0x14) = param_3;
    return;
  case 0xc:
    *(undefined4 *)(param_1 + 0x16) = param_3;
    return;
  case 0xd:
    *(undefined4 *)(param_1 + 0x18) = param_3;
    return;
  case 0xe:
    param_1[0x32] = uVar1;
    return;
  case 0xf:
    param_1[0x33] = uVar1;
    return;
  case 0x10:
    param_1[0x34] = uVar1;
    return;
  case 0x11:
    *(undefined1 *)(param_1 + 0xd1) = uVar2;
    return;
  case 0x12:
    param_1[0xf8] = uVar1;
    return;
  case 0x13:
    param_1[0x12f] = uVar1;
    return;
  case 0x14:
    param_1[0x130] = uVar1;
    return;
  case 0x15:
    param_1[0x131] = uVar1;
    return;
  case 0x16:
    param_1[0x134] = uVar1;
    return;
  case 0x17:
    param_1[0x138] = uVar1;
    return;
  case 0x18:
    param_1[0x139] = uVar1;
    return;
  case 0x19:
    param_1[0x13a] = uVar1;
    return;
  case 0x1a:
    param_1[0x13b] = uVar1;
    return;
  case 0x1b:
    *(undefined1 *)(param_1 + 0xf0) = uVar2;
    return;
  case 0x1c:
    param_1[0xf0] = uVar1;
    return;
  case 0x1d:
    param_1[0xf1] = uVar1;
    return;
  case 0x1e:
    param_1[0xf2] = uVar1;
    return;
  case 0x1f:
    *(undefined1 *)(param_1 + 0xf5) = uVar2;
    return;
  case 0x20:
    param_1[0x98] = uVar1;
    return;
  case 0x21:
    param_1[0x9a] = uVar1;
    return;
  case 0x22:
    param_1[0x99] = uVar1;
    return;
  case 0x23:
    param_1[0x9b] = uVar1;
    return;
  case 0x24:
    param_1[0x9d] = uVar1;
    return;
  case 0x25:
    param_1[0x9c] = uVar1;
    return;
  case 0x26:
    param_1[0x13d] = uVar1;
    return;
  case 0x27:
    param_1[0xda] = uVar1;
    return;
  case 0x28:
    param_1[0xdb] = uVar1;
    return;
  case 0x29:
    param_1[0x15a] = uVar1;
    return;
  case 0x2a:
    param_1[0x15b] = uVar1;
    return;
  case 0x2b:
    *(undefined1 *)((int)param_1 + 0x26f) = uVar2;
  }
  return;
}

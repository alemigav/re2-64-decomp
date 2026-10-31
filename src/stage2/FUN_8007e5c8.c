/* FUN_8007e5c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e5c8  body 0x8007e5c8..0x8007e61b  size 87 B
 * body sha256 e10a578cca32948c0cbb43a7c66ea0b01ca6b5668085ffe911b22d738b701824
 * provider record sha256 db274691b983d6734eb82a10dea61ae80488da40bd459187275a9cf6ad3e4b9e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e5c0::caseD_0(void)

{
  ushort uVar1;
  ushort uVar2;
  uint *unaff_s0;
  
  *(undefined1 *)((int)unaff_s0 + 7) = 1;
  *(undefined1 *)(unaff_s0 + 0x7a) = 6;
  if ((*(byte *)((int)unaff_s0 + 6) & 2) != 0) {
    *(undefined1 *)(unaff_s0 + 0x7a) = 7;
  }
  *(undefined1 *)((int)unaff_s0 + 0x1ea) = 7;
  *(undefined1 *)((int)unaff_s0 + 0x1e9) = 0;
  unaff_s0[0x7a] = 0x700;
  *(undefined2 *)(unaff_s0 + 0x78) = 0x32;
  *(undefined2 *)((int)unaff_s0 + 0x66) = *(undefined2 *)(unaff_s0 + 0xac);
  *unaff_s0 = *unaff_s0 | 4;
  FUN_80089d54();
  uVar1 = *(ushort *)((int)unaff_s0 + 0x66);
  if ((uVar1 & 0x200) == 0) {
    uVar2 = -(uVar1 >> 2 & 0xff);
  }
  else {
    uVar2 = uVar1 >> 2 & 0xff;
  }
  *(ushort *)((int)unaff_s0 + 0x66) = uVar1 + uVar2;
  if ((*(ushort *)((int)unaff_s0 + 0x66) & 0x3e0) == 0) {
    *(ushort *)((int)unaff_s0 + 0x66) = *(ushort *)((int)unaff_s0 + 0x66) & 0xff00;
    *(undefined1 *)((int)unaff_s0 + 7) = 2;
    if ((*(byte *)((int)unaff_s0 + 6) & 2) != 0) {
      *(undefined1 *)((int)unaff_s0 + 7) = 0;
      *(char *)((int)unaff_s0 + 5) = *(char *)((int)unaff_s0 + 5) + '\x01';
    }
  }
  return;
}

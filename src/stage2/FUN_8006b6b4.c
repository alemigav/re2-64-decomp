/* FUN_8006b6b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b6b4  body 0x8006b6b4..0x8006b89f  size 495 B
 * sha256  fd9b116d23a6c22de2a7fefdc32c8b0e8a27d8002c8ed07492436689b808c356
 * callees 7 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006b6b4(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  uVar1 = func_0x800072e0();
  if (DAT_8011277e != 5) {
    iVar3 = 10;
    if (DAT_8011296c == '\x04') {
      iVar3 = 4;
    }
    uVar5 = 0xb;
    if ((((DAT_8011277c != '\x04') && (uVar5 = 3, DAT_8011296b != '\x04')) &&
        (uVar5 = 0, DAT_80112968 != '\x04')) &&
       ((uVar5 = 1, DAT_80112969 != '\x04' && (uVar5 = 10, DAT_8011296a == '\x04')))) {
      uVar5 = 2;
    }
    uVar2 = (uint)DAT_8011277d;
    if ((&DAT_80112968)[uVar2] == '\x04') {
      uVar5 = uVar2;
    }
    if (DAT_8011277e == 10) {
      bVar4 = (byte)uVar5;
      if (uVar5 == 0xb) {
        func_0x8000d460(DAT_80112778);
        func_0x8000d66c(DAT_80112778);
        DAT_8011277c = '\x06';
        DAT_8011277e = bVar4;
      }
      else if (iVar3 == 10) {
        if ((uVar5 != 10) && ((uVar2 == 10 || (uVar5 == uVar2)))) {
          (&DAT_80112968)[uVar5] = 6;
          DAT_8011277e = bVar4;
          func_0x8000f020();
          func_0x8000d460(&DAT_80112868 + uVar5 * 0x40);
          func_0x8000d66c(&DAT_80112868 + uVar5 * 0x40);
          FUN_8006b3dc(uVar5,3,1);
          DAT_8011277d = bVar4;
          func_0x80006f50(0x3c0);
        }
      }
      else {
        DAT_8011296c = '\x06';
        DAT_8011277e = 4;
        func_0x8000f020();
        func_0x8000d460(DAT_80112a20);
        func_0x8000d66c(DAT_80112a20);
        FUN_8006b3dc(iVar3,1,1);
      }
    }
  }
  func_0x80007300(uVar1);
  return;
}

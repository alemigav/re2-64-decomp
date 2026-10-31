/* func_8009de58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009de58  body 0x8009de58..0x8009e583  size 1839 B
 * body sha256 5bb4c5111c50001fb37af5b788cbfe3fd58a16ca3337b6280f9175d2015789d2
 * provider record sha256 82d2784b7685c3392cc1f884da986f51cb7bb3c3a6a85f3763eba666664059bc
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
void func_8009de58(void)

{
  int iVar1;
  undefined4 in_v1;
  
  switch(in_v1) {
  case 0:
    FUN_8009e93c(3,0,0xffff,0);
    FUN_800777d8(0x1006b00);
    DAT_80012888 = 0x6b;
    DAT_8013273a = 0;
    DAT_8013272e = 1;
    DAT_8013272b = 3;
    goto switchD_8009de84_default;
  case 1:
    if (DAT_8013273a == 0xf0) {
      func_0x80004a6c(1,6);
    }
    if (DAT_8013273a == 0xfa) {
      DAT_80132740 = 3;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0x20b) goto switchD_8009de84_default;
    DAT_80132740 = 3;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 2;
    break;
  case 2:
    if (DAT_8013273a == 1) {
      func_0x80004a6c(1,7);
    }
    if (DAT_8013273a == 0xb) {
      DAT_80132740 = 0xc;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0x1b6) goto switchD_8009de84_default;
    DAT_80132740 = 0xc;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 3;
    break;
  case 3:
    if (DAT_8013273a == 10) {
      func_0x80004a6c(1,8);
    }
    if (DAT_8013273a == 0x14) {
      DAT_80132740 = 0x30;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0x8c) goto switchD_8009de84_default;
    DAT_80132740 = 0x30;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 4;
    break;
  case 4:
    if (DAT_8013273a == 1) {
      func_0x80004a6c(1,9);
    }
    if (DAT_8013273a == 0xb) {
      DAT_80132740 = 0xc0;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0x142) goto switchD_8009de84_default;
    DAT_80132740 = 0xc0;
    FUN_8009e8d4(0xb,0);
    FUN_80025f78(0,2,&DAT_80132628);
    FUN_80025f78(1,2,&DAT_80132644);
    FUN_8009ce40();
    DAT_8013272e = 5;
    break;
  case 5:
    if (DAT_8013273a == 0x80) {
      func_0x80004a6c(1,0xe);
    }
    if (DAT_8013273a != 0x151) goto switchD_8009de84_default;
    FUN_8009ced8();
    DAT_80132728 = 8;
    DAT_8013272e = 6;
    break;
  case 6:
    if (DAT_8013273a == 0x5a) {
      func_0x80004a6c(1,10);
    }
    if (DAT_8013273a == 100) {
      DAT_80132740 = 0x300;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0x150) goto switchD_8009de84_default;
    DAT_80132740 = 0x300;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 7;
    break;
  case 7:
    if (DAT_8013273a == 1) {
      func_0x80004a6c(1,0xb);
    }
    if (DAT_8013273a == 0xb) {
      DAT_80132740 = 0xc00;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0x10a) goto switchD_8009de84_default;
    DAT_80132740 = 0xc00;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 8;
    break;
  case 8:
    if (DAT_8013273a == 1) {
      func_0x80004a6c(1,0xc);
    }
    if (DAT_8013273a == 0xb) {
      DAT_80132740 = 0x3000;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x1b9) {
      DAT_80132740 = 0x3000;
      FUN_8009e8d4(0xb,0);
      FUN_80025f78(1,2,&DAT_80132660);
      FUN_8009ce40();
    }
    if (DAT_8013273a == 0x1c3) {
      DAT_80132740 = 0xc000;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x2e2) {
      DAT_80132740 = 0xc000;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a != 0x300) goto switchD_8009de84_default;
    DAT_8013272e = 9;
    break;
  case 9:
    if (DAT_8013273a == 1) {
      func_0x80004a6c(1,0xd);
    }
    if (DAT_8013273a == 0xb) {
      DAT_80132740 = 0x30000;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x181) {
      DAT_80132740 = 0x30000;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a == 0x253) {
      FUN_80077430(0x5a,0x18);
      DAT_80132728 = 8;
      FUN_8009ced8();
      DAT_80132729 = 0;
      DAT_8013272c = 2;
    }
    if ((DAT_8013273a < 0x254) || (iVar1 = FUN_8002767c(DAT_8013272b), iVar1 == 0))
    goto switchD_8009de84_default;
    DAT_80132740 = 0;
    FUN_8009e8d4(0,1);
    DAT_80132729 = 1;
    DAT_8013272e = 10;
    goto LAB_8009e4e4;
  case 10:
    if ((DAT_8013273a != 100) || (DAT_80119e70 != '\0')) goto switchD_8009de84_default;
    DAT_800e90f8 = 1;
    DAT_800e110c = DAT_800e110c & 0xffffffef;
    FUN_8006c070(0);
    FUN_8009f320(3);
    DAT_8013272e = 0xb;
    goto LAB_8009e4e4;
  case 0xb:
    if ((DAT_800e10ec & 0x200) != 0) goto switchD_8009de84_default;
    FUN_8006c070(1);
    DAT_8013272e = 0xc;
    goto LAB_8009e524;
  case 0xc:
    if (DAT_8013273a != 1) goto switchD_8009de84_default;
    FUN_8006c070(0);
    FUN_8009f320(0x10);
    DAT_8013272e = 0xd;
LAB_8009e4e4:
    DAT_8013273a = 0;
    goto switchD_8009de84_default;
  case 0xd:
    if ((DAT_800e10ec & 0x200) != 0) goto switchD_8009de84_default;
    FUN_8006c070(1);
    DAT_8013272e = 0xe;
LAB_8009e524:
    DAT_8013273a = 0;
    goto switchD_8009de84_default;
  case 0xe:
    if (DAT_8013273a == 10) {
      DAT_8013272a = 3;
      DAT_8013273c = 4;
    }
  default:
    goto switchD_8009de84_default;
  }
  DAT_8013273a = 0;
switchD_8009de84_default:
  DAT_8013273a = DAT_8013273a + 1;
  return;
}

/* FUN_8002cc54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002cc54  body 0x8002cc54..0x8002cf1f  size 719 B
 * sha256  0c7a6d3fbcddc115552d95d4886ad74c9db50cb67faf50ee1c4687e073589399
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002cc54(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  do {
    while( true ) {
      if (param_1[0x58] == 0) {
        if (*(int *)(param_1[0x5d] + 0x50) == 0) {
          iVar1 = FUN_8002cb54(param_1);
        }
        else {
          iVar1 = FUN_8002c9c0(param_1);
        }
        if (iVar1 == 0) {
          return 2;
        }
      }
      iVar1 = param_1[0x58];
      if (0xcf < iVar1) break;
      if (iVar1 < 0xcd) {
        if (iVar1 == 0xc4) {
          iVar1 = FUN_8002bf74(param_1);
        }
        else if (iVar1 < 0xc5) {
          if (0xc1 < iVar1) goto LAB_8002cdc4;
          if (iVar1 < 0xc0) {
            if (iVar1 != 1) goto LAB_8002cedc;
            goto LAB_8002ce90;
          }
          param_1[0x39] = 0;
          iVar1 = FUN_8002afa4(param_1);
        }
        else if (iVar1 == 0xc9) {
          param_1[0x39] = 1;
          iVar1 = FUN_8002afa4(param_1);
        }
        else {
          if ((iVar1 < 0xc9) || (iVar1 < 0xcc)) goto LAB_8002cdc4;
          iVar1 = FUN_8002bd80(param_1);
        }
LAB_8002cecc:
        if (iVar1 == 0) {
          return 2;
        }
        param_1[0x58] = 0;
      }
      else {
LAB_8002cdc4:
        iVar1 = *param_1;
        uVar2 = 0x34;
LAB_8002cee4:
        *(undefined4 *)(iVar1 + 0x14) = uVar2;
        *(int *)(*param_1 + 0x18) = param_1[0x58];
        (**(code **)*param_1)(param_1);
        param_1[0x58] = 0;
      }
    }
    if (iVar1 == 0xdb) {
      iVar1 = FUN_8002c3b4(param_1);
      goto LAB_8002cecc;
    }
    if (0xdb < iVar1) {
      if (iVar1 < 0xf0) {
        if (iVar1 < 0xe0) {
          if (iVar1 == 0xdc) {
            iVar1 = FUN_8002c8bc(param_1);
          }
          else {
            if (iVar1 != 0xdd) goto LAB_8002cedc;
            iVar1 = FUN_8002c74c(param_1);
          }
        }
        else {
          iVar1 = (**(code **)(param_1[0x5d] + (iVar1 + -0xe0) * 4 + 0x10))(param_1);
        }
      }
      else {
        if (iVar1 != 0xfe) goto LAB_8002cedc;
        iVar1 = (**(code **)(param_1[0x5d] + 0xc))(param_1);
      }
      goto LAB_8002cecc;
    }
    if (iVar1 == 0xd8) {
      iVar1 = FUN_8002aee0(param_1);
      goto LAB_8002cecc;
    }
    if (0xd7 < iVar1) {
      if (iVar1 == 0xd9) {
        *(undefined4 *)(*param_1 + 0x14) = 0x4d;
        (**(code **)(*param_1 + 4))(param_1,1);
        param_1[0x58] = 0;
        return 1;
      }
      if (iVar1 == 0xda) {
        iVar1 = FUN_8002b490(param_1);
        if (iVar1 == 0) {
          return 2;
        }
        param_1[0x58] = 0;
        return 0;
      }
LAB_8002cedc:
      iVar1 = *param_1;
      uVar2 = 0x3c;
      goto LAB_8002cee4;
    }
LAB_8002ce90:
    *(undefined4 *)(*param_1 + 0x14) = 0x54;
    *(int *)(*param_1 + 0x18) = param_1[0x58];
    (**(code **)(*param_1 + 4))(param_1,1);
    param_1[0x58] = 0;
  } while( true );
}

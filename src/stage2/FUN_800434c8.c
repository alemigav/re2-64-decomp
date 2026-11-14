/* FUN_800434c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800434c8  body 0x800434c8..0x8004355f  size 152 B
 * body sha256 0d5432631125fe0d6fd557efb4f6805aedcc9bab45f0504ba65f10e83e81cffb
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (36 of 38 -> 38 of 38) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800434c8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern short _DAT_80139a78;














int FUN_800434c8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,int *param_7)

{
  FUN_80042de0();
  FUN_8004341c(param_4);
  FUN_80042de0(param_2);
  FUN_8004341c(param_5);
  FUN_80042de0(param_3);
  FUN_8004341c(param_6);
  *param_7 = (int)_DAT_80139a78;
  return (int)_DAT_80139a78;
}

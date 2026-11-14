/* FUN_80043560
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043560  body 0x80043560..0x8004361f  size 192 B
 * body sha256 8c2531b07ea9e97e0ae00e32c9ccc7eaa226344d2eb5847b653812feb2edfea5
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (46 of 48 -> 48 of 48) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80043560.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern short _DAT_80139a78;














int FUN_80043560(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                int *param_9)

{
  FUN_80042de0();
  FUN_8004341c(param_5);
  FUN_80042de0(param_2);
  FUN_8004341c(param_6);
  FUN_80042de0(param_3);
  FUN_8004341c(param_7);
  FUN_80042de0(param_4);
  FUN_8004341c(param_8);
  *param_9 = (int)_DAT_80139a78;
  return (int)_DAT_80139a78;
}

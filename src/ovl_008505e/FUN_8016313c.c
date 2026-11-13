/* FUN_8016313c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016313c  body 0x8016313c..0x80163247  size 268 B
 * body sha256 059dabc7a078a805cbd4dc7f236d2155e794161aca33875c8cf1499faceb9f5b
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/8016313c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;












undefined4 FUN_8016313c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)((int)param_1 + 7) == '\0') {
    func_0x80032bd8(param_1,0,0);
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
    if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
      *(undefined1 *)((int)param_1 + 7) = 1;
      *(undefined1 *)((int)param_1 + 0x2b5) = 0;
      param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
      *param_1 = *param_1 & 0xefffffff | 0x4000000;
      func_0x80077d18(10,param_1);
    }
    if (*(unsigned char *)((int)param_1 + 0x1e9) != '\b') {
      func_0x80089d54(param_1,param_2,param_3,0x100);
      return 0;
    }
  }
  else {
    func_0x80032b5c(param_1,0);
    FUN_8016655c(param_1,0x40,0xf0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

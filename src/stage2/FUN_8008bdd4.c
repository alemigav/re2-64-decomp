/* FUN_8008bdd4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008bdd4  body 0x8008bdd4..0x8008be27  size 84 B
 * body sha256 0831a1ed429c5843c789ab660f1e656b92574210fcc130c150b1745ffc6c461f
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (20 of 21 -> 21 of 21) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8008bdd4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned char DAT_8012bf98;












void FUN_8008bdd4(void)

{
  int iVar1;
  
  iVar1 = FUN_8002767c(0);
  if (iVar1 != 0) {
    FUN_800274f8(0x200,0,7,1);
    FUN_800275c0(0,0x7fff,0xffff,0);
    DAT_8012bf98 = 2;
  }
  return;
}

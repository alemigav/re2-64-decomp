/* FUN_80052f40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052f40  body 0x80052f40..0x80052ffb  size 191 B
 * sha256  4ec92a1350e5057acb0f927c70d6d3f32d1c49baba548fdd6c496c937f580d21
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80052f40(void)

{
  FUN_8004ce90(0);
  FUN_80027650(0);
  DAT_8010bfa8 = DAT_8010bfa8 << 1 | 1;
  do {
    if ((DAT_800e10f0 & 3) == 0) {
      FUN_800540f0();
    }
    else {
      if ((DAT_800e10f0 & 3) != 1) {
        DAT_8010bfa8 = DAT_8010bfa8 << 1;
        FUN_8004cec4(0);
        DAT_800e9182 = 2;
        FUN_8004cdd4();
        return;
      }
      FUN_8005497c();
    }
    FUN_8004cd88(1);
  } while( true );
}

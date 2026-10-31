/* FUN_8000d020
 * image   boot (boot), base 0x80000480
 * address 0x8000d020  body 0x8000d020..0x8000d047  size 43 B
 * body sha256 bf248149f441c4ef9bdd5d6ad8650acf2e1616407774cc54f8543b225eb96f68
 * provider record sha256 e8576e512e19ed8730f97e693ab81d78494ccb551a252b653c35afc3cf432bf9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000d020(void)

{
  osSendMesg(0x800177c0,0,0);
  return;
}

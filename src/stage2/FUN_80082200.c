/* FUN_80082200
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082200  body 0x80082200..0x80082223  size 39 B
 * body sha256 2e65ce313818677a2c636f42a9c71693fe36ec67bd10364f56255915a8d59cea
 * provider record sha256 c5e46cc8fb0772f8baa8115f5d37c1f90c46ddc1027c6a81f99ae63d166b795d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082200(undefined1 *param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_3 + -1;
  if (param_3 != 0) {
    do {
      *param_1 = param_2;
      iVar1 = iVar1 + -1;
      param_1 = param_1 + 1;
    } while (iVar1 != -1);
  }
  return;
}

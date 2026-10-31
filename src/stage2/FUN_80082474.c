/* FUN_80082474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082474  body 0x80082474..0x80082497  size 39 B
 * sha256  43a61137e7c16783ae92dc90d9ca7384c79af78f25b71b2e84f331638addb0d8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082474(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_3;
  do {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (param_1 < puVar1);
  return;
}

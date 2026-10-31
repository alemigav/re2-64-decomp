/* FUN_80002360
 * image   boot (boot), base 0x80000480
 * address 0x80002360  body 0x80002360..0x800023d7  size 123 B
 * sha256  afc63d2a43c77d401a78eb9888173425dbe3e9e507b2a630689e2b67f5da33c8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80002360(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(param_5 + 0x20))(*(undefined4 *)(param_5 + 0x28),1,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 4) = param_1;
    *(undefined1 *)((int)puVar1 + 0x11) = param_2;
    puVar1[5] = param_3;
    puVar1[6] = param_4;
  }
  return;
}

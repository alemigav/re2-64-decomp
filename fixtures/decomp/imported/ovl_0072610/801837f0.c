typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
void func_80183770_ovl_02(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
int __repair_literal;

    u8 *p;
    u8 *q;
    u8 *r;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    s32 i;

    r = arg0 + arg2;
    i = 0;
__repair_literal = 0;

    if (arg4 > __repair_literal) {
        p = arg0;
        q = arg1;
        do {
            a = p[0];
            c = r[0];
            b = p[1];
            d = r[1];
            q[0] = (u8)((a + b + c + d + 2) >> 2);
            a = p[2];
            c = r[2];
            q[1] = (u8)((b + a + d + c + 2) >> 2);
            b = p[3];
            d = r[3];
            q[2] = (u8)((a + b + c + d + 2) >> 2);
            a = p[4];
            c = r[4];
            q[3] = (u8)((b + a + d + c + 2) >> 2);
            b = p[5];
            d = r[5];
            q[4] = (u8)((a + b + c + d + 2) >> 2);
            a = p[6];
            c = r[6];
            q[5] = (u8)((b + a + d + c + 2) >> 2);
            b = p[7];
            d = r[7];
            q[6] = (u8)((a + b + c + d + 2) >> 2);
            a = p[8];
            c = r[8];
            q[7] = (u8)((b + a + d + c + 2) >> 2);
            b = p[9];
            d = r[9];
            q[8] = (u8)((a + b + c + d + 2) >> 2);
            a = p[10];
            c = r[10];
            q[9] = (u8)((b + a + d + c + 2) >> 2);
            b = p[11];
            d = r[11];
            q[10] = (u8)((a + b + c + d + 2) >> 2);
            a = p[12];
            c = r[12];
            q[11] = (u8)((b + a + d + c + 2) >> 2);
            b = p[13];
            d = r[13];
            q[12] = (u8)((a + b + c + d + 2) >> 2);
            a = p[14];
            c = r[14];
            q[13] = (u8)((b + a + d + c + 2) >> 2);
            b = p[15];
            d = r[15];
            q[14] = (u8)((a + b + c + d + 2) >> 2);
            q[15] = (u8)((b + p[16] + d + r[16] + 2) >> 2);
            p += arg3;
            r += arg3;
            q += arg3;
        } while (++i < arg4);
    }
}
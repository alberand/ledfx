#include <stdint.h>

#define RAND16_SEED  1337
uint16_t rand16seed = RAND16_SEED;


// memset8, memcpy8, memmove8:
//  optimized avr replacements for the standard "C" library
//  routines memset, memcpy, and memmove.
//
//  There are two techniques that make these routines
//  faster than the standard avr-libc routines.
//  First, the loops are unrolled 2X, meaning that
//  the average loop overhead is cut in half.
//  And second, the compare-and-branch at the bottom
//  of each loop decrements the low byte of the
//  counter, and if the carry is clear, it branches
//  back up immediately.  Only if the low byte math
//  causes carry do we bother to decrement the high
//  byte and check that result for carry as well.
//  Results for a 100-byte buffer are 20-40% faster
//  than standard avr-libc, at a cost of a few extra
//  bytes of code.

#if defined(__AVR__)
extern "C" {
//__attribute__ ((noinline))
void * memset8 ( void * ptr, uint8_t val, uint16_t num )
{
    asm volatile(
         "  movw r26, %[ptr]        \n\t"
         "  sbrs %A[num], 0         \n\t"
         "  rjmp Lseteven_%=        \n\t"
         "  rjmp Lsetodd_%=         \n\t"
         "Lsetloop_%=:              \n\t"
         "  st X+, %[val]           \n\t"
         "Lsetodd_%=:               \n\t"
         "  st X+, %[val]           \n\t"
         "Lseteven_%=:              \n\t"
         "  subi %A[num], 2         \n\t"
         "  brcc Lsetloop_%=        \n\t"
         "  sbci %B[num], 0         \n\t"
         "  brcc Lsetloop_%=        \n\t"
         : [num] "+r" (num)
         : [ptr]  "r" (ptr),
           [val]  "r" (val)
         : "memory"
         );
    return ptr;
}



//__attribute__ ((noinline))
void * memcpy8 ( void * dst, const void* src, uint16_t num )
{
    asm volatile(
         "  movw r30, %[src]        \n\t"
         "  movw r26, %[dst]        \n\t"
         "  sbrs %A[num], 0         \n\t"
         "  rjmp Lcpyeven_%=        \n\t"
         "  rjmp Lcpyodd_%=         \n\t"
         "Lcpyloop_%=:              \n\t"
         "  ld __tmp_reg__, Z+      \n\t"
         "  st X+, __tmp_reg__      \n\t"
         "Lcpyodd_%=:               \n\t"
         "  ld __tmp_reg__, Z+      \n\t"
         "  st X+, __tmp_reg__      \n\t"
         "Lcpyeven_%=:              \n\t"
         "  subi %A[num], 2         \n\t"
         "  brcc Lcpyloop_%=        \n\t"
         "  sbci %B[num], 0         \n\t"
         "  brcc Lcpyloop_%=        \n\t"
         : [num] "+r" (num)
         : [src] "r" (src),
           [dst] "r" (dst)
         : "memory"
         );
    return dst;
}

//__attribute__ ((noinline))
void * memmove8 ( void * dst, const void* src, uint16_t num )
{
    if( src > dst) {
        // if src > dst then we can use the forward-stepping memcpy8
        return memcpy8( dst, src, num);
    } else {
        // if src < dst then we have to step backward:
        dst = (char*)dst + num;
        src = (char*)src + num;
        asm volatile(
             "  movw r30, %[src]        \n\t"
             "  movw r26, %[dst]        \n\t"
             "  sbrs %A[num], 0         \n\t"
             "  rjmp Lmoveven_%=        \n\t"
             "  rjmp Lmovodd_%=         \n\t"
             "Lmovloop_%=:              \n\t"
             "  ld __tmp_reg__, -Z      \n\t"
             "  st -X, __tmp_reg__      \n\t"
             "Lmovodd_%=:               \n\t"
             "  ld __tmp_reg__, -Z      \n\t"
             "  st -X, __tmp_reg__      \n\t"
             "Lmoveven_%=:              \n\t"
             "  subi %A[num], 2         \n\t"
             "  brcc Lmovloop_%=        \n\t"
             "  sbci %B[num], 0         \n\t"
             "  brcc Lmovloop_%=        \n\t"
             : [num] "+r" (num)
             : [src] "r" (src),
               [dst] "r" (dst)
             : "memory"
             );
        return dst;
    }
}


} /* end extern "C" */

#endif /* AVR */

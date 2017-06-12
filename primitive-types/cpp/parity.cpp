/* Brute forcing this problem is pretty simple: Iteratively test the value of each bit while tracking the number of
 * 1s seen so far. This runs O(n). */
short Parity(unsigned long x) {
    short result = 0;
    while (x) {
        result ^= (x & 1);
        x >>= 1;
    }
    return result;
}


/* Here is the CPP for the best possible coding solution.  This is a fairly complicated method. Check page 30 for the
 * solution explanation */
short Parity(unsigned long x) {
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}
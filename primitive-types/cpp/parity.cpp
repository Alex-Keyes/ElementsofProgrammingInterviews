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
# Things to know about Primitive Types

Quick Bitwise Operation Primer
==

BitShifting
===
`<<=` and `>>=` are bit shifting operators.

`<<=` shifts the bits so that they are more significant, while `>>=` shifts them so they are less.

For example: 
```
int a = 1;
a <<= 1;
```
Now `a` is equal to 2. 

This is what the bits stored on the hard drive referred to as `a` in this example look like:

| Code | Space on hard drive for `a` | integer value of `a` |
|------|-----------------------------|----------------------|
|`int a = 1;`   |   `0000 0000 0000 0001`|1|
|`a <<= 1;`    |   `0000 0000 0000 0010`|2|

So, you see, after the `<<=` the value of `a` is actually `2`.
If we shifted it again in the same direction, it would then be `4`.
Another quick example:

| Code | Space on hard drive for `a`|integer value of `a`|
|------|-----|----|
|`int a = 3;`   |   `0000 0000 0000 0011`|3
|`a <<= 2;`    |   `0000 0000 0000 1100`|12|

In this case, we started with `a` being `3`, we shift it left 2 spaces, which ends up with `a` being equal to `12`.

The opposite holds true for `>>=`. If you do a right shift on `3` by 1 space, you'll end up with 1.

| Code | Space on hard drive for `a`|integer value of `a`|
|------|-----|----|
|`int a = 3;`   |   `0000 0000 0000 0011`|3
|`a >>= 1;`    |   `0000 0000 0000 0001`|1|

The "extra" 1 that we shifted out of range, just goes away.

Bitwise Operations
===
Now, on to `&=`, `^=`, `|=`. These are doing the basic bitwise operations.

`&` is a bitwise `and`, the resulting bits will be 'on' if the corresponding bits in both variables are on

`|` is a bitwise `or`, the resulting bits will be 'on' if the *either* the original bits *or* the comparative bits are on

`^` is a bitwise `exlusive or`, the resulting bits will be 'on' *only* if the bits in the original were on *or* the comparitive bits are on, *but not if both are*

Examples for these cases:
`&=` case

|   Code          |    Space on hard drive for `a`| integer value of `a` or `b`
|-----|-----|-----|
|`int a = 3;`   |   `0000 0000 0000 0011`| a is `3`
|`int b = 2;`   |   `0000 0000 0000 0010`| b is `2`
|`a &= b;`    |   `0000 0000 0000 0010`| a is `2`

`|=` case

|   Code          |    Space on hard drive for `a` | integer value of `a` or `b`|
|---|---|---|
|`int a = 11;`  |   `0000 0000 0000 1011` | a is `11`|
|`int b = 4;`   |   `0000 0000 0000 0100` | b is `4`|
| `a l= b;`    |   `0000 0000 0000 1111` | a is `15`|

That table doesn't format correctly... It interprets the `|=` as a column separator, so imagine that the `l=` in the bottom left cell is actually a `|=` ;-)

`^=` case

|   Code          |    Space on hard drive for `a`|integer value of `a` or `b`|
|---|---|---|
|`int a = 11;`  |   `0000 0000 0000 1011` | a is `11`|
|`int b = 2;`   |   `0000 0000 0000 1110`| b is `2`|
|`a ^= b;`    |   `0000 0000 0000 0101` | a is `5`|

There are actually a few other logical bitwise operations... Here is a breakdown of all that I remember off-hand:
* `AND` - `&`- If both inputs are true, then the output is true.
* `OR` - `|`- If either of the inputs are true, then the output is true.
* `XOR` - `^` - EXCLUSIVE OR - If either, but not both, of the inputs is true, then the output is true.
* `NOR` - NOT OR - The opposite of `OR`, if at least one input is true, then the output is false.
* `NAND` - NOT AND - The opposite of `AND`, if at least one input if false, then the output is true.
* `XNOR` - NOT EXCLUSIVE OR - The opposite of `XOR`, if both inputs are the same, the output is true.

In  my day, the way that we learned about bitwise operations is by using what are called `Truth Tables`. 

Here is a quick one-off truth table that runs through the bitwise operations given two inputs `p` and `q`

| P | Q | `AND` | `OR` | `XOR` | `NOR` | `NAND` | `XNOR`|
|---|---|---|---|---|---|---|---|
|1|1|1|1|0|0|0|1|
|1|0|0|1|1|0|1|0|
|0|1|0|1|1|0|1|0|
|0|0|0|0|0|1|1|1|


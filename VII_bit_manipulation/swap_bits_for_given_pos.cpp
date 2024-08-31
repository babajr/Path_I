#include <bits/stdc++.h>
using namespace std;

/*
Input: num = 11 (0000 1011), first_pos = 0, second_pos = 2
Output: res = 14  (0000 1110)
*/

int swap_bits(int num, int first_pos, int second_pos)
{
    int bit_first_pos = (num >> first_pos) & 1;
    int bit_second_pos = (num >> second_pos) & 1;
    int xor_bit = bit_first_pos ^ bit_second_pos;

    xor_bit = (xor_bit << first_pos) | (xor_bit << second_pos);

    return (num ^ xor_bit);
}

int main(void)
{
    int num = 11; // 0000 1011
    int first_pos = 0;
    int second_pos = 2;

    printf("%d\n", swap_bits(num, first_pos, second_pos));

    return 0;
}
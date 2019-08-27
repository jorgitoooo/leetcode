/* ---------------
 * Jorge L. Garcia
 * 8/27/2019
 * ---------------
 * Reverse Bits
 */

#include <iostream>
#include <bitset>

uint32_t reverseBits(uint32_t n)
{
	uint32_t rn = 0;

	for(int i = 0; i < 32; i++)            
	    rn |= ((n & (0x0001 << i)) >> i) << (31-i);

	return rn;
}

int main(int argc, char **argv)
{
	uint32_t n = 0x0f000000;

	std::cout << std::bitset<32>(n) << " => "
		  << std::bitset<32>(reverseBits(n))
		  << '\n';
	n = 0xfe000000;
	std::cout << std::bitset<32>(n) << " => " 
		  << std::bitset<32>(reverseBits(n))
		  << '\n';
	n = 0xea59a837;
	std::cout << std::bitset<32>(n) << " => " 
		  << std::bitset<32>(reverseBits(n))
		  << '\n';

	return 0;
}

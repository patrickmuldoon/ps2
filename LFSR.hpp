#ifndef LFSR_HPP_
#define LFSR_HPP_


#include <iostream>
#include <string>
#include <vector>

class LFSR {
public:
	LFSR(std::string seed, int tap);
	~LFSR();
	friend std::ostream& operator<<(std::ostream& out, const LFSR& right);
	//string to_string();
	int step();
	int generate(int k);
private:
	std::vector<int> arr;
	int num;
};

#endif


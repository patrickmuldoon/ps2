#include "LFSR.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

LFSR::LFSR(string seed, int tap){
	for (int i = 0; i < seed.length(); ++i)
	{
		if (seed[i] == '1')
		{
			arr.push_back(1);
		}
		if (seed[i] == '0')
		{
			arr.push_back(0);
		}
	}
	num = tap;
}

LFSR::~LFSR()
{

}

ostream& operator<<(ostream& out, const LFSR& right)
{
	string answer;
	std::stringstream ss;
	for (int i = 0; i < right.arr.size(); ++i)
	{
		ss << right.arr[i];
	}

	out << ss.str();
	return out;
}


int LFSR::step()
{
	int temp;
	int tp = (this->arr.size()-1) - this->num;
	if (this->arr[0] == 1 && this->arr[tp] == 0)
	{
		temp = 1;
	}
	if (this->arr[0] == 0 && this->arr[tp] == 1)
	{
		temp = 1;
	}
	if (this->arr[0] == this->arr[tp])
	{
		temp = 0;
	}
	for (int i = 0; i < this->arr.size()-1; i++)
	{
		this->arr[i] = this->arr[i+1];
	}
	this->arr[this->arr.size()-1] = temp;
	return temp;

}

int LFSR::generate(int k)
{
	int answer = 0;
	int temp;
	for (int i = 0; i < k; ++i)
	{
		temp = this->step();
		answer *= 2;
		answer += temp;
	}
	return answer;
}


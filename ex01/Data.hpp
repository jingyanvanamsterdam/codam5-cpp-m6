#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
	public:
		Data(void) : _inum(42), _fnum(42.0f), _dnum(42.123), _str("hello"){};
		Data(int i, float f, double d, std::string s): _inum(i), _fnum(f), _dnum(d), _str(s){};
		Data(const Data& obj): _inum(obj._inum), _fnum(obj._fnum), _dnum(obj._dnum), _str(obj._str){}
		Data& operator=(const Data& obj) = default;
		~Data(void) = default;
		
		int	geti(void) const
		{
			return this->_inum;
		}
		
		float getf(void) const
		{
			return this->_fnum;
		}
		
		double getd(void) const
		{
			return this->_dnum;
		}
		
		std::string getstr(void) const
		{
			return this->_str;
		}
		
	private:
		int _inum;
		float	_fnum;
		double	_dnum;
		std::string	_str;
};

#endif
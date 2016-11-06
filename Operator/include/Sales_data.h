#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <string>
#include <iostream>


class Sales_data
{
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	public:
		Sales_data() = default;
		Sales_data(const std::string& s):boo(s) {}
		Sales_data(const std::string& s, unsigned n, double p)
				::bookNo(s), units_sold(n), revenue(p * n) {}
		Sales_data(istream& is);

		Sales_data(const Sales_data&);
		Sales_data& operator=(const Sales&);
			
		std::string isbn() const { return bookNo; }
		Sales_data& combine(const Sales_data&);
		double avg_price() const;
	private:
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue;	
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, Sales_data&);
std::istream& operator>>(std::istream&, Sales_data&);

#endif /* __SALES_DATA_H__ */

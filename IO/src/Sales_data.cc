#include "Sales_data.h"

using namespace std;


Sales_data::Sales_data(const Sales_data& other)
{
	this->book_no = other.book_no;
	this->units_sold = other.units_sold;
	this->revenue = other.revenue;
}

Sales_data& Sales_data::operator=(const Sales_data& other)
{
	this->book_no = other.book_no;
	this->units_sold = other.units_sold;
	this->revenue = other.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	return units_sold? revenue/units_sold : 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}

istream& read(istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.book_no >> item.units_sold >> price;
	item.revenue = price * item.units_sold;

	return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(istream& is)
{
	read(is, *this);
}

#include "Sales_data.h"

using namespace std;

Sales_data::Sales_data(const Sales_data& other)
{
	this->bookNo = other.bookNo;
	this->units_sold = other.units_sold;
	this->revenue = other.revenue;
}

Sales_data& Sales_data::operator=(const Sales_data& other)
{
	this->bookNo = other.bookNo;
	this->units_sold = other.units_sold;
	this->revenue = other.revenue;
}

Sales_data& Sales_data::combine(const Sales_data& sd)
{
	units_sold += sa.units_sold;
	revenue += sd.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	if (units_sol)
		return revenue / units_sold;
	else
		return 0;	
}

Sales_data::Sales_data(istream& is)
{
	read(is, *this);
}

Sales_data add(const Sales_data& lsd, const Sales_data& rsd)
{
	Sales_data result;	
	result.revenue = lsd.revenue + lsd.revenue;
	result.units_sold = lsd.units_sold + rsd.units_sold;

	return result;
}

ostream& print(ostream& os, const Sales_data& sd)
{
	os << "isbn = " << sd.bookNo << " "
	   << "units_sold = " << sd.units_sold
	   << ", revenue = " << sd.revenue << "\n";

	return os;
}

istream& read(istream& is, const Sales_data& sd)
{
	is >> sd.units_sold >> sd.revenue;

	return is;
}

ostream& operator<<(ostream& os, Sales_data& sd)
{
	os << sd.bookNo << " " << sd.units_sold << " " << sd.revenue;
	return os;
}

istream& operator>>(istream& is, Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if(is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}
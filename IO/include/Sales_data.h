#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string>

class Sales_data
{
  public:
	// friend functions
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);

	//! Default constructor
	Sales_data() = default;
	Sales_data(const std::string& s):book_no(s) {}
	Sales_data(const std::string& s, unsigned n, double p):
			book_no(s), units_sold(n), revenue(p * n) {}
	Sales_data(std::istream&);

	//! Copy constructor
	Sales_data(const Sales_data& other);

	//! Copy assignment operator
	Sales_data& operator=(const Sales_data& other);
	
	// Interface here
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	// Getter and setter
	std::string isbn() const {return this->book_no;}

  protected:
  private:
	std::string book_no;
	unsigned units_sold = 0;
	double revenue = 0.0;

};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::string&, Sales_data&);


#endif /* __SALES_DATA_H__ */

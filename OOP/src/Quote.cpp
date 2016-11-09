#include "common.h"
#include "Quote.h"

using namespace std;

double Quote::net_price(size_t n) const
{
    return price;
}

void Quote::debug(ostream& os) const
{
    os << "Quote: \n"
       << "\t" << "ISBN: " << bookNo << "\n"
       << "\t" << "Price: " << price << "\n"; 
}
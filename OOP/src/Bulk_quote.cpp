#include "common.h"
#include "Bulk_quote.h"

using namespace std;

double Bulk_quote::net_price(size_t cnt) const
{
    return cnt * (cnt > quantity? (1 - discount) : 1) * price;
}

void Bulk_quote::debug(ostream& os) const
{
    os << "Bulk_quote:\n"
       << "\tISBN: " << isbn() << "\n"
       << "\tPrice: " << price << "\n"
       << "\tMin Quantity: " << quantity << "\n"
       << "\tDiscount: " << discount << "\n";
}
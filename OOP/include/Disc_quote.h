#ifndef __DISC_QUOTE_H__
#define __DISC_QUOTE_H__

#include "common.h"
#include "Quote.h"

class Disc_quote : public Quote
{
public:
    /* Constructors here */
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price,
              std::size_t qty, double disc):
              Quote(book, price), quantity(qty), discount(disc) {}
    // Disc_quote(const Disc_quote&);
    // Disc_quote& operator=(const Disc_quote&);

    /* Deconstructor here */
    // ~Disc_quote();
    /* Interface here */
    virtual double net_price(std::size_t) const = 0;

protected:
    /* Memebers here */
    std::size_t quantity = 0;
    double discount = 0.0;
};

#endif /* __DISC_QUOTE_H__ */
#ifndef __BULK_QUOTE_H__
#define __BULK_QUOTE_H__

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
  public:
    /* Constructors here */
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t n, double d):
        Disc_quote(b, p, n, d) {}
    // Bulk_quote(const Bulk_quote&);
    // Bulk_quote &operator=(const Bulk_quote &);
    /* Deconstructor here*/
    // ~Bulk_quote();
    /* Interface here */
    double net_price(std::size_t) const override;
    void debug(std::ostream&) const override;

    Bulk_quote* clone() const & override {return new Bulk_quote(*this);}
    Bulk_quote* clone() && override {return new Bulk_quote(std::move(*this));}
};

#endif /* __BULK_QUOTE_H__ */
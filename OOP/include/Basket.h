#ifndef __BASKET_H__
#define __BASKET_H__

#include "common.h"
#include "Quote.h"

class Basket
{
public:
    /* Constructors here */
    Basket() = default;
    // Basket(const Basket&);
    // Basket& operator=(const Basket&);
    /* Move constructor */
    // Basket(const Basket&&);
    // Basket& operator=(const Basket&&);

    /* Deconstructor here */
    // ~Basket() = default;
    /* Interface here */
    void add_item(const Quote& sale)
    {items.insert(std::shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote &&sale)
    {items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));};
    double total_receipt(std::ostream&) const;

private:
    /* Memebers here */
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

#endif /* __BASKET_H__ */
#ifndef __QUOTE_H__
#define __QUOTE_H__

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
                bookNo(book), price(sales_price) {}
    std::string isbn() const {return bookNo;}

    virtual double net_price(std::size_t n) const;
    virtual ~Quote() = default;

    virtual void debug(std::ostream&) const;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

#endif
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
    // 为了解决无法确定类型而导致数据被切的问题
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && {return new Quote(std::move(*this));}
private:
    std::string bookNo;

protected:
    double price = 0.0;
};

#endif
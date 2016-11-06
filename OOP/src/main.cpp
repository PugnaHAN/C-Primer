#include "oop.h"

using namespace std;

int main(int argc, char* argv[])
{
    Quote base("0-201-82470-1", 50);
    Bulk_quote bq("0-201-82470-1", 50, 5, 0.19);

    // print_total(cout, base, 10);
    // print_total(cout, bq, 10);
    base.debug(cout);
    bq.debug(cout);
    cout << flush;
    return 0;
}
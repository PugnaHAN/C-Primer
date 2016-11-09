#include "TemplateDecl.h"

using namespace std;

template <typename Type>
TempTest<Type>::TempTest(const std::initializer_list<Type>& t) :
	data(make_shared<vector<Type>>(t)) {}
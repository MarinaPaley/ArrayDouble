#include <iostream>
#include"..\Domain\Array.h"
#include "..\TemplateArray\TemplateArray.h"

using namespace miit;
int main()
{
	Array a{ 1, 2, 3, 4, 5 };
	Array b(a);
	std::cout << a.ToString() << "\n" << b.ToString() << "\n";
	a[0] = 0;
	std::cout << a.ToString() << "\n" << b.ToString() << "\n";
	Array c(std::move(b));
	std::cout << a.ToString() << "\n" << c.ToString() << "\n";
	auto d = c;
	auto e = std::move(a);
	std::cout << e.ToString() << "\n" << d.ToString() << "\n";

	TemplateArray<int> templateArray(5);

	return 0;
}
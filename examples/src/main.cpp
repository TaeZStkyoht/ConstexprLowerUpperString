#include "ConstexprLowerUpperString.h"

using namespace std;
using namespace ConstexprLowerUpperString;

static constexpr auto lowerVal = CLUStringHelper::CreateLower("SoMeThInG");
static constexpr auto lowerVal2 = CLUStringHelper::CreateLower("SOMETHING");
static constexpr auto lowerValAnother = CLUStringHelper::CreateLower("ANOther");

static constexpr auto upperVal = CLUStringHelper::CreateUpper("SoMeThInG");
static constexpr auto upperVal2 = CLUStringHelper::CreateUpper("something");
static constexpr auto upperValAnother = CLUStringHelper::CreateUpper("anothER");

int main() {
	static_assert(lowerVal == lowerVal2);
	static_assert(lowerVal != lowerValAnother);

	static_assert(lowerVal == "something");
	static_assert(lowerVal != "Something");

	static_assert(lowerVal == "something"sv);
	static_assert(lowerVal != "somethinG"sv);

	if (lowerVal == string("somethinG") || lowerVal != string("something"))
		return -1;

	static_assert(upperVal == upperVal2);
	static_assert(upperVal != upperValAnother);

	static_assert(upperVal == "SOMETHING");
	static_assert(upperVal != "sOMETHING");

	static_assert(upperVal == "SOMETHING"sv);
	static_assert(upperVal != "sOMETHING"sv);

	if (upperVal == string("SOMETHINg") || upperVal != string("SOMETHING"))
		return -1;

	return 0;
}

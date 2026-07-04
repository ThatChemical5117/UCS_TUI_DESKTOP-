#pragma once

#include <vector>
#include <string>

// Factory template for different objects that are not related
// But still allows for Overriding sub-classes to be used through polymorphism
template <typename T>
class TemplateFactory
{
public:
	TemplateFactory() = default;
	virtual T MakeItem(const std::vector<std::string>&) = 0;
	virtual std::string MakeString(const T&) = 0;

	virtual ~TemplateFactory() = default;
};

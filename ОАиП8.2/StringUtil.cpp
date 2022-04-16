
#include "StringUtil.h"

std::string RightInsert(const std::string& base, const std::string& insertable)
{
	std::string result = base;

	int j = insertable.length() - 1;
	for (int i = base.length() - 1; i >= 0 && j >= 0; --i)
	{
		result[i] = insertable[j];
		--j;
	}

	return result;
}

std::string RightInsert(const std::string& base, int insertable)
{
	return RightInsert(base, std::to_string(insertable));
}

#include <vector>
#include <string>

using namespace std;

class SimilarityChecker
{
public:
	int CheckLength(const vector<string>& strs)
	{
		SwapStringsForCalculating(strs);

		if (len1 == len2)
			return 60;
		if (len1 >= len2 * 2)
			return 0;
		return (60 - (len1 - len2) * 60 / len2);
	}

private:
	void SwapStringsForCalculating(const vector<string>& strs)
	{
		len1 = strs[0].length();
		len2 = strs[1].length();
		int temp;
		if (len1 < len2)
		{
			temp = len1;
			len1 = len2;
			len2 = temp;
		}
	}

	int len1;
	int len2;
};
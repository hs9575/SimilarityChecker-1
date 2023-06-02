
#include <string>
#include <vector>
using namespace std;
const int MAX_NUM_OF_ALPHABET = 26;
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

	int CheckAlphabet(std::vector<std::string> strs)
	{
		if (IsCapitalOnly(strs) != true)
			return 0;
		
		char alphaArray[2][MAX_NUM_OF_ALPHABET] = { { 0,} };
		SetAlphaTable(strs, alphaArray);

		return GetScore(alphaArray);
	}

	bool IsCapitalOnly(std::vector<std::string> strs)
	{
		for (string str : strs)
			for (char ch : str)
				if (ch < 'A' || ch > 'Z')
				{
					return false;
				}
		return true;
	}

	void SetAlphaTable(std::vector<std::string> strs, char alphaArray[2][MAX_NUM_OF_ALPHABET])
	{
		for (int i = 0; i < 2; i++)
		{
			for (char ch : strs[i])
				alphaArray[i][ch - 'A'] = 1;
		}
	}

	int GetScore(char alphaArray[2][MAX_NUM_OF_ALPHABET])
	{
		int sameCnt = 0;
		int totalCnt = 0;
		for (int i = 0; i < MAX_NUM_OF_ALPHABET; i++)
		{
			if (alphaArray[0][i] || alphaArray[1][i])
				totalCnt++;
			if (alphaArray[0][i] && alphaArray[1][i])
				sameCnt++;
		}
		return sameCnt * 40 / totalCnt;
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

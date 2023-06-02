#include <string>
#include <vector>
using namespace std;
const int MAX_NUM_OF_ALPHABET = 26;

class SimilarityChecker
{
public:

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
};

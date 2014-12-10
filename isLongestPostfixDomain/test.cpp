#include <iostream>
#include <string>
#include <iterator>

using namespace std;

//string getLongestSamePostFix(string & longerStr, string & shorterStr)
//{
	//std::string result;
	//if(longerStr.empty() || shorterStr.empty())
	//{
		//return string();
	//}

	//if(longerStr.size() < shorterStr.size())
	//{
		//return string();
	//}

	//string::reverse_iterator rit1 = longerStr.rbegin();
	//string::reverse_iterator rit2 = shorterStr.rbegin();
	//for(; *rit1 == *rit2 && rit1 != longerStr.rend() && rit2 != shorterStr.rend(); ++rit1, ++rit2)
	//{}

	//if(rit2 == shorterStr.rend())
	//{
		//return shorterStr;
	//}

	//result.assign(rit2.base(), shorterStr.end());
	//return result;
//}

bool isLongestPostfixDomain(const string & longerStr, const string &shorterStr)
{
	std::string result;
	if(longerStr.empty() || shorterStr.empty())
	{
		return false;
	}

	int longerStrSize = longerStr.size();
	int shorterStrSize = shorterStr.size();

	if(longerStrSize < shorterStrSize)
	{
		return false;
	}

	int longerStrIndex = longerStrSize;
	int shorterStrIndex = shorterStrSize;

	while(longerStrIndex > 0 && 
		  shorterStrIndex > 0 && 
		  longerStr[longerStrIndex -1] == shorterStr[shorterStrIndex -1])
	{
		if(shorterStr[shorterStrIndex-1] == '.' && shorterStrIndex != shorterStrSize)
		{
			return true;
		}
		--longerStrIndex;
		--shorterStrIndex;
	}

	return false;
}

string getLongestSamePostFix(const string & longerStr, const string &shorterStr)
{
	std::string result;
	if(longerStr.empty() || shorterStr.empty())
	{
		return result;
	}

	int longerStrSize = longerStr.size();
	int shorterStrSize = shorterStr.size();

	if(longerStrSize < shorterStrSize)
	{
		return result;
	}

	int longerStrIndex = longerStrSize;
	int shorterStrIndex = shorterStrSize;
	for(; longerStrIndex > 0 && shorterStrIndex > 0 && longerStr[longerStrIndex -1] == shorterStr[shorterStrIndex -1]; --longerStrIndex, --shorterStrIndex)
	{}
	
	result = shorterStr.substr(shorterStrIndex);
	return result;
}

int main()
{
	string longerStr;
	string shorterStr;

	cout << "please enter longerStr: " << endl;
	cin >> longerStr;
	cout << "please enter shorterStr: " << endl;
	cin >> shorterStr;

	string str3 = getLongestSamePostFix(longerStr, shorterStr);
	cout << "The result is: " << str3 << endl;

	cout << "Is Domain: " << isLongestPostfixDomain(longerStr, shorterStr) << endl;
}

#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> dict;
char text;
string word;
int main()
{
	while((text=getchar())!=EOF)
	{
		if(!isalpha(text)) continue;
		while(isalpha(text))
		{
			text=tolower(text);
			word+=text;
			text=getchar();
		}
		dict.insert(word);
		word.clear();
	}
	for(set<string>::iterator i=dict.begin();i!=dict.end();i++)
		cout<<*i<<endl;
	return 0;
}

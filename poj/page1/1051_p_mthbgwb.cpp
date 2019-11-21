#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	char morse[30][5] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
					  "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
					  "...-",".--","-..-","-.--","--.." ,"..--",".-.-","---.","----" };
	int n;
	cin >> n;
	char message[101];
	int len;
	string str ="";
	stack<int> s;
	for (int i = 0;i < n;i++)
	{
		cin >> message;
		len = strlen(message);
		for (int j = 0;j < len;j++)
		{
			if (message[j] >= 'A'&&message[j] <= 'Z')
			{
				string ss(morse[message[j] - 'A']);
				str = str + ss;
				s.push(strlen(morse[message[j] - 'A']));
			}
			else if (message[j] == '_')
			{
				str = str + "..--";
				s.push(4);
			}
			else if (message[j] == ',')
			{
				str = str + ".-.-";
				s.push(4);
			}
			else if (message[j] == '.')
			{
				str += "---.";
				s.push(4);
			}
			else
			{
				str = str + "----";
				s.push(4);
			}
		}
		cout << i + 1 << ": ";
		int flag = 0;
		while (s.size() > 0)
		{
			int sublen = s.top();
			s.pop();
			char subs[5];
			string ss = str.substr(flag, sublen);
			strncpy(subs, ss.c_str(), ss.length() + 1);
			for (int k = 0;k < 30;k++)
			{
				if (strcmp(morse[k], subs) == 0)
				{
					if (k < 26)
						cout <<(char)( k + 'A');
					else if (k == 26)
						cout << '_';
					else if (k == 27)
						cout << ',';
					else if (k == 28)
						cout << '.';
					else
						cout << '?';
					break;
				}
			}
			flag += sublen;
		}
		cout << endl;
		str.clear();
	}
	system("pause");
}
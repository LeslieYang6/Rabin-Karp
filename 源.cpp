#include<iostream>

#include<string>
using namespace std;

int d=256;



void Find_Pattern(char pat[], char str[],int q)   //q质数，pat所要匹配的字符串，str大字符串//
{
	int m = strlen(pat);
	int n = strlen(str);
	int p = 0;                                   //记录pat的hash值
	int s = 0;                                   //记录str的某个substring的hash值
	int h = 1;                                   //用于处理first char
	for (int i = 1; i < m; i++)
		h = (h*d) % q;                           //用于减去第一个字符的值，这是（p*d+pat[i])%q的一部分而已
	for (int i = 0; i < m; i++)
	{
		p = (p*d + pat[i]) % q;                 //公式，用于计算字符串的值
		s = (s*d + str[i]) % q;
	}
	int k = 0;
	while (k <=n - m)
	{
	    if(s==p)
		{
			int i = 0;
			while (i < m)
			{
				if (str[i + k] != pat[i])
				{   
					cout << "collision";
					break;
				}
				i++;
			}
			if (i == m)
				cout << "patter found at " << (k + 1) << endl;
		}
		s = ((s - str[k] * h)*d + str[k + m]) % q;               //字符串去掉首字符的值和加上next字符
		if (s < 0)
			s = s + q;
		k++;

	}
}

int main()
{
	char str[] = "geek for geeks";
	char pat[] = "geek";
	Find_Pattern(pat, str, 101);
	system("pause");
}
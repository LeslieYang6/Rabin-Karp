#include<iostream>

#include<string>
using namespace std;

int d=256;



void Find_Pattern(char pat[], char str[],int q)   //q������pat��Ҫƥ����ַ�����str���ַ���//
{
	int m = strlen(pat);
	int n = strlen(str);
	int p = 0;                                   //��¼pat��hashֵ
	int s = 0;                                   //��¼str��ĳ��substring��hashֵ
	int h = 1;                                   //���ڴ���first char
	for (int i = 1; i < m; i++)
		h = (h*d) % q;                           //���ڼ�ȥ��һ���ַ���ֵ�����ǣ�p*d+pat[i])%q��һ���ֶ���
	for (int i = 0; i < m; i++)
	{
		p = (p*d + pat[i]) % q;                 //��ʽ�����ڼ����ַ�����ֵ
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
		s = ((s - str[k] * h)*d + str[k + m]) % q;               //�ַ���ȥ�����ַ���ֵ�ͼ���next�ַ�
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
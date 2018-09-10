#define _CRT_SECURE_NO_WARNINGS

#include <map>     
#include <fstream>     
#include <iostream>     
#include <string> 
#include <regex>
using namespace std;
int cnt[3] = { 0 };
bool isnum_str(char str)  //�ж��Ƿ����ַ�������
{
	if ((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9'))
		return true;
	else
		return false;
}
void count(fstream &outfile, int *cnt)  //ͳ�ƺ���
{
	char str[256];
	while (outfile.getline(str, 256))
	{
		int tmp = 0;
		for (int i = 0; i < (unsigned int )strlen(str); i++)
		{
			if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!' || str[i] == '\n')
				cnt[1]++;            //ͳ�Ƶ�����
			if (isnum_str(str[i]))
			{
				cnt[0]++;   tmp++;
			}    //ͳ���ַ�����tmp�ֲ��������������ǲ���һ�����С�
		}
		if (tmp != 0)
			cnt[2]++;                 //ͳ������
		tmp = 0;
	}
	return;
}
void display_map(map<string, int> &wmap);
/**
*function��ͳ���ı���ÿ�����ʳ��ֵĴ���
*/
int main() {

	char filename[256];
	//int cnt[3] = { 0 };
	const char *mInputFileName = "1.txt";
	ifstream ifs(mInputFileName);
	string mStrTemp;
	map<string, int> mCountMap;
	//���ж����ļ����������ҳ����ʣ�����ͳ��
	regex regWordPattern("[a-zA-Z]+");//���ʵ�����ʽ��1��\w+:�������� 2)[a-zA-Z]:ֻ����ĸ
	while (getline(ifs, mStrTemp)) {//���ж���
		const std::sregex_token_iterator end;
		for (sregex_token_iterator wordIter(mStrTemp.begin(), mStrTemp.end(), regWordPattern); wordIter != end; wordIter++) {//��һ���ı�������ҳ�����
			//cout<<*wordIter<<endl;//ÿ������
			mCountMap[*wordIter]++;//���ʼ���
		}
	}

	
	cout << "please input your filename:" << endl; //����Ҫͳ�Ƶ��ı��ľ���·��
	cin.getline(filename, 256);
	fstream outfile(filename, ios::in);
	count(outfile, cnt);
	cout << "characters: " << cnt[0] << endl;
	cout << "words:";
	display_map(mCountMap);
	//cout << "lines:" << cnt[2] << endl;
	outfile.close();
	system("pause");
	return 0;
	system("pause");
	return 0;
	return 1;
}




struct ww
{
	char word[20];
	int number;
}w[100];
void display_map(map<string, int> &wmap)
{


	map<string, int>::const_iterator map_it;
	
	
	int i, j, num = 0;
	int t = 0;
	int tt=0, ttt, x = 0;
	char  cc[20];
	
	for (map_it = wmap.begin(); map_it != wmap.end(); map_it++)
	{

		num += map_it->second;
		strcpy(w[t].word,(map_it->first).c_str());
		w[t].number = map_it->second;
		t++;
		
	}
	
	ttt = t - 2;
	for (j = tt; j < ttt; j++)
	{
		for (i = 0; i < ttt - j; i++)
		{
			if (w[i].number < w[i + 1].number)
			{
				x = w[i].number; w[i].number = w[i + 1].number; w[i + 1].number = x;
				strcpy(cc,w[i].word);
				strcpy(w[i].word, w[i + 1].word);
				strcpy(w[i+1].word,cc);
			}
		}
	}
	cout << num << endl;
	cout << "lines :"<< cnt[2] << endl;
	for (j = tt; j < 10; j++)
	{
		cout << w[j].word  << ":"<< w[j].number << endl;
	}

}
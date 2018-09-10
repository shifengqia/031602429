#include <map>     
#include <fstream>     
#include <iostream>     
#include <string> 
#include <regex>
using namespace std;
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
		for (int i = 0; i < strlen(str); i++)
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
	int cnt[3] = { 0 };
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
	cout << endl;
	cout << "lines:" << cnt[2] << endl;
	outfile.close();
	system("pause");
	return 0;
	system("pause");
	return 0;
	return 1;
}



void display_map(map<string, int> &wmap)
{
	map<string, int>::const_iterator map_it;
	int num = 0;
	for (map_it = wmap.begin(); map_it != wmap.end(); map_it++)
	{
		num += map_it->second;


	}
	cout << num;
}

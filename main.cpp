#include <iostream>
#include <windows.h>
#include <cmath>
#include <random>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

class Player
{
public:
	//玩家姓名
	string Name;
	//UR相关加减
	int UR_ADD(int Num)
	{
		this->UR += Num;
		return this->UR;
	}
	int UR_DEC(int Num)
	{
		this->UR -= Num;
		return this->UR;
	}
	//SSR相关加减
	int SSR_ADD(int Num)
	{
		this->SSR += Num;
		return this->SSR;
	}
	int SSR_DEC(int Num)
	{
		this->SSR -= Num;
		return this->SSR;
	}
	//SR相关加减
	int SR_ADD(int Num)
	{
		this->SR += Num;
		return this->SR;
	}
	int SR_DEC(int Num)
	{
		this->SR -= Num;
		return this->SR;
	}
	//R相关加减
	int R_ADD(int Num)
	{
		this->R += Num;
		return this->R;
	}
	int R_DEC(int Num)
	{
		this->R -= Num;
		return this->R;
	}
	//N相关加减
	int N_ADD(int Num)
	{
		this->N += Num;
		return this->N;
	}
	int N_DEC(int Num)
	{
		this->N -= Num;
		return this->N;
	}
	void Show()
	{
		cout << "玩家: " << this->Name << endl;
		cout << "库存: " << endl;
		cout << "UR: " << this->UR << endl;
		cout << "SSR: " << this->SSR << endl;
		cout << "SR: " << this->SR << endl;
		cout << "R: " << this->R << endl;
		cout << "N: " << this->N << endl;
	}
	Player()
	{
		this->Name = "测试员";
		this->UR = 0;
		this->SSR = 0;
		this->SR = 0;
		this->R = 0;
		this->N = 0;
	}
private:
	int UR;
	int SSR;
	int SR;
	int R;
	int N;
};
Player WJ;
void One(); //单抽
void Ten(); //十连
void Hundred(); //百连 
void Thousand(); //千连
void MANG(); //万连
void Custom(int Num); //自定义抽奖次数
void KK();
Player Loot(Player &Temp, int Num);
void Menu()
{
	cout << "菜单" << endl;
	cout << "0.退出程序" << endl;
	cout << "1.单抽" << endl;
	cout << "2.十连" << endl;
	cout << "3.百连" << endl;
	cout << "4.千连" << endl;
	cout << "5.万连" << endl;
	cout << "6.自定义次数" << endl;
	

	cout << "请输入选择: ";
	int Menu_S;
	cin >> Menu_S;
	switch (Menu_S)
	{
	case 0:
		system("cls");
		cout << "即将退出程序!祝您生活愉快!再见!" << endl;
		Sleep(3000);
		exit(0);
	case 1:
		system("cls");
		One();
		break;
	case 2:
		system("cls");
		Ten();
		break;
	case 3:
		system("cls");
		Hundred();
		break;
	case 4:
		system("cls");
		Thousand();
		break;
	case 5:
		system("cls");
		MANG();
		break;
	case 6:
		system("cls");
		cout << "请输入次数: ";
		int Temp = 0;
		cin >> Temp;
		Custom(Temp);
		break;
	}
}
void One()
{
	Loot(WJ, 1);
	KK();
}
void Ten()
{
	Loot(WJ,10);
	KK();
}
void Hundred()
{
	Loot(WJ,100);
	KK();
}
void Thousand()
{
	Loot(WJ,1000);
	KK();
}
void MANG()
{
	Loot(WJ, 10000);
	KK();
}
void Custom(int Num)
{
	Loot(WJ, Num);
	KK();
}
Player Loot(Player &Temp, int Num)
{
	int Temp_N = 0;
	int Temp_R = 0;
	int Temp_SR = 0;
	int Temp_SSR = 0;
	int Temp_UR = 0;
	for (int i = 1; i <= Num; i++)
	{
		int Roll = (rand() % (100 - 1)) + 1;
		if (Roll >= 50 && Roll < 100)
		{
			cout << "抽取到了N卡" << endl;
			Temp_N += 1;
		}
		else if (Roll >= 25 && Roll < 50)
		{
			cout << "抽取到了R卡" << endl;
			Temp_R += 1;
		}
		else if (Roll >= 10 && Roll < 25)
		{
			cout << "抽取到了SR卡" << endl;
			Temp_SR += 1;
		}
		else if (Roll >= 2 && Roll < 10)
		{
			cout << "抽取到了SSR卡" << endl;
			Temp_SSR += 1;
		}
		else if (Roll >= 0 && Roll < 2 || Roll == 100)
		{
			cout << "抽取到了UR卡" << endl;
			Temp_UR += 1;
		}
	}
	Temp.N_ADD(Temp_N);
	Temp.R_ADD(Temp_R);
	Temp.SR_ADD(Temp_SR);
	Temp.SSR_ADD(Temp_SSR);
	Temp.UR_ADD(Temp_UR);
	system("cls");
	cout << "本次抽奖总计获得: " << endl;
	cout << "UR: " << Temp_UR << endl;
	cout << "SSR: " << Temp_SSR << endl;
	cout << "SR: " << Temp_SR << endl;
	cout << "R: " << Temp_R << endl;
	cout << "N: " << Temp_N << endl;
	system("pause");
	return Temp;
}
void KK()
{
	system("cls");
	//显示玩家信息
	WJ.Show();
	cout << endl;
	//显示菜单
	Menu();
}
int main()
{
	//设置CMD标题
	SetConsoleTitle("抽奖模拟器 by.AnswersKK|QQ:908095447");
	srand((unsigned)time(NULL));
	//设置玩家名称
	cout << "欢迎来到抽奖模拟器,我是一个AI" << endl;
	cout << "请输入你的ID: ";
	cin >> WJ.Name;
	system("cls");
	cout << "欢迎您!尊敬的 " << WJ.Name << " 阁下!" << endl;
	cout << "接下来,我将为您跳转至菜单界面,请等待..." << endl;
	Sleep(1000);
	cout << "跳转成功!" << endl;
	system("pause");
	KK();
	return 0;
}

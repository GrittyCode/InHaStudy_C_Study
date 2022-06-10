#include<iostream>
#include"tabtenn1.h"

int main()
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tera", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
	
	player1.Name();
	if(player1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
	cout << "이름: ";
	rplayer1.Name();
	cout << "; 랭킹: " << rplayer1.Rating() << endl;
	//TableTennisPlayer 객체 사용하여 RatedPlayer를 초기화
	RatedPlayer rplayer2(1212, player1);
	cout << "이름: ";
	rplayer2.Name();
	cout << "; 랭킹: " << rplayer2.Rating() << endl;

	return 0;
}
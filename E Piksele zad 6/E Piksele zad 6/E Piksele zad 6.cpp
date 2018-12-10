#include <fstream>

using namespace std;

int main(){
	ifstream dane;
	dane.open("dane.txt");
	ofstream wynik6;
	wynik6.open("wynik6.txt");

	wynik6 << "6.1" <<endl;

	int obraz[200][320];
	int min = 255, max = 0;

	for (int i = 0; i < 200; i++){
		for (int j = 0; j < 320; j++){
			dane >> obraz[i][j];
			if (obraz[i][j] > max) max = obraz[i][j];
			if (obraz[i][j] < min) min = obraz[i][j];
		}
	}
	wynik6 << endl << "min: " << min << " max: " << max << endl;

	/////////////////////////////////////////////////////////

	int count = 0;

	for (int i = 0; i < 200; i++){
		for (int j = 0; j < 160; j++){
			if (obraz[i][j] != obraz[i][319 - j]){
				count++;
				break;
			}
		}
	}

	wynik6 << endl << "6.2" << endl << endl << count << endl;

	////////////////////////////////////////////////////////////
	
	return 0;
}
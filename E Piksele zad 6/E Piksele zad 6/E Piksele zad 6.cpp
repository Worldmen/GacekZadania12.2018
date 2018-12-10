#include <fstream>
#include <cmath>

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

	dane.close();

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

	count = 0;
	//ZLE!!!!!!!!!!!!
	for (int i = 0; i < 199; i++){
		for (int j = 0; j < 319; j++){
			if (abs(obraz[i][j] - obraz[i][j + 1]) >= 128 || abs(obraz[i][j] - obraz[i + 1][j]) >= 128){
				count++;
			}
		}
		if (abs(obraz[i][319] - obraz[i][318]) >= 128 || abs(obraz[i][319] - obraz[i + 1][319]) >= 128){
			count++;
		}
	}
	for (int j = 0; j < 319; j++){
		if (abs(obraz[199][j] - obraz[199][j + 1]) >= 128 || abs(obraz[199][j] - obraz[198][j]) >= 128){
			count++;
		}
	}
	if (abs(obraz[199][319] - obraz[199][318]) >= 128 || abs(obraz[199][319] - obraz[199 - 1][319]) >= 128){
		count++;
	}

	wynik6 << "6.3" << endl << endl << count;
	wynik6.close();
	return 0;
}
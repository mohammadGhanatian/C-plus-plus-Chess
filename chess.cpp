#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include<fstream>
#include<sstream>
using namespace std;

class userinterface {
	string alphabet[8] = { "a","b","c","d","e","f","g","h" };
	string verticalboarder =  "|     |     |     |     |     |     |     |     |" ;
	string horizontalborder = "+-----+-----+-----+-----+-----+-----+-----+-----+";
	string empty = "                                                 ";
	vector<string> verticalBorderVector;
	
	//private methods:
	void writeAlphabet() {
		for (  int i = 0; i < 49; i++) {
			if ((i + 1) % 6 == 0) {
				cout << alphabet[(i - 3) / 6];
			}
			else { cout << " "; }
		}
		cout << endl;
	}

	int columnNumber(string c) {
		for (int i = 0; i < 8; i++) {
			if (alphabet[i] == c) {
				return 1+i;
			}
		}
	}

public:
	//public methods;
	userinterface() {
		for (int i = 0; i < 8; i++) {
			verticalBorderVector.push_back(verticalboarder);
		}
	}

	void draw() {
		string white = empty;
		white[24] = 'w'; white[25] = 'h'; white[26] = 'i'; white[27] = 't'; white[28] = 'e';
		cout << white << endl;

		writeAlphabet();

		for (int i = 0; i < 8; i++) {
			cout << "  " << horizontalborder << endl;
			cout << i + 1 << " " << verticalBorderVector[i] << " " << i + 1 << endl;
		}

		cout << "  " << horizontalborder << endl;
		writeAlphabet();

		string black = empty;
		black[24] = 'b'; black[25] = 'l'; black[26] = 'a'; black[27] = 'c'; black[28] = 'k';
		cout << black << endl;

	}
	void reset() {
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				deleteAWordFromTheTable(i, j);
			}
		}
	}

	void putAWordIntoTheTable(string str,int row,string column) {
		int col = columnNumber(column);
		verticalBorderVector[row-1].at(6*col-3) = str.at(0);
		verticalBorderVector[row-1].at(6*col-3+1) = str.at(1);
	}
	void deleteAWordFromTheTable(int row, string column) {
		system("cls");
		int col = columnNumber(column);
		verticalBorderVector[row - 1].at(6 * col - 3) = ' ';
		verticalBorderVector[row - 1].at(6 * col - 3 + 1) = ' ';
	}

	void deleteAWordFromTheTable(int row, int column) {
		system("cls");
		verticalBorderVector[row - 1].at(6 * column - 3) = ' ';
		verticalBorderVector[row - 1].at(6 * column - 3 + 1) = ' ';
	}



	void printChoices(vector<string> CHOICES) {
		int size = CHOICES.size();
		cout << "You have these options: " << endl;
		for (int i = 0; i < size; i++) {
			cout <<i<<")"<< CHOICES[i] << endl;
		}
	}

	int  newOrLoad() {
		cout << "WELCOME TO Mohammmmmad CHESS" << endl << endl;
		cout << "DO YOU WANNA: " << endl << "1)LOAD THE LAST GAME " << endl << "2)PLAY A NEW GAME " << endl ;
		int i;
		int flag = 0;

		while (flag == 0) {
			cin >> i;
			if (i == 1 || i == 2) {
				flag = 1;
			}
			else { cout << "INVALID INPUT,PLEASE TRY AGAIN"<<endl; }
		}
		
		return i;
	}
	int numberOfPlayers() {
		system("cls");
		cout << "DO YOU WANT: " << endl << endl << endl << "1) 1 PLAYER" << endl << "2) 2 PLAYER" << endl;
		int flag = 0;
		int i;

		while (flag == 0) {
			cin >> i;
			if (i == 1 || i == 2) {
				flag = 1;
			}
			else { cout << "INVALID INPUT,PLEASE TRY AGAIN" << endl; }
		}
		return i;
	}
	
	string whichPositionToMove() {
		string position;
		cout << "Enter the position of the piece you wanna move: "; cin >> position;
		return position;
	}
	

};

class pieces {
protected:
	string alphabet[8] = { "a","b","c","d","e","f","g","h" };
	int team;
	string column;
	int row;
	
	int columnNumber(string c) {
		for (int i = 0; i < 8; i++) {
			if (alphabet[i] == c) {
				return  i;
			}
		}
	}
	string name;
public:
	void setTeam(int TEAM) {
		team = TEAM;
	}
	int getTeam() {
		return team;
	}
	string sGetTeam() {
		if (team == 0) {
			return "B";
		}
		if(team==1) {
			return "W";
		}
	}

	void setName(string NAME) {
		name = NAME;
	}
	string getName() {
		return name;
	}

	void setPosition(int ROW, string COLUMN) {
		row = ROW;
		column = COLUMN;
	}
	string getPosition() {
		return((to_string(getRow()) + getColumn()));
	}

	int getRow() {
		return row;
	}
	string getColumn() {
		return column;
	}
	void goUp() {
		row--;
	 }
	void goDown() {
		row++;
	}
	void goRight() {
		column = alphabet[(columnNumber(column))+1];
	}
	void goLeft() {
		column = alphabet[(columnNumber(column)) - 1];
	}
	virtual void defaultPosition() = 0;
	virtual vector<string> options() = 0;
};


class pawn :public pieces {
public:
	void defaultPosition() {
		if (getName() == "BP1") {
			setPosition(7, "a");
		}
		if (getName() == "BP2") {
			setPosition(7, "b");
		}
		if (getName() == "BP3") {
			setPosition(7, "c");
		}
		if (getName() == "BP4") {
			setPosition(7, "d");
		}
		if (getName() == "BP5") {
			setPosition(7, "e");
		}
		if (getName() == "BP6") {
			setPosition(7, "f");
		}
		if (getName() == "BP7") {
			setPosition(7, "g");
		}
		if (getName() == "BP8") {
			setPosition(7, "h");
		}
		////////////////////////
		if (getName() == "WP1") {
			setPosition(2, "a");
		}
		if (getName() == "WP2") {
			setPosition(2, "b");
		}
		if (getName() == "WP3") {
			setPosition(2, "c");
		}
		if (getName() == "WP4") {
			setPosition(2, "d");
		}
		if (getName() == "WP5") {
			setPosition(2, "e");
		}
		if (getName() == "WP6") {
			setPosition(2, "f");
		}
		if (getName() == "WP7") {
			setPosition(2, "g");
		}
		if (getName() == "WP8") {
			setPosition(2, "h");
		}
	}


	vector<string> options() {
		vector<string> options;

		int currentRow = getRow();
		string currentColumn = getColumn();

		int futureRow;
		string futureColumn;

		if (team == 0) {
			if (currentRow > 2) {
				futureRow = currentRow - 1;
				futureColumn = currentColumn;
				options.push_back(to_string(futureRow) + futureColumn);
			}
		}
		if (team == 1) {
			if (currentRow < 8) {
				futureRow = currentRow + 1;
				futureColumn = currentColumn;

				options.push_back(to_string(futureRow) + futureColumn);
			}
		}
		return options;
	}

};
class rook:public pieces {
public:
	void defaultPosition() {
		if (getName() == "BR1") {
			setPosition(8, "a");
		}
		if (getName() == "BR2") {
			setPosition(8, "h");
		}
		if (getName() == "WR1") {
			setPosition(1, "a");
		}
		if (getName() == "WR2") {
			setPosition(1, "h");
		}
	}
	vector<string> options() {
		vector<string> options;
		int currentRow = getRow();
		string currentColumn = getColumn();
		string currentPosition = to_string(currentRow) + currentColumn;
		for (int i = 0; i < 16; i++) {
			if (i < 8 && (to_string(i + 1) + currentColumn)!= currentPosition)
				options.push_back((to_string(i+1) + currentColumn));
			if (i > 7 && (to_string(currentRow) + alphabet[i - 8]) != currentPosition) {
				options.push_back(( to_string(currentRow) + alphabet[i - 8]));
			}
		}
		return options;
	}
};
class knight:public pieces{
public:

	void defaultPosition() {
		if (getName() == "BN1") {
			setPosition(8, "b");
		}
		if (getName() == "BN2") {
			setPosition(8, "g");
		}
		if (getName() == "WN1") {
			setPosition(1, "b");
		}
		if (getName() == "WN2") {
			setPosition(1, "g");
		}
	}
	vector<string> options() {

		vector<string> options;

		int currentRow = getRow();
		string currentColumn = getColumn();

		if (0 <= (columnNumber(currentColumn) + 1) && (columnNumber(currentColumn) + 1) < 8 && 0<(currentRow + 2) && (currentRow + 2)<9) {
			options.push_back(to_string(currentRow + 2) + alphabet[columnNumber(currentColumn) + 1]);
		}
		if (0 <= (columnNumber(currentColumn) - 1) && (columnNumber(currentColumn) - 1) < 8 && 0<(currentRow +2) && (currentRow +2)<9) {
			options.push_back(to_string(currentRow + 2) + alphabet[columnNumber(currentColumn) - 1]);
		}
		if (0 <= (columnNumber(currentColumn) + 1) && (columnNumber(currentColumn) + 1) < 8 && 0<(currentRow -2) && (currentRow -2)<9) {
			options.push_back(to_string(currentRow - 2) + alphabet[columnNumber(currentColumn) + 1]);
		}
		if (0 <= (columnNumber(currentColumn) - 1) && (columnNumber(currentColumn) - 1) < 8 && 0<(currentRow - 2) && (currentRow - 2)<9) {
			options.push_back(to_string(currentRow - 2) + alphabet[columnNumber(currentColumn) - 1]);
		}
		if (0 <= (columnNumber(currentColumn) +2) && (columnNumber(currentColumn) + 2) < 8 && 0<(currentRow + 1) && (currentRow + 1)<9) {
			options.push_back(to_string(currentRow + 1) + alphabet[columnNumber(currentColumn) + 2]);
		}
		if (0 <= (columnNumber(currentColumn)-2 ) && (columnNumber(currentColumn) - 2) < 8 && 0<(currentRow + 1) && (currentRow + 1)<9) {
			options.push_back(to_string(currentRow + 1) + alphabet[columnNumber(currentColumn) - 2]);
		}
		if (0 <= (columnNumber(currentColumn) +2) && (columnNumber(currentColumn) + 2) < 8 && 0<(currentRow -1) && (currentRow -1)<9) {
			options.push_back(to_string(currentRow - 1) + alphabet[columnNumber(currentColumn) + 2]);
		}
		if (0 <= (columnNumber(currentColumn) -2) && (columnNumber(currentColumn) - 2) < 8 && 0<(currentRow -1) && (currentRow -1)<9) {
			options.push_back(to_string(currentRow - 1) + alphabet[columnNumber(currentColumn) - 2]);
		}
			return options;
	}
	
	

	

};
class bishop:public pieces{
public:

	void defaultPosition() {
		if (getName() == "BB1") {
			setPosition(8, "c");
		}
		if (getName() == "BB2") {
			setPosition(8, "f");
		}
		if (getName() == "WB1") {
			setPosition(1, "c");
		}
		if (getName() == "WB2") {
			setPosition(1, "f");
		}
	}
	vector<string> options() {

		vector<string> options;

		int currentRow = getRow();
		string currentColumn = getColumn();
		string currentPosition = to_string(currentRow) + currentColumn;

		for (int i = 0; i < 32; i++) {
			if (i < 8 ) {
				if((currentRow + i)>0 && (currentRow + i)<9 && 0<=(columnNumber(currentColumn) + i) && (columnNumber(currentColumn) + i)<8 && currentPosition != (to_string(currentRow + i) + alphabet[columnNumber(currentColumn) + i]))
					options.push_back(to_string(currentRow + i) + alphabet[columnNumber(currentColumn) + i]);
			}
				if (i > 7 && i < 16) {
				int i2 = i - 8;
				if ((currentRow + i2)>0 && (currentRow + i2)<9 && 0 <= (columnNumber(currentColumn) -i2) && (columnNumber(currentColumn) - i2)<8 && currentPosition != (to_string(currentRow + i2) + alphabet[columnNumber(currentColumn) - i2]))
					options.push_back(to_string(currentRow + i2) + alphabet[columnNumber(currentColumn) - i2]);
			}
			if (i > 15 && i < 24) {
				int i3 = i - 16;
				if ((currentRow - i3)>0 && (currentRow -i3)<9 && 0 <= (columnNumber(currentColumn) -i3) && (columnNumber(currentColumn) -i3)<8 && currentPosition != (to_string(currentRow - i3) + alphabet[columnNumber(currentColumn) - i3]))
					options.push_back(to_string(currentRow -i3) + alphabet[columnNumber(currentColumn) - i3]);
			}
			if (i > 23 && i < 32) {
				int i4 = i - 24;
				if ((currentRow -i4)>0 && (currentRow -i4)<9 && 0 <= (columnNumber(currentColumn) + i4) && (columnNumber(currentColumn) + i4)<8 && currentPosition != (to_string(currentRow - i4) + alphabet[columnNumber(currentColumn) + i4]))
					options.push_back(to_string(currentRow -i4) + alphabet[columnNumber(currentColumn) +i4]);
			}
		}


		return options;
	}


};
class king :public pieces {
public:
	void defaultPosition() {
		if (getName() == "BK") {
			setPosition(8, "e");
		}
		if (getName() == "WK") {
			setPosition(1, "e");
		}
	}
	vector<string> options() {
		vector<string> options;

		int currentRow = getRow();
		string currentColumn = getColumn();
		if(0<(currentRow + 1)&& (currentRow + 1)<9 )
			options.push_back(to_string(currentRow+1) + alphabet[columnNumber(currentColumn) ]);
		if(0<(currentRow - 1)&& (currentRow - 1)<9 )
			options.push_back(to_string(currentRow - 1) + alphabet[columnNumber(currentColumn) ]);
		if(0<=(columnNumber(currentColumn) + 1) && (columnNumber(currentColumn) + 1)<8)
			options.push_back(to_string(currentRow ) + alphabet[columnNumber(currentColumn) + 1]);
		if (0 <= (columnNumber(currentColumn) - 1) && (columnNumber(currentColumn) - 1)<8)
			options.push_back(to_string(currentRow ) + alphabet[columnNumber(currentColumn) - 1]);

		return options;
	}

};
class queen:public pieces{
public:

	void defaultPosition() {
		if (getName() == "BQ") {
			setPosition(8, "d");
		}
		if (getName() == "WQ") {
			setPosition(1, "d");
		}
	}
	vector<string> options() {
		vector<string> options;
		int currentRow = getRow();
		string currentColumn = getColumn();
		string currentPosition = to_string(currentRow) + currentColumn;
		
		for (int i = 0; i < 16; i++) {
			if (i < 8 && (to_string(i + 1) + currentColumn) != currentPosition)
				options.push_back((to_string(i + 1) + currentColumn));
			if (i > 7 && (to_string(currentRow) + alphabet[i - 8]) != currentPosition) {
				options.push_back((to_string(currentRow) + alphabet[i - 8]));
			}
		}
		for (int i = 0; i < 32; i++) {
			if (i < 8) {
				if ((currentRow + i)>0 && (currentRow + i)<9 && 0 <= (columnNumber(currentColumn) + i) && (columnNumber(currentColumn) + i)<8 && currentPosition != (to_string(currentRow + i) + alphabet[columnNumber(currentColumn) + i]))
					options.push_back(to_string(currentRow + i) + alphabet[columnNumber(currentColumn) + i]);
			}
			if (i > 7 && i < 16) {
				int i2 = i - 8;
				if ((currentRow + i2)>0 && (currentRow + i2)<9 && 0 <= (columnNumber(currentColumn) - i2) && (columnNumber(currentColumn) - i2)<8 && currentPosition != (to_string(currentRow + i2) + alphabet[columnNumber(currentColumn) - i2]))
					options.push_back(to_string(currentRow + i2) + alphabet[columnNumber(currentColumn) - i2]);
			}
			if (i > 15 && i < 24) {
				int i3 = i - 16;
				if ((currentRow - i3)>0 && (currentRow - i3)<9 && 0 <= (columnNumber(currentColumn) - i3) && (columnNumber(currentColumn) - i3)<8 && currentPosition != (to_string(currentRow - i3) + alphabet[columnNumber(currentColumn) - i3]))
					options.push_back(to_string(currentRow - i3) + alphabet[columnNumber(currentColumn) - i3]);
			}
			if (i > 23 && i < 32) {
				int i4 = i - 24;
				if ((currentRow - i4)>0 && (currentRow - i4)<9 && 0 <= (columnNumber(currentColumn) + i4) && (columnNumber(currentColumn) + i4)<8 && currentPosition != (to_string(currentRow - i4) + alphabet[columnNumber(currentColumn) + i4]))
					options.push_back(to_string(currentRow - i4) + alphabet[columnNumber(currentColumn) + i4]);
			}
		}

		return options;
	}

};
class timer {
	int time;
public:
	void getSecond(int Seconds) {
		for (int i = 0; i <Seconds; i++) {
			cout << "|" << endl;
			Sleep(1000);
		}
	}
};
class board {
	string alphabet[8] = { "a","b","c","d","e","f","g","h" };
	string status[8][8];

	int columnNumber(string c) {
		for (int i = 0; i < 8; i++) {
			if (alphabet[i] == c) {
				return  i;
			}
		}
	}

public:
	board() {
		reset();
	}

	void reset() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				status[i][j] = "em";//referes to empty
			}
		}
	}



	void setThisPieceIntoTheStatusTable(string NAMEOFPIECE,int ROW, string COLUMN ) {
			status[ROW-1][columnNumber(COLUMN)] = NAMEOFPIECE;

	}
	string whatIsInThisPositon(int ROW,string COLUMN) {
		return(status[ROW-1][columnNumber(COLUMN)]);
	}
	string whatIsInThisPositon(string POSITION) {
		string srow = " "; srow[0] = POSITION[0];
		int ROW = stoi(srow);
		string COLUMN = " "; COLUMN[0] = POSITION[1];
		return(status[ROW - 1][columnNumber(COLUMN)]);
	}

	string whatIsInThisPositon(int ROW, int COLUMN) {
		return(status[ROW-1][COLUMN]);
	}



	bool checkIfThisPlaceIsEmpty(int ROW, string COLUMN) {
		if (whatIsInThisPositon(ROW, COLUMN) == "em") {
			return(true);
		}
		else { return false; }
	}

	bool checkIfThisPlaceIsEmpty(string POSITION) {
		string srow = " "; srow[0] = POSITION[0];
		int ROW = stoi(srow);
		string COLUMN = " "; COLUMN[0] = POSITION[1];


		if (whatIsInThisPositon(ROW, COLUMN) == "em") {
			return(true);
		}
		else { return false; }
	}

	bool checkIfThisPlaceOccupiesMyTeammate(int ROW, string COLUMN,string TEAM) {
		if (whatIsInThisPositon(ROW, COLUMN).at(0) == TEAM.at(0)) {
			return(true);
		}
		else {
			return false;
		}
	}

	bool checkIfThisPlaceOccupiesMyTeammate(string POSITION, string TEAM) {
		string srow = " "; srow[0] = POSITION[0];
		int ROW = stoi(srow);
		string COLUMN = " "; COLUMN[0] = POSITION[1];

		if (whatIsInThisPositon(ROW, COLUMN).at(0) == TEAM.at(0)) {
			return(true);
		}
		else {
			return false;
		}
	}
	

};
class file {
	string data;

public:

	file() {
		ifstream read("file.txt");
		string temp;
		int i = -1;
		while (!read.eof()) {
			i++;
			read >> temp;
			if ((i % 3 == 1 || i % 3 == 2)) {
				data += "\t";
			}
			if (i % 3 == 0 && i > 1) {
				data += "\n";
			}
			data += temp;
		}
	}

	void writeDefaultDataToTheFile() {
		data = "BR1\t0\t0\n";
		data += "BN1\t0\t0\n";
		data += "BB1\t0\t0\n";
		data += "BQ\t0\t0\n";
		data += "BK\t0\t0\n";
		data += "BB2\t0\t0\n";
		data += "BN2\t0\t0\n";
		data += "BR2\t0\t0\n";
		data += "BP1\t0\t0\n";
		data += "BP2\t0\t0\n";
		data += "BP3\t0\t0\n";
		data += "BP4\t0\t0\n";
		data += "BP5\t0\t0\n";
		data += "BP6\t0\t0\n";
		data += "BP7\t0\t0\n";
		data += "BP8\t0\t0\n";

		data += "WR1\t0\t0\n";
		data += "WN1\t0\t0\n";
		data += "WB1\t0\t0\n";
		data += "WQ\t0\t0\n";
		data += "WK\t0\t0\n";
		data += "WB2\t0\t0\n";
		data += "WN2\t0\t0\n";
		data += "WR2\t0\t0\n";
		data += "WP1\t0\t0\n";
		data += "WP2\t0\t0\n";
		data += "WP3\t0\t0\n";
		data += "WP4\t0\t0\n";
		data += "WP5\t0\t0\n";
		data += "WP6\t0\t0\n";
		data += "WP7\t0\t0\n";
		data += "WP8\t0\t0\n";
		ofstream write("file.txt");
		write << data;
	}

	string getRow(string PIECENAME) {
		int pos = data.find(PIECENAME);
		int length = PIECENAME.length();
		stringstream ss;
		string s;
		char c = data.at(pos + length + 1);
		ss << c;
		ss >> s;
		return s;
	}

	string getColumn(string PIECENAME) {
		int pos = data.find(PIECENAME);
		int length = PIECENAME.length();
		stringstream ss;
		string s;
		char c = data.at(pos + length + 3);
		ss << c;
		ss >> s;
		return s;
	}

	void setRow(string PIECENAME, int ROW) {
		int pos = data.find(PIECENAME);
		int length = PIECENAME.length();
		data.at(pos + length + 1) = to_string(ROW).at(0);
		ofstream write("file.txt");
		write << data;
	}
	void setColumn(string PIECENAME, string COLUMN) {
		int pos = data.find(PIECENAME);
		int length = PIECENAME.length();
		data.at(pos + length + 3) = COLUMN.at(0);
		ofstream write("file.txt");
		write << data;
	}

};
class management {
	string alphabet[8] = { "a","b","c","d","e","f","g","h" };
	pieces* ptrArrayOfPieces[32];

	board Board;
	userinterface UI;
	timer time;
	file File;
	pawn BP1;
	pawn BP2;
	pawn BP3;
	pawn BP4;
	pawn BP5;
	pawn BP6;
	pawn BP7;
	pawn BP8;
	rook BR1;
	rook BR2;
	knight BN1;
	knight BN2;
	bishop BB1;
	bishop BB2;
	queen BQ;
	king BK;

	pawn WP1;
	pawn WP2;
	pawn WP3;
	pawn WP4;
	pawn WP5;
	pawn WP6;
	pawn WP7;
	pawn WP8;
	rook WR1;
	rook WR2;
	knight WN1;
	knight WN2;
	bishop WB1;
	bishop WB2;
	queen WQ;
	king WK;

public:
	management() {
		ptrArrayOfPieces[0] = &BP1;
		ptrArrayOfPieces[1] = &BP2;
		ptrArrayOfPieces[2] = &BP3;
		ptrArrayOfPieces[3] = &BP4;
		ptrArrayOfPieces[4] = &BP5;
		ptrArrayOfPieces[5] = &BP6;
		ptrArrayOfPieces[6] = &BP7;
		ptrArrayOfPieces[7] = &BP8;
		ptrArrayOfPieces[8] = &BR1;
		ptrArrayOfPieces[9] = &BR2;
		ptrArrayOfPieces[10] = &BN1;
		ptrArrayOfPieces[11] = &BN2;
		ptrArrayOfPieces[12] = &BB1;
		ptrArrayOfPieces[13] = &BB2;
		ptrArrayOfPieces[14] = &BQ;
		ptrArrayOfPieces[15] = &BK;

		ptrArrayOfPieces[16] = &WP1;
		ptrArrayOfPieces[17] = &WP2;
		ptrArrayOfPieces[18] = &WP3;
		ptrArrayOfPieces[19] = &WP4;
		ptrArrayOfPieces[20] = &WP5;
		ptrArrayOfPieces[21] = &WP6;
		ptrArrayOfPieces[22] = &WP7;
		ptrArrayOfPieces[23] = &WP8;
		ptrArrayOfPieces[24] = &WR1;
		ptrArrayOfPieces[25] = &WR2;
		ptrArrayOfPieces[26] = &WN1;
		ptrArrayOfPieces[27] = &WN2;
		ptrArrayOfPieces[28] = &WB1;
		ptrArrayOfPieces[29] = &WB2;
		ptrArrayOfPieces[30] = &WQ;
		ptrArrayOfPieces[31] = &WK;



		ptrArrayOfPieces[0]->setName("BP1");
		ptrArrayOfPieces[1]->setName("BP2");
		ptrArrayOfPieces[2]->setName("BP3");
		ptrArrayOfPieces[3]->setName("BP4");
		ptrArrayOfPieces[4]->setName("BP5");
		ptrArrayOfPieces[5]->setName("BP6");
		ptrArrayOfPieces[6]->setName("BP7");
		ptrArrayOfPieces[7]->setName("BP8");
		ptrArrayOfPieces[8]->setName("BR1");
		ptrArrayOfPieces[9]->setName("BR2");
		ptrArrayOfPieces[10]->setName("BN1");
		ptrArrayOfPieces[11]->setName("BN2");
		ptrArrayOfPieces[12]->setName("BB1");
		ptrArrayOfPieces[13]->setName("BB2");
		ptrArrayOfPieces[14]->setName("BQ");
		ptrArrayOfPieces[15]->setName("BK");

		ptrArrayOfPieces[16]->setName("WP1");
		ptrArrayOfPieces[17]->setName("WP2");
		ptrArrayOfPieces[18]->setName("WP3");
		ptrArrayOfPieces[19]->setName("WP4");
		ptrArrayOfPieces[20]->setName("WP5");
		ptrArrayOfPieces[21]->setName("WP6");
		ptrArrayOfPieces[22]->setName("WP7");
		ptrArrayOfPieces[23]->setName("WP8");
		ptrArrayOfPieces[24]->setName("WR1");
		ptrArrayOfPieces[25]->setName("WR2");
		ptrArrayOfPieces[26]->setName("WN1");
		ptrArrayOfPieces[27]->setName("WN2");
		ptrArrayOfPieces[28]->setName("WB1");
		ptrArrayOfPieces[29]->setName("WB2");
		ptrArrayOfPieces[30]->setName("WQ");
		ptrArrayOfPieces[31]->setName("WK");

		////defining the team
		for (int i = 0; i < 32; i++) {
			string name = ptrArrayOfPieces[i]->getName();
			if (name.at(0) == 'B') {
				ptrArrayOfPieces[i]->setTeam(0);
			}
			if (name.at(0) == 'W') {
				ptrArrayOfPieces[i]->setTeam(1);
			}
		}
	}





	void defaultPosition() {
		/////defining the default position
		for (int i = 0; i < 32; i++) {
			ptrArrayOfPieces[i]->defaultPosition();
			File.setRow(ptrArrayOfPieces[i]->getName(), ptrArrayOfPieces[i]->getRow());
			File.setColumn(ptrArrayOfPieces[i]->getName(), ptrArrayOfPieces[i]->getColumn());
			Board.setThisPieceIntoTheStatusTable(ptrArrayOfPieces[i]->getName(), ptrArrayOfPieces[i]->getRow(), ptrArrayOfPieces[i]->getColumn());
			UI.putAWordIntoTheTable(ptrArrayOfPieces[i]->getName(), ptrArrayOfPieces[i]->getRow(), ptrArrayOfPieces[i]->getColumn());
		}
		system("cls");
		UI.draw();
	}







	void readDataFromTheFile() {
		Board.reset();
		UI.reset();
		for (int i = 0; i < 32; i++) {
			if (File.getRow(ptrArrayOfPieces[i]->getName()) != "0") {
				ptrArrayOfPieces[i]->setPosition(stoi(File.getRow(ptrArrayOfPieces[i]->getName())), File.getColumn(ptrArrayOfPieces[i]->getName()));
				Board.setThisPieceIntoTheStatusTable(ptrArrayOfPieces[i]->getName(), ptrArrayOfPieces[i]->getRow(), ptrArrayOfPieces[i]->getColumn());
				UI.putAWordIntoTheTable(ptrArrayOfPieces[i]->getName(), ptrArrayOfPieces[i]->getRow(), ptrArrayOfPieces[i]->getColumn());
			}
		}
		system("cls");
		UI.draw();
	
	}







	int columnNumber(string c) {
		for (int i = 0; i < 8; i++) {
			if (alphabet[i] == c) {
				return 1 + i;
			}
		}
	}






	vector<string> pathGenerator(string CURRENTPOSITION, string NEWPOSITION) {
		vector<string> path;
		string currentColumn = " "; currentColumn[0] = CURRENTPOSITION[1];
		string newColumn = " "; newColumn[0] = NEWPOSITION[1];
		string sCurrentRow = " "; sCurrentRow[0] = CURRENTPOSITION[0];
		int currentRow = stoi(sCurrentRow);
		string sNewRow = " "; sNewRow[0] = NEWPOSITION[0];
		int newRow = stoi(sNewRow);

		//-
		int initial1 = columnNumber(currentColumn);
		int final1 = columnNumber(newColumn);
		if (initial1 < final1) {
			if (currentRow == newRow) {
				
				for (int k = 0; k <(final1-initial1); k++) {
					path.push_back(to_string(currentRow) + alphabet[(initial1+k)]);
				}
			}

		}
		if (initial1 > final1) {
			if (currentRow == newRow) {
				for (int k =0; k<(initial1-final1);k++) {
					path.push_back(to_string(currentRow) + alphabet[initial1-(k+2)]);
				}
			}
		}

		//|
		int initial2 = currentRow;
		int final2 = newRow;
		if (initial2< final2) {
			if (currentColumn == newColumn) {
				for (int k = 0; k<(final2-initial2); k++) {
					path.push_back(to_string(initial2+k+1) + currentColumn);
				}
			}
		}
		if(currentColumn == newColumn) {
			if (initial2 > final2) {
				for (int k = 0; k<(initial2-final2); k++) {
					path.push_back(to_string(initial2- (k+1)) + currentColumn);
				}
			}
		}
		
		//  /
		int initialRow = currentRow;
		string initialColumn = currentColumn;
		
		int finalRow = newRow;
		string finalColumn = newColumn;
		if((initialRow - finalRow) && (columnNumber(initialColumn) - columnNumber(finalColumn)))
		if ((initialRow < finalRow) && (columnNumber(initialColumn) > columnNumber(finalColumn))) {
			for (int k = 0; k <(finalRow-initialRow); k++) {
				path.push_back((to_string(initialRow + k+1) + alphabet[columnNumber(initialColumn) - (k+2)]));
			}
		}
		if ((initialRow - finalRow) && (columnNumber(initialColumn) - columnNumber(finalColumn)))
			if ((initialRow > finalRow) && (columnNumber(initialColumn) < columnNumber(finalColumn))) {
				for (int k = 0; k < (initialRow-finalRow); k++) {
					path.push_back(to_string(initialRow - (k+1)) + alphabet[columnNumber(initialColumn) +k]);
				}
			}

		// \       
		if ((initialRow - finalRow) && (columnNumber(initialColumn) - columnNumber(finalColumn)))
		if ((initialRow < finalRow) && (columnNumber(initialColumn) < columnNumber(finalColumn))) {
			for (int k = 0; k < (finalRow-initialRow); k++) {
				path.push_back(to_string(initialRow + k+1) + alphabet[columnNumber(initialColumn) + k ]);
			}
		}
		if ((initialRow - finalRow) && (columnNumber(initialColumn) - columnNumber(finalColumn)))
			if ((initialRow > finalRow) && (columnNumber(initialColumn) > columnNumber(finalColumn))) {
				for (int k = 0; (initialRow- finalRow)>k; k++) {
					path.push_back(to_string(initialRow - (k+1)) + alphabet[columnNumber(initialColumn) - (k+2)]);
				}
			}
		return path;

	}






	vector<string> validOptionsGenerator(vector<string> OPTIONS,board& BOARD,string CURRENTPOSITION,string TEAM){
		vector<string> validOptions;


		if (Board.whatIsInThisPositon(CURRENTPOSITION)[1] != 'N') {
			string status;
			for (int i = 0; i < OPTIONS.size(); i++) {
				int flag = 1;
				vector<string> PATH = pathGenerator(CURRENTPOSITION, OPTIONS[i]);
				for (int j = 0; j < PATH.size() - 1; j++) {
					status = Board.whatIsInThisPositon(PATH[j]);
					if (status != "em") {
						flag = 0;
					}
				}
				status = " ";
				status[0] = Board.whatIsInThisPositon(PATH[PATH.size() - 1])[0];
				if (flag == 1 && (TEAM == status)) {
					flag = 0;
				}
				if (flag == 1) {
					validOptions.push_back(OPTIONS[i]);
				}
			}



		}
		else {
			for (int i = 0; i < OPTIONS.size(); i++) {
				if (Board.whatIsInThisPositon(OPTIONS[i])[0] != TEAM[0]) {
					validOptions.push_back(OPTIONS[i]);
				}
			}
		}
		return validOptions;
	}






	


	void move(string PIECENAME, string NEWPOSITION) {
		for (int i = 0; i < 32; i++) {
			if (ptrArrayOfPieces[i]->getName() == PIECENAME) {

				string team = ptrArrayOfPieces[i]->sGetTeam();

				int  currentRow = ptrArrayOfPieces[i]->getRow();
				string currentColumn = ptrArrayOfPieces[i]->getColumn();

				string stringnewRow = " "; stringnewRow.at(0) = NEWPOSITION.at(0);//temporary and useless
				int newRow = stoi(stringnewRow);
				string newColumn = " "; newColumn.at(0) = NEWPOSITION.at(1);

				string name = "  "; name.at(0) = PIECENAME.at(0); name.at(1) = PIECENAME.at(1);
				string CURRENTPOSITION = to_string(currentRow) + currentColumn;

				if (Board.checkIfThisPlaceIsEmpty(NEWPOSITION) == true) {
					ptrArrayOfPieces[i]->setPosition(newRow, newColumn);

					UI.deleteAWordFromTheTable(currentRow, currentColumn);
					UI.putAWordIntoTheTable(name, newRow, newColumn);

					File.setRow(PIECENAME, newRow);
					File.setColumn(PIECENAME, newColumn);

					Board.setThisPieceIntoTheStatusTable("em", currentRow, currentColumn);
					Board.setThisPieceIntoTheStatusTable(PIECENAME, newRow, newColumn);
				}else{
					File.setColumn(Board.whatIsInThisPositon(NEWPOSITION), "0");
					File.setRow(Board.whatIsInThisPositon(NEWPOSITION), 0);
					
					ptrArrayOfPieces[i]->setPosition(newRow, newColumn);
					
					UI.deleteAWordFromTheTable(currentRow, currentColumn);
					UI.putAWordIntoTheTable(name, newRow, newColumn);

					Board.setThisPieceIntoTheStatusTable("em", currentRow, currentColumn);
					Board.setThisPieceIntoTheStatusTable(PIECENAME, newRow, newColumn);
					
					File.setRow(PIECENAME, newRow);
					File.setColumn(PIECENAME, newColumn);

				}

				system("cls");
				UI.draw();
			}
		}
	}




	int declareWinner() {
		bool wKingIsAlive = false;
		bool bKingIsAlive = false;
		for (int i = 1; i < 9; i++) {
			for (int j = 0; j < 8; j++) {
			//	cout << Board.whatIsInThisPositon(i, j) << endl;
				if (Board.whatIsInThisPositon(i, j) == "BK") {
					bKingIsAlive = true;
				}
				if (Board.whatIsInThisPositon(i, j) == "WK") {
					wKingIsAlive = true;
				}
			}
		}
		if (bKingIsAlive == false) {
			cout << "WHITE TEAM WON" << endl;
			return 1;
		}
		if (wKingIsAlive == false) {
			cout << "BLACK TEAM WON" << endl;
			return 1;
		}
		return 0;
	}




	void RunTwoPlayers() {
		
		int flag = 0;//check the winner
		int turn = 0;

		while (flag == 0) {

			turn++;
			if (turn % 2 == 1) {
				cout << "BLACK" << " turn" << endl;
			}
			else {
				cout << "WHITE" << " turn" << endl;
			}

			int index;
			string place;
			string PIECENAME;
			int choice;


			int flag2 = 0;//if a piece has any choice to move
			while (flag2 == 0) {

				int flag3 = 0;//if user selects from the right team
				while (flag3 == 0) {
					place = UI.whichPositionToMove();
					PIECENAME = Board.whatIsInThisPositon(place);
					if ((turn % 2 == 0 && PIECENAME[0] != 'W') || turn % 2 == 1 && PIECENAME[0] != 'B') {
						cout << "This was not your turn!Chose a place which occupies a piece of your team... " << endl;
					}
					else {
						flag3 = 1;
					}
				}


				for (int i = 0; i < 32; i++) {
					if (ptrArrayOfPieces[i]->getName() == PIECENAME) {
						index = i;
						if (validOptionsGenerator(ptrArrayOfPieces[i]->options(), Board, ptrArrayOfPieces[i]->getPosition(), ptrArrayOfPieces[i]->sGetTeam()).size() != 0) {
							UI.printChoices(validOptionsGenerator(ptrArrayOfPieces[i]->options(), Board, ptrArrayOfPieces[i]->getPosition(), ptrArrayOfPieces[i]->sGetTeam()));
							flag2 = 1;
						}
						else {
							cout << "You don't have any option to move this piece,try again " << endl;
						}
					}
				}
			}
			cin >> choice;
			move(PIECENAME, validOptionsGenerator(ptrArrayOfPieces[index]->options(), Board, ptrArrayOfPieces[index]->getPosition(), ptrArrayOfPieces[index]->sGetTeam())[choice]);
			flag = declareWinner();
		}
	}




	void RunOnePlayer() {
		
		


		
		int flag = 0;//check the winner
		int turn = 0;

		while (flag == 0) {

			turn++;

			int index;
			string place;
			string PIECENAME;
			int choice;


			if (turn % 2 == 1) {
				cout << "BLACK: Your " << " turn" << endl;
				int flag2 = 0;
				while (flag2 == 0) {

					int flag3 = 0;
					while (flag3 == 0) {
						place = UI.whichPositionToMove();
						PIECENAME = Board.whatIsInThisPositon(place);
						if (PIECENAME[0] != 'B') {
							cout << "Chose a place that occupies a BLACK piece" << endl;
						}
						else {
							flag3 = 1;
						}
					}

					for (int i = 0; i < 32; i++) {
					
						if (ptrArrayOfPieces[i]->getName() == PIECENAME) {
							index = i;
						}
					}
					if (validOptionsGenerator(ptrArrayOfPieces[index]->options(), Board, ptrArrayOfPieces[index]->getPosition(), "B").size() != 0) {
						UI.printChoices(validOptionsGenerator(ptrArrayOfPieces[index]->options(), Board, ptrArrayOfPieces[index]->getPosition(), "B"));
						flag2 = 1;
					}
					else { cout << "You don't have any option to move this piece,try again " << endl; }

				}

				cin >> choice;
				move(PIECENAME, validOptionsGenerator(ptrArrayOfPieces[index]->options(), Board, ptrArrayOfPieces[index]->getPosition(), ptrArrayOfPieces[index]->sGetTeam())[choice]);

			}
			else {
				cout << "WHITE : My" << " turn" << endl;

				int flag2 = 0;
				int iter = 0;
				while (flag2 == 0) {
					iter++;
					if (ptrArrayOfPieces[iter]->sGetTeam() == "W" && validOptionsGenerator(ptrArrayOfPieces[iter]->options(), Board, ptrArrayOfPieces[iter]->getPosition(), "W").size() != 0) {
						if (Board.whatIsInThisPositon(ptrArrayOfPieces[iter]->getPosition()) == ptrArrayOfPieces[iter]->getName()) {
							move(ptrArrayOfPieces[iter]->getName(), validOptionsGenerator(ptrArrayOfPieces[iter]->options(), Board, ptrArrayOfPieces[iter]->getPosition(), "W")[0]);
							flag2 = 1;
						}
					}
				}
			}

			flag = declareWinner();
		}
	}



	void RUN() {
		int newOrLoad = UI.newOrLoad();//1:load/2:new



		int numberOFplayers = UI.numberOfPlayers();
		if (newOrLoad == 2) {
			if (numberOFplayers == 2) { defaultPosition(); RunTwoPlayers(); }
			if (numberOFplayers == 1) { system("cls"); cout << "YOU ARE BLACK AND ME,COMPUTER AM WHITE" << endl; Sleep(3000); defaultPosition(); RunOnePlayer(); }
		}
		if (newOrLoad == 1) {
			if (numberOFplayers == 2) { readDataFromTheFile(); RunTwoPlayers(); }
			if (numberOFplayers == 1) { system("cls"); cout << "YOU ARE BLACK AND ME,COMPUTER AM WHITE" << endl; Sleep(3000); readDataFromTheFile(); RunOnePlayer(); }
		}
	}
};
	









int main() {
	
	management m;
	m.RUN();

	
}
#pragma once
#include <iostream>
#include "Position.h"
#include <vector>
#include <set>
#include <algorithm>
#include "JSON.h"
#include "DataBase.h"

struct Cell {
	Cell() {}
	Cell(bool Er) : Error(Er){}
	Cell(TypePosition Intype, Position Inposit) : type(Intype), posit(Inposit) {}
	//bool empty = true;
	TypePosition type = TypePosition::RemoteWarehouse;
	Position posit = Position("000"); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//vector<std::string> includeCell;
	bool Error = false;
	int height = 0;
	string NameCell = "";
};

bool operator<(Cell c1, Cell c2);

class WareHouse {
public:
	WareHouse(); /*{}*/
	WareHouse(POSTJSON data, string DBName);
	void AddElement(Cell ce);
	/*{
		setWareHouse.insert(ce);
	}*/
	Cell GetElementToUUID(const string& uuid); 
	/*{ // ������ �������� �� �������.
		auto it = find_if(setWareHouse.begin(), setWareHouse.end(), [uuid] (Cell c) {
			return c.posit.GetUUid() == uuid;
			});
		if (it != setWareHouse.end()) {
			return *it;
		}
		else {
			return Cell(true); // ���� ������� �� ������, �� ���������� ������ Cell � ������� Error.
		}
	}*/
private:
	int heightWH = 0,
		widthWH = 0,
		depthWH = 0;
	std::vector<std::vector<std::string>> vecCellNotSmall;
	void CreateDBTable(std::vector<Cell> InVecCell);
	DataBase db;
};
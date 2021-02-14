#pragma once;
#include <string>
using namespace std;



enum class TypePosition {
    Small, //1000*1000*1000
    Medium, //1000*2000*1000
    Big, //2000*2000*1000
    RemoteWarehouse //�������� �����.
};
 
class TypeAndSizePosition {
public:
    TypeAndSizePosition() {}
    TypeAndSizePosition(const int& x, const int& y, const int& z) {
        // Small
        if (x <= 1000 and y <= 1000 and z <= 1000) {
            height = x;
            width = y;
            depth = z;
            type = TypePosition::Small;
        }

        // Medium

        else if (x <= 1000 and y <= 2000 and z <= 1000) {
            height = x;
            width = y;
            depth = z;
            type = TypePosition::Medium;
        }

        else if (x <= 2000 and y <= 1000 and z <= 1000) {
            height = y;
            width = x;
            depth = z;
            type = TypePosition::Medium;
        }

        else if (x <= 1000 and y <= 1000 and z <= 2000) {
            height = z;
            width = y;
            depth = x;
            type = TypePosition::Medium;
        }

        //Big

        else if (x <= 2000 and y <= 2000 and z <= 1000) {
            height = x;
            width = y;
            depth = z;
            type = TypePosition::Big;
        }

        else if (x <= 2000 and y <= 1000 and z <= 2000) {
            height = x;
            width = z;
            depth = y;
            type = TypePosition::Big;
        }

        else if (x <= 1000 and y <= 2000 and z <= 2000) {
            height = z;
            width = y;
            depth = x;
            type = TypePosition::Big;
        }

        else {
            height = x;
            width = y;
            depth = z;
            type = TypePosition::RemoteWarehouse;
        }
    }
    TypePosition GetType() {
        return type;
    }
    int GetHeight() { return height; }
    int GetWidth() { return width; }
    int GetDepth() { return depth; }
private:
    int height = 0;
    int width = 0;
    int depth = 0;
    TypePosition type = TypePosition::RemoteWarehouse;
};

string operator+(string st, TypePosition tp);

class Position {
public:
    Position(){}
    Position(string InName, int InWeight, TypeAndSizePosition InSizeAndType) : name(InName), weigt(InWeight), sizeAndType(InSizeAndType) {
        //uuid = generateUUID()
    }
    Position(string InName, int InWeight, TypeAndSizePosition InSizeAndType, string InUuid) : name(InName),
                                        weigt(InWeight), sizeAndType(InSizeAndType), uuid(InUuid) {
        //uuid = generateUUID()
    }
    Position(string InUUID) : uuid(InUUID) {} //debug, delete continue!!!!!!
    string GetUUid() {
        return uuid;
    }
    TypePosition GetTypePosition() {
        return sizeAndType.GetType();
    }
    int GetWeigt() { return weigt; }
    int GetDepth() { return sizeAndType.GetDepth(); }
    int GetHeight() { return sizeAndType.GetHeight(); }
    int GetWidth() { return sizeAndType.GetWidth(); }
    std::string GetName() { return name; }
    std::string GetComment() { return comment; }
private:
    std::string name;
    int weigt;
    TypeAndSizePosition sizeAndType;
    std::string uuid;
    std::string comment = "";
};
void Test();
/* unit test:
        300*300*300 -> Small
        200*500*2100 -> RemoteWarehouse
        1000*1200*2000 -> Big
        

        
*/

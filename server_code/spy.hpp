#include "./block.hpp"
#include "./log.hpp"
#include "./position.hpp"
class Spy
{
private:
    Position _pos;
    int _hp;

public:
    Movement legalAction()
    {
        Movement result;
        result.enableUp = true;
        result.enableDown = true;
        result.enableLeft = true;
        result.enableRight = true;
        if(_pos.colsIndex==0){
            result.enableLeft=false;
        }
        if(_pos.colsIndex==4){
            result.enableRight=false;
        }
        if(_pos.rowsIndex==0){
            result.enableUp=false;
        }
        if(_pos.rowsIndex==4){
            result.enableDown=false;
        }
        log("Spy.legalAction:Success!");

        return result;
    }

    bool move(Movement _to, const Block *src)
    {
        int checkSum = _to.enableUp+_to.enableDown+_to.enableLeft+_to.enableRight;
        if(checkSum!=1){
            log("Spy.move:move directions not equal to 1!");
            return false;
        }
        if(_to.enableUp==true){
            _pos.rowsIndex-=1;
        }
        if(_to.enableDown==true){
            _pos.rowsIndex+=1;
        }
        if(_to.enableLeft==true){
            _pos.colsIndex-=1;
        }
        if(_to.enableRight==true){
            _pos.colsIndex+=1;
        }
        log("Spy.move:Success!");
        return true;
    }
};

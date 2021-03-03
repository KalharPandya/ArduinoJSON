#include "./unit/unit.h"
#define MAX_UNITS 100

class json{
    public:
    int index = 0;
    unit *units[MAX_UNITS];
    String result;
    void addUnit(String key, String value){
        units[index] = new unit();
        units[index]->setKey(key);
        units[index]->setValue(value);
        index++;
    }
    void addUnit(String key, double value){
        units[index] = new unit();
        units[index]->setKey(key);
        units[index]->setValue(value);
        index++;
    }
    void addUnit(String key, long value){
        units[index] = new unit();
        units[index]->setKey(key);
        units[index]->setValue(value);
        index++;
    }
    void addUnit(String key, int value){
        addUnit(key,long(value));
    }
    void addUnit(String key, float value){
        addUnit(key,double(value));
    }
    unit* findUnit(String key){
        for(int i = 0 ; i < index ; i ++){
            if(units[i]->getKey() == key){
                return units[i];
            }
        }
    }
    String getStringValue(String key){
        unit * found_unit = findUnit(key);
        return found_unit->value->str_data;
    }
    long getNumberValue(String key){
        unit * found_unit = findUnit(key);
        return found_unit->value->number_data;
    }
    double getDoubleValue(String key){
        unit * found_unit = findUnit(key);
        return found_unit->value->double_data;
    }
    void clear(){
        index = 0;
    }
    String getString(){
        result = "{";
        for(int i = 0 ; i < index ; i ++){
            result+=units[i]->getString();
            if(i!=index-1){
                result+=',';
            }
        }
        result+="}";
        return result;
    }
};
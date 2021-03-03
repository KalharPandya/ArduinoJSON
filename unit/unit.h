#include "../uni_data/uni_data.h"
class unit{
    
    public:
    String key;
    uni_data *value;
    unit(){
        value = new uni_data();
    }
    String getKey(){
        return key;
    }

    uni_data* getValue(){
        return value;
    }

    void setKey(String k){
        key = k;
    }
    void setValue( long d){
        value->setData(d);
    }
    void setValue(String d){
        value->setData(d);
    }
    void setValue(double d){
        value->setData(d);
    }

    String getString(){
        return key+":"+value->getString();
    }
};
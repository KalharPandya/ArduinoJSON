#include"ArduinoJSON.h"

class optimizedJSON{
    public:
    String jsonString;
    bool has(String key)
    {
        
    }
    void setTemp(){
        parsed = parseJSON(this->jsonString);
    }

    void updateString(){
        this->jsonString = parsed.getString();
    }

    void addUnit(String key, String value)
    {
        this->setTemp();
        parsed.addUnit(key,value);
        this->updateString();
    }
    void addUnit(String key, double value)
    {
        this->setTemp();
        parsed.addUnit(key,value);
        this->updateString();
        
    }
    void addUnit(String key, long value)
    {
        this->setTemp();
        parsed.addUnit(key,value);
        this->updateString();
    }
    void addUnit(String key, int value)
    {
        this->setTemp();
        parsed.addUnit(key,value);
        this->updateString();
    }
    void addUnit(String key, float value)
    {
        this->setTemp();
        parsed.addUnit(key,value);
        this->updateString();
    }
    unit *findUnit(String key)
    {
        this->setTemp();
        return parsed.findUnit(key);
        this->updateString();
    }
    String getValue(String key)
    {
        this->setTemp();
        return parsed.getValue(key);
        this->updateString();
    }
    long getNumberValue(String key)
    {
        this->setTemp();
        return parsed.getNumberValue(key);
        this->updateString();
    }
    double getDoubleValue(String key)
    {
        this->setTemp();
        return parsed.getDoubleValue(key);
        this->updateString();
    }
    void clear()
    {
        this->setTemp();
        parsed.clear();
        this->updateString();
    }
    void updateValue(String key, String Value)
    {
        this->setTemp();
        parsed.updateValue(key,value);
        this->updateString();
    }
    void updateValue(String key, long Value)
    {
        this->setTemp();
        parsed.updateValue(key,value);
        this->updateString();
    }
    void updateValue(String key, double Value)
    {
        this->setTemp();
        parsed.updateValue(key,value);
        this->updateString();
    }

    void updateValue(String key, int Value)
    {
        this->setTemp();
        parsed.updateValue(key,value);
        this->updateString();
    }
    void updateValue(String key, float Value)
    {
        this->setTemp();
        parsed.updateValue(key,value);
        this->updateString();
    }
    void remove(String key)
    {
        this->setTemp();
        parsed.remove(key);
        this->updateString();
    }
    String getString(bool withEscape = false)
    {
        this->setTemp();
        return parsed.getString(withEscape);
    }
}parsedOptimized;

optimizedJSON toOptimize(json j){
    parsedOptimized.jsonString = j.getString();
    return parsedOptimized;
}
optimizedJSON parseOptimizedJSON(String j){
    parsedOptimized.jsonString = j;
    return parsedOptimized;
}

json toNormal(optimizedJSON j){
    return parseJSON(j.jsonString);
}


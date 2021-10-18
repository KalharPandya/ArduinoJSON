#include "./unit/unit.h"
#define MAX_UNITS 1500//Decrease This for Arduino
unit invalidUnit;
class json
{
public:
    int index = 0;
    unit *units[MAX_UNITS];
    String result;
    json()
    {
        invalidUnit.setKey("Invalid");
        invalidUnit.value->setType(-1);
        // for (int i = 0; i < MAX_UNITS; i++)
        // {
        //     units[i] = new unit();
        // }
    }
    bool has(String key)
    {
        for (int i = 0; i < index; i++)
        {
            if (units[i]->getKey() == key)
            {
                return true;
            }
        }
        return false;
    }
    void addUnit(String key, String value)
    {
        if (has(key))
        {
            updateValue(key, value);
            return;
        }
        if (index >= MAX_UNITS)
        {
            Serial.println("JSON units Limit Reached");
            return;
        }
        units[index] = new unit();
        units[index]->setKey(key);
        units[index]->setValue(value);
        index++;
    }
    void addUnit(String key, double value)
    {
        if (has(key))
        {
            updateValue(key, value);
            return;
        }
        else if (index >= MAX_UNITS)
        {
            Serial.println("JSON units Limit Reached");
            return;
        }
        units[index] = new unit();
        units[index]->setKey(key);
        units[index]->setValue(value);
        index++;
    }
    void addUnit(String key, long value)
    {
        if (has(key))
        {
            updateValue(key, value);
            return;
        }
        else if (index >= MAX_UNITS)
        {
            Serial.println("JSON units Limit Reached");
            return;
        }
        units[index] = new unit();
        units[index]->setKey(key);
        units[index]->setValue(value);
        index++;
    }
    void addUnit(String key, int value)
    {
        addUnit(key, long(value));
    }
    void addUnit(String key, float value)
    {
        addUnit(key, double(value));
    }
    unit *findUnit(String key)
    {
        for (int i = 0; i < index; i++)
        {
            if (units[i]->getKey() == key)
            {
                return units[i];
            }
        }
        return &invalidUnit;
    }
    String getValue(String key)
    {
        unit *found_unit = findUnit(key);
        return found_unit->value->getStringValue();
    }
    long getNumberValue(String key)
    {
        unit *found_unit = findUnit(key);
        return found_unit->value->getNumberValue();
    }
    double getDoubleValue(String key)
    {
        unit *found_unit = findUnit(key);
        return found_unit->value->getDoubleValue();
    }
    void clear()
    {

        while(index > 0){
            delete units[index-1];
            index -= 1;
        }
    }
    void updateValue(String key, String Value)
    {
        unit *found_unit = findUnit(key);
        found_unit->setValue(Value);
    }
    void updateValue(String key, long Value)
    {
        unit *found_unit = findUnit(key);
        found_unit->setValue(Value);
    }
    void updateValue(String key, double Value)
    {
        unit *found_unit = findUnit(key);
        found_unit->setValue(Value);
    }

    void updateValue(String key, int Value)
    {
        updateValue(key, long(Value));
    }
    void updateValue(String key, float Value)
    {
        updateValue(key, double(Value));
    }
    void remove(String key)
    {
        for (int i = 0; i < index; i++)
        {
            Serial.printf("i = %d\n",i);

            if (units[i]->getKey() == key)
            {
                
                delete units[i]; 
                for (int j = i; j < index - 1; j++)
                {
                    Serial.printf("j = %d\n",j);
                    units[j] = units[j + 1];
                    Serial.printf("j afrter = %d\n",j);

                }
                 
                    Serial.printf("j afrter deleting = %d\n",index - 1 );

                index -= 1;  
                break;
            }
        }
    }
    String getString(bool withEscape = false)
    {
        result = "{";
        for (int i = 0; i < index; i++)
        {
            Serial.printf("Accessing Index %d\n", i);
            result += units[i]->getString(withEscape);
            
            Serial.printf("Accessing Index %d\n", i);
            if (i != index - 1)
            {
                result += ',';
            }
        }
        result += "}";
        String esc = withEscape ? "\"" : "";
        return esc + result + esc;
    }
    ~json(){
        for(int i = 0 ; i < index ; i ++){
            delete units[i];
        }
    }
};
#include "./unit/unit.h"
#define MAX_UNITS 10
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
        invalidUnit.value->double_data = -1;
        invalidUnit.value->number_data = -1;
        invalidUnit.value->str_data = "";
        for (int i = 0; i < MAX_UNITS; i++)
        {
            units[i] = new unit();
        }
    }
    void addUnit(String key, String value)
    {
        units[index]->setKey(key);
        units[index]->setValue(value);
        index++;
    }
    void addUnit(String key, double value)
    {
        units[index]->setKey(key);
        units[index]->setValue(value);
        index++;
    }
    void addUnit(String key, long value)
    {
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
        return found_unit->value->str_data;
    }
    long getNumberValue(String key)
    {
        unit *found_unit = findUnit(key);
        return found_unit->value->number_data;
    }
    double getDoubleValue(String key)
    {
        unit *found_unit = findUnit(key);
        return found_unit->value->double_data;
    }
    void clear()
    {
        index = 0;
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
            if (units[i]->getKey() == key)
            {
                for (int j = i; j < index - 1; j++)
                {
                    units[j] = units[j + 1];
                }
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
            result += units[i]->getString(withEscape);
            if (i != index - 1)
            {
                result += ',';
            }
        }
        result += "}";
        String esc = withEscape ? "\"" : "";
        return esc + result + esc;
    }
};
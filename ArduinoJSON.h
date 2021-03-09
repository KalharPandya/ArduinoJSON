#include "JsonType/JsonType.h"
#include <string.h>
json parsed;

int found = 0;
int strIndex[] = {0, -1};
int maxIndex = 0;
bool isNumber = true;
bool isDouble = true;
bool isString = true;
long result = 0;
String value;
String key;

int knowTokenType(String token)
{
    isNumber = true;
    isDouble = true;
    isString = true;
    for (int i = 0; i < token.length(); i++)
    {
        if (!isDigit(token[i]))
        {
            isNumber = false;
            if (token[i] != '.')
            {
                isDouble = false;
                return STRING;
            }
        }
    }
    if (isNumber)
        return NUMBER;
    if (isDouble)
        return DOUBLE;
    if (isString)
        return STRING;
    return -1;
}

long getNumber(String token)
{
    result = 0;
    for (int i = 0; i < token.length(); i++)
    {
        result = result * 10 + (token[i] - '0');
    }
    return result;
}
double getDouble(String token)
{
    return token.toDouble();
}

String strSplit(String data,  char separator, int index)
{
    // Serial.println("Splitting   "+data);
    int index_cnt = -1;
    data += separator;
    String token = "";
    for(int i = 0 ; i < data.length(); i ++){
        if(data[i] == separator){
            index_cnt+=1;
            if(index_cnt == index){
                return token;
            }
            token = "";
        }
        else
            token+=data[i];
    }
}
void createUnit(String token)
{
    key = strSplit(token, ':', 0);
    
    key.remove(0, 1);
    key.remove(key.length() - 1, 1);
    value = strSplit(token, ':', 1);
    
    // Serial.println("Value = " + value);
    switch (knowTokenType(value))
    {
    case STRING:
        value.remove(0, 1);
        value.remove(value.length() - 1, 1);
        parsed.addUnit(key, value);
        break;
    case NUMBER:
        parsed.addUnit(key, getNumber(value));
        break;
    case DOUBLE:
        parsed.addUnit(key, double(getDouble(value)));
        break;
    default:
        parsed.addUnit(key, value);
    }
}
json parseJSON(String jsonStr)
{
    jsonStr.remove(0, 1);
    jsonStr.remove(jsonStr.length() - 1, 1);
    // Serial.println(jsonStr);
    parsed.clear();
    int i = 0;
    String token;
    do
    {   
        token = strSplit(jsonStr, ',', i);
        if(token == "")
            break;
        createUnit(token);
        i++;
    }while (token != "");
    return parsed;
}
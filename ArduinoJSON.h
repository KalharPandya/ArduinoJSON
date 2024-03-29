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
json noJson;
int knowTokenType(String token)
{
    isNumber = true;
    isDouble = true;
    isString = true;
    for (int i = 0; i < token.length(); i++)
    {
        if (!isDigit(token[i])){

            isNumber = false;
            if(token[i] == '-'&& i == 0){
                isNumber = true;
            }
            else if (token[i] != '.')
            {
                isDouble = false;
            }
        }
    }
    if (isNumber)
    {
        //Serial.println("Number");
        return NUMBER;
    }
    if (isDouble)
    {
        //Serial.println("Double");
        return DOUBLE;
    }
    if (isString)
    {
        //Serial.println("String");
        return STRING;
    }
    return -1;
}

long getNumber(String token)
{
    result = token.toInt();
    
    return result;
}
double getDouble(String token)
{
    return token.toDouble();
}

String strSplit(String data, char separator, int index)
{
    // Serial.println("Splitting   "+data);
    int index_cnt = -1;
    data += separator;
    String token = "";
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == separator)
        {
            index_cnt += 1;
            if (index_cnt == index)
            {
                return token;
            }
            token = "";
        }
        else
            token += data[i];
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
String findJSON(String raw, char start = '{', char finish = '}')
{
    String json = "";

    for (int i = 0; i < raw.length(); i++)
    {
        if (raw[i] == start)
        {
            while (raw[i - 1] != finish && i<raw.length())
            {
                json += raw[i];
                i++;
            }
            if(i == raw.length()){
                return "";
            }
            break;
        }
    }
    return json;
}
bool isJsonString(String jsonStr){

    jsonStr = findJSON(jsonStr);
    if (jsonStr.length() == 0)
    {
        return false;
    }
    return true;
}
json parseJSON(String jsonStr)
{
    jsonStr = findJSON(jsonStr);
    if(jsonStr.length() == 0){
        noJson.clear();
        noJson.addUnit("error", "No Json Found");
        return noJson;
    }
    jsonStr.remove(0, 1);
    jsonStr.remove(jsonStr.length() - 1, 1);
    parsed.clear();
    int i = 0;
    String token;
    do
    {
        token = strSplit(jsonStr, ',', i);
        if (token == "")
            break;
        createUnit(token);
        i++;
    } while (token != "");
    return parsed;
}

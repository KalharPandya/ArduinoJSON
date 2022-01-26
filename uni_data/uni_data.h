#define DOUBLE 1
#define NUMBER 2
#define STRING 3

class uni_data{
    public:
    uint8_t type;
    String str_data;
    double double_data;
    long number_data;
    void setData(String d){
        this->str_data = d;
        type = STRING;
    }
    void setData(double d){
        this->double_data = d;
        type = DOUBLE;
    }
    void setData(long d){
        this->number_data = d;
        type = NUMBER;
    }
    String getType(){
        switch (type)
        {
        case (DOUBLE):
            return "double";
            break;
        case (NUMBER):
            return "number";
            break;
        case (STRING):
            return "string";
            break;
        default:
            return "none";
        }
    }
    String getString(bool withEscape){
        String esc = withEscape?"\\":"";
        switch (type)
        {
        case (DOUBLE):
            return String(double_data);
            break;
        case (NUMBER):
            return String(number_data);
            break;
        case (STRING):
            return esc+"\""+String(str_data)+esc+"\"";
            break;
        default:
            return "error";
        }
    }
};
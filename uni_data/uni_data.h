#define DOUBLE 1
#define NUMBER 2
#define STRING 3

class uni_data{
    public:
    uint8_t type = -1;
    String *str_data;
    double *double_data;
    long *number_data;
    void clear_past(){
        delete double_data;
        delete number_data;
        delete str_data;
    }
    void setType(int i){
        type = i;
    }
    void setData(String d){
        clear_past();
        str_data = new String();
        *this->str_data = d;
        type = STRING;
    }
    void setData(double d){
        clear_past();
        double_data = new double();
        *this->double_data = d;
        type = DOUBLE;
    }
    void setData(long d){
        clear_past();
        number_data = new long();
        *this->number_data = d;
        type = NUMBER;
    }
    double getDoubleValue(){
        return *double_data;
    }
    String getStringValue(){
        return *str_data;
    }
    long getNumberValue(){
        return *number_data;
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
            return String(*double_data);
            break;
        case (NUMBER):
            return String(*number_data);
            break;
        case (STRING):
            return esc+"\""+String(*str_data)+esc+"\"";
            break;
        default:
            return "error";
        }
    }

    ~uni_data(){
        clear_past();
    }
};
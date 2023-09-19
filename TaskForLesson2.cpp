#include <iostream>
#include <cstring>

using namespace std;

class FooString{
    char* buf;
    public:
        FooString(char* tbuf){
            buf = new char[strlen(tbuf) + 1];
            strcpy(buf, tbuf);
        }
    
        
        bool compare(char* str){
                return (str == buf || !strcmp(str,buf));
            }


        void show(char* str){
            cout << compare(str);
        }
        ~FooString(){
            delete [] buf;
        }
};

int main(){
    char* text_one = "stroka";
    char* text_two = "stooka";

    FooString a(text_one);
    a.show(text_two);
    
    char* result;
    if (strlen(text_one) != strlen(text_two)){
        result = "different strings";
    }
    else{
        
            if (!!strcmp(text_one,text_two)){
                result = "different strings";
            }
            else result = "equal strings";
        }

    cout << result;

    cout << "\n" << "Если выведен (0different strings) ИЛИ (1equal strings), то результат сравнения в классе верный)";

    return 0;
}

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
    FooString a("stroka");
    a.show("stroka");
    return 0;
}
#include <iostream>
using namespace std;
class AList: public List{
    private:
        int maxSize;
        int listSize;
        int curr;
        int listArray ;
    public:
    AList(int size = 2){
        maxSize = size;
        listSize = curr = 0;
        listArray = new int[maxSize];
    }

    ~AList(){
        delete [] listArray;
    }
    //to be continued
}
int main(){
    return 0;
}
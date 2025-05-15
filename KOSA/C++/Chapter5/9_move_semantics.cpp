#include <iostream>
#include <string>



class Integer{
public:
    int *val;
    Integer() = default;
    Integer(int val) {
        this->val = new int(val);
    }
    Integer(Integer &&obj){
        val = obj.val;
        obj.val = nullptr;
    }
    ~Integer(){
        delete val;
    }
};

Integer Add(const Integer &a, const Integer &b){
    Integer tmp;
    tmp.val = new int(a.val + b.val);
    return tmp;
}

int main(){
    Integer i1(1), i2(3);
    i1.val = Add(i1,i2).val;
    std::cout << i1.val;
}
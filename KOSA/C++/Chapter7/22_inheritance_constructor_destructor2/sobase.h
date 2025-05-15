class SoBase{
private:
    int baseNum;
public:
    SoBase();
    ~SoBase();
    SoBase(int n);
    void ShowBaseData();
};


class SoDerived : public SoBase{
private:
    int derivNum;
public:
    SoDerived();
    ~SoDerived();
    SoDerived(int N);
    SoDerived(int n1, int n2);
    void ShowDerivData();
};
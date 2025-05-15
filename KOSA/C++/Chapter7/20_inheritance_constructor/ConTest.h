

class Con1{
public:
    Con1(const int c);
    //~Con1();
protected:
    int c;
};

class Con2 : public Con1{
public:
    Con2(const int c);
    //~Con1();
protected:
    int c;
};


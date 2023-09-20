class Line{
private: 
    double slope, intercept;

public:
    Line(double k, double b);
    void Print();
    void operator *(double ck);
    void operator +(double cb);
    bool operator ==(const Line& l2) const;
};
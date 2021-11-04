
class rand_num
{
private:
    int M_class;        
    int A_class;
    int C_class;
    int num;
public:
    rand_num(int M , int C , int A) {
        int M_class = M;
        int A_class = A;
        int C_class = C;
    }
    ~rand_num();

    int set_seed(int seed) {
        num = seed;
    }

    int get_rnd() {
        num = (A_class * num + C_class) % M_class;
        return num;
    }    

};


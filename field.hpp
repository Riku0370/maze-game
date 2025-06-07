#include<cstdlib>
using namespace std;

class field{
    private:
        int field_side[15][15];
        int x = 1;
        int y = 1;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int randomNumber[4] = {0, 1, 2, 3};
    public:
        void field_zero();
        void field_set();
        void field_dig(int x, int y);
        void print_field();
};

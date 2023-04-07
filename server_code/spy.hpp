class Spy
    {
    private:
        struct position
        {
            int _rowIndex;
            int _colIndex;
        };
        position _pos;
        int hp;

    public:
        enum towards
        {
            toUp,
            toDown,
            toLeft,
            toRight,
        };

        bool move(towards _to)
        {
            if(_to == toUp){
                int temp1 = _pos._rowIndex;
                int temp2 = _pos._colIndex;
                
            }
        }
    };

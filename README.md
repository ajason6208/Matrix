# Matrix
C++ Matrix Class

main.cpp : Simple test program

MATRIX.h : Define 3-d dimension matrix
  
  template <class T>
  class MATRIX {

  private:
    // MATRIX data member 
    int cols_;
    int rows_;
    int depth_;
    T ***p;
      // dynamic allocate space for MATRIX object
    void allocSpace(); 
  public:
    MATRIX(int, int, int);
    MATRIX();
    ~MATRIX();
    MATRIX(const MATRIX&);
    MATRIX& operator=(const MATRIX&);

    inline T& operator()(int x, int y, int z) { return p[x][y][z]; }

    // Overload operator
    MATRIX& operator+=(const MATRIX&);
    MATRIX& operator-=(const MATRIX&);
    MATRIX& operator*=(const MATRIX&);
    MATRIX& operator*=(double);
    MATRIX& operator/=(double);

    // Tool Member Function
    void print_matrix();

    // Get Private Data Member
    int get_cols_() const;
    int get_rows_() const;
    int get_depth_() const;
  };

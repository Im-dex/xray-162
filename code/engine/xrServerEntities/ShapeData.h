#ifndef ShapeDataH
#define ShapeDataH

struct CShapeData {
    enum { cfSphere = 0, cfBox };
    union shape_data {
        Fsphere sphere;
        Fmatrix box;
    };
    struct shape_def {
        u8 type;
        shape_data data;
    };
    using ShapeVec = std::vector<shape_def>;
    ShapeVec shapes;
};

#endif
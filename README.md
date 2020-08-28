## Vector calculation
Library provides Vector2D class for simple Vector calculations like addition, substraction, muliplication and division of Vectors.
Further it provides methods for calculating the length of the vector and normalization.

## Build
Clone repository.

    mkdir build
    cd build

If you want to build examples.

    cmake .. -Dbuild_examples=ON


## Using
Include header ```"vector2d.h"```

create 2D Vector

    vector::Vector2D v(3,4);

create from two vectors

    vector::Vector2D v3 = v1 + v2;

print vector x and y

    std::cout << v.Print() << std::endl;

get vector length

    float length = v.Length();


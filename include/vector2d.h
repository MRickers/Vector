#pragma once
#include <string>

namespace vector {
    class Vector2D {
    public:
        Vector2D(float x, float y);
        Vector2D(const Vector2D& other);
        ~Vector2D(){}


        Vector2D operator=(const Vector2D& other);
        Vector2D operator+(const Vector2D& other);
        Vector2D operator+=(const Vector2D& other);
        Vector2D operator-(const Vector2D& other);
        Vector2D operator-=(const Vector2D& other);
        Vector2D operator*(float scalar);
        Vector2D& operator*=(float scalar);
        Vector2D operator/(float scalar);
        Vector2D& operator/=(float scalar);

        Vector2D GetVec() const;
        float GetX() const;
        float GetY() const;
        void SetX(float x);
        void SetY(float y);
        void Set(const Vector2D& vec);

        std::string Print() const;

        float Magnitude() const;
        void Magnitude(float mag);
        void Normalize();

        void SetLimit(float limit);

    private:
        float m_x;
        float m_y;
    };
}

using Vector = vector::Vector2D;
#include "vector2d.h"
#include <math.h>
#include <stdexcept>

vector::Vector2D::Vector2D() : m_x(0), m_y(0) {}

vector::Vector2D::Vector2D(float x, float y) :
	m_x(x),
	m_y(y){

}

vector::Vector2D::Vector2D(const Vector2D& other){
    m_x = other.m_x;
    m_y = other.m_y;
}

std::string vector::Vector2D::Print() const{
    return std::string("x: "+std::to_string(m_x)+" y: "+std::to_string(m_y));
}

vector::Vector2D vector::Vector2D::operator=(const Vector2D& other) {
    m_x = other.m_x;
    m_y = other.m_y;

    return Vector2D(m_x,m_y);
}

vector::Vector2D vector::Vector2D::operator+(const Vector2D& other) {
	return Vector2D(m_x + other.m_x, m_y + other.m_y);
}

vector::Vector2D vector::Vector2D::operator+=(const Vector2D& other){
    m_x += other.m_x;
    m_y += other.m_y;

    return Vector2D(m_x,m_y);
}

vector::Vector2D vector::Vector2D::operator-(const Vector2D& other) {
	return Vector2D(m_x - other.m_x, m_y - other.m_y);
}

vector::Vector2D vector::Vector2D::operator-=(const Vector2D& other){
    m_x -= other.m_x;
    m_y -= other.m_y;

    return Vector2D(m_x,m_y);
}

vector::Vector2D vector::Vector2D::operator*(float scalar) const {
	return Vector2D(m_x * scalar, m_y * scalar);
}

vector::Vector2D& vector::Vector2D::operator*=(float scalar) {
    m_x *= scalar;
    m_y *= scalar;

    return *this;
}

vector::Vector2D vector::Vector2D::operator/(float scalar) const {
    if(scalar == 0){
        throw std::runtime_error("divided by zero error");
    }
	return Vector2D(m_x / scalar, m_y / scalar);
}

vector::Vector2D& vector::Vector2D::operator/=(float scalar) {
    if(scalar == 0){
        throw std::runtime_error("divided by zero error");
    }
    m_x /= scalar;
    m_y /= scalar;

    return *this;
}

bool vector::Vector2D::operator==(const Vector2D& other) {
    return (m_x == other.m_x && m_y == other.m_y);
}

vector::Vector2D vector::Vector2D::GetVec() const{
    return Vector2D(m_x, m_y);
}

float vector::Vector2D::GetX() const{
    return m_x;
}

float vector::Vector2D::GetY() const{
    return m_y;
}

void vector::Vector2D::SetX(float x){
    m_x = x;
}

void vector::Vector2D::SetY(float y){
    m_y = y;
}

void vector::Vector2D::Set(const Vector2D& vec){
    m_x = vec.m_x;
    m_y = vec.m_y;
}

float vector::Vector2D::Magnitude() const{
    return sqrt(m_x*m_x + m_y * m_y);
}

void vector::Vector2D::Magnitude(float mag) {
    float tmp_x = m_x * mag / Magnitude();
    float tmp_y = m_y * mag / Magnitude();

    m_x = tmp_x;
    m_y = tmp_y;
}

/**
 * @brief Normalize Vector (vector divided by length)
 * 
 */
void vector::Vector2D::Normalize(){
    float length = Magnitude();
    *this /= length;
}

void vector::Vector2D::SetLimit(float limit) {
    if(Magnitude() > limit){
        Magnitude(limit);
    }
}
